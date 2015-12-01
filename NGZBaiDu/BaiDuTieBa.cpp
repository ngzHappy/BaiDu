﻿#include "private/PBaiduTieBa.hpp"
#include "private/GZipCompressor.hpp"
#include "BaiDuTieBa.hpp"
#include <FunctionType.hpp>
#include <CheckArgs.hpp>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkCookieJar>
#include <QScriptEngine>
#include "BaiDuNetworkAccessManager.hpp"
#include <cstddef>
#include <QBuffer>
#include <regex>
#include <QCoreApplication>
#include <QDir>
#include <QDataStream>
#include <QTextCodec>

namespace {

QString operator""_qutf8(const char * d,std::size_t n) {
    return QString::fromUtf8(d,n);
}

}

namespace
{
namespace  baidutieba_
{
const static std::map<int, const char *>  error_code{
    {220001, u8"参数错误"},
    {220008, u8"先发后审"},
    {220009, u8""},
    {220011, u8"贴子标题和内容太长"},
    {220012, u8"this.forbidTpl"},
    {220013, u8R"(操作失败，您的网络地址由于非法操作被封<br/><a href=\"/upc/userinfo?fid=fid\" target="_blank">查看封禁信息</a>)"},
    {220015, u8"请不要发表含有不适当内容的留言<br>请不要发表广告贴"},
    {220034, u8"您说话太快了,) 请先停下来喝杯茶吧，或者可以去别的吧看看哦，一定会发现还有您感兴趣的话题"},
    {220035, u8"亲，已@不少人了，以免打搅更多人，歇一会吧~"},
    {220037, u8"您已尝试提交多次了，请返回后刷新页面，方可重新发贴"},
    {220038, u8"验证码超时，请重新输入"},
    {220040, u8"验证码输入错误，请您返回后重新输入"},
    {220119, u8"对不起，本主题的回复数已经达到上限，感谢您的参与，欢迎您浏览本吧的其它主题"},
    {220901, u8""},
    {224009, u8"贴子已被锁定，无法进行该操作"},
    {224010, u8"您的账号存在安全风险暂不能发贴，请先进行手机绑定后再发贴吧。"},
    {230004, u8"您未登录或已退出登录状态，请先登录再进行操作。"},
    {230008, u8"您的内容已提交成功，正在进行审核，请耐心等待。"},
    {230013, u8"操作失败，您的帐号因违规操作而被封禁"},
    {230020, u8"您发表的贴子的标题或正文包含太少的文字，请修改后再发表"},
    {230044, u8"建吧失败，请重新尝试"},
    {230045, u8"抱歉，您提交的贴吧名称含特殊字符，目前无法创建，推荐您使用汉字、字母或数字作为贴吧名称"},
    {230046, u8"抱歉，您的贴子过长，无法正常提交。建议您精简或分段后重新提交，谢谢!"},
    {230265, u8"您未登录或已退出登录状态，请先登录再进行操作。"},
    {230273, u8"操作失败，该帖子已不存在"},
    {230308, u8"抱歉，您没有权限进行该项操作。"},
    {230705, u8"本吧当前只能浏览，不能发贴！"},
    {230808, u8"抱歉，每层楼插入的视频不能超过1个，请修改后重新提交"},
    {230809, u8"抱歉，每层楼插入的图片不能超过10张，请修改后重新提交"},
    {230814, u8"抱歉，每层楼插入的表情不能超过10张，请修改后重新提交"},
    {230815, u8"抱歉，每层楼插入的音乐不能超过10个，请修改后重新提交"},
    {230850, u8"吧名已存在，请勿重复创建"},
    {230870, u8"本帖子回复较多，不支持删除"},
    {230871, u8"发贴太频繁，停下来喝杯茶休息下吧"},
    {230887, u8"发表失败了，请重新尝试"},
    {230889, u8"您已被加入小黑屋，无法进行该操作。"},
    {230900, u8"为抵御挖坟危害，本吧吧主已放出贴吧神兽--超级静止蛙，本贴暂时无法回复。"},
    {230901, u8"该楼回复已达上限，请到别的楼层参与互动吧"},
    {230902, u8"您输入的内容过长，请修改后重新提交。"},
    {230903, u8"您输入的内容不合法，请修改后重新提交。"},
    {230961, u8"发贴失败，您输入的图片地址有错误，请检查更正后再次发布：）"},
    {230962, u8"您输入的内容不合法，请修改后重新提交。"},
    {230963, u8"您输入的内容不合法，请修改后重新提交。"},
    {231120, u8"抱歉，您输入的图片、视频链接地址错误，您可以点击<a href=\"http,//www.baidu.com/search/post_img.html\" target=\"_blank\">查看相关帮助</a>或返回修改"},
    {232000, u8"您输入的内容不合法，请修改后重新提交。"},
    {232001, u8"您输入的内容不合法，请修改后重新提交。"},
    {232007, u8"您输入的内容不合法，请修改后重新提交。"},
    {232101, u8"您输入的内容不合法，请修改后重新提交。"},
    {233001, u8"发表失败了，请重新再试。"},
    {233003, u8"发表失败了，请重新再试。"},
    {233004, u8"发表失败了，请重新再试。"},
    {233005, u8"发表失败了，请重新再试。"},
    {233006, u8"发表失败了，请重新再试。"},
    {233007, u8"发表失败了，请重新再试。"},
    {233010, u8"本吧仅允许官方粉丝团成员回复哦，赶快加入吧！"},
    {220903, u8"线路升级改造，暂时无法发贴，请耐心等待，给您带来不便表示抱歉~"},
    {234031, u8"上传文件失败，请重新上传。"},
    {235004, u8"使用道具错误，该道具要购买后才能使用。"},
    {235005, u8"无权限使用该道具，请去购买。"},
    {236001, u8"该贴为贴吧手机App直播贴，目前暂时不支持非楼主之外的用户占楼，但你可以在楼中楼回复哦！"},
    {239000, u8"您还没有用户名，不能在本吧发贴。请先填写用户名。"},
    {239001, u8"由于匿名状态或本吧设置，无法发表带有图片的主题。"},
    {2270028, u8"附加奖品的额度不能少于10000T豆"},
    {2270029, u8"主题发送成功，奖励添加失败"},
    {2270018, u8"抱歉，您没有权限发奖励贴"},
    {2270027, u8"感言请控制在140个字之内"},
    {10, u8"贴子内容包含太少的文字"},
    {11, u8"贴子标题和内容太长"},
    {12, u8"this.forbidTpl"},
    {13, u8R"(操作失败，您的网络地址由于非法操作被封<br/><a href=\"/upc/userinfo?fid=fid\" target="_blank">查看封禁信息</a>)"},
    {14, u8"您发布的贴子已经存在"},
    {15, u8"请不要发表含有不适当内容的留言<br>请不要发表广告贴"},
    {501,u8"请不要发表含有不适当内容的留言<br>请不要发表广告贴"},
    {16, u8"对不起，您所输入的贴吧不存在。由于系统升级维护，新建贴吧功能暂停，希望得到您的谅解！"},
    {17, u8"本吧当前只能浏览，不能发贴！"},
    {19, u8"您的用户名或者密码填写有误，请确认后再发表"},
    {200, u8"您的用户名或者密码填写有误，请确认后再发表"},
    {201, u8"您的用户名或者密码填写有误，请确认后再发表"},
    {202, u8"您的用户名或者密码填写有误，请确认后再发表"},
    {20, u8"您发表的贴子的标题或正文包含太少的文字，请修改后再发表"},
    {22, u8"您发表的贴子已经成功提交，由于特殊原因我们需要核实该贴内容是否含有不良信息，我们会在10分钟内确认，请您耐心等待！"},
    {23, u8"您的贴子已经成功提交，但需要系统审核通过后才能建立贴吧"},
    {33, u8"您发贴太快了,) 请稍后再发"},
    {34, u8"您说话太快了,) 请先停下来喝杯茶吧，或者可以去别的吧看看哦，一定会发现还有您感兴趣的话题"},
    {35, u8"亲，已@不少人了，以免打搅更多人，歇一会吧~"},
    {36, u8"请不要发广告贴！"},
    {37, u8"您已尝试提交多次了，请返回后刷新页面，方可重新发贴"},
    {38, u8"验证码超时，请重新输入"},
    {39, u8"由于您多次输错验证码，请您返回后刷新页面，方可重新发贴"},
    {40, u8"验证码输入错误，请您返回后重新输入"},
    {41, u8"您的贴子可能包含不合适的内容，请您确定后再提交"},
    {42, u8"您的发贴行为被系统认为有发广告嫌疑，请您稍后再发"},
    {43, u8"您的发贴行为或贴子内容有广告或不合适的特征，请您确定后再发送"},
    {44, u8"对不起，本吧暂时限制部分用户发表主题贴子，您可以浏览或回复本吧其它内容，给您带来不便希望得到您的谅解。"},
    {119, u8"对不起，本主题的回复数已经达到上限，感谢您的参与，欢迎您浏览本吧的其它主题"},
    {1120, u8"抱歉，您输入的图片、视频链接地址错误，您可以点击<a href=\"http,//www.baidu.com/search/post_img.html\" target=\"_blank\">查看相关帮助</a>或返回修改"},
    {1121, u8"抱歉，视频服务升级中，您暂时无法发表带有视频的贴子，给您带来的不便请原谅"},
    {100, u8"对不起，本吧暂时限制部分用户使用完整的贴吧功能，您可以浏览本吧其它内容，给您带来不便希望得到您的谅解。"},
    {701, u8"为了减少恶意灌水和广告帖，本吧不允许未登录用户发贴，登录用户不受影响，给您带来的不便深表歉意"},
    {702, u8"为了减少恶意灌水和广告帖，本吧限制部分用户发贴，给您带来的不便深表歉意"},
    {703, u8"为了减少恶意灌水和广告帖，本吧被设置为仅本吧会员才能发贴，给您带来的不便深表歉意。<a href=\"/f?kw=this.bdQueryWordEnc#1\" target=_blank>点此申请加入</a>本吧会员"},
    {704, u8"为了减少恶意灌水和广告帖，本吧被设置为仅本吧管理团队才能发贴，给您带来的不便深表歉意"},
    {705, u8"本吧当前只能浏览，不能发贴！"},
    {706, u8"抱歉，本贴暂时无法回复。"},
    {45, u8"抱歉，您提交的贴吧名称含特殊字符，目前无法创建，推荐您使用汉字、字母或数字作为贴吧名称"},
    {46, u8"抱歉，您的贴子过长，无法正常提交。建议您精简或分段后重新提交，谢谢!"},
    {815, u8"抱歉，您已退出登录或未购买音乐道具，请刷新页面重试"},
    {900, u8"为抵御挖坟危害，本吧吧主已放出贴吧神兽--超级静止蛙，本贴暂时无法回复。"},
    {961, u8"发贴失败，您输入的图片地址有错误，请检查更正后再次发布：）"},
    {9001, u8"由于匿名状态或本吧设置，无法发表带有图片的主题。"},
    {2100, u8"内容含有高级字体效果，保持连续签到就能使用哦~~"},
    {4010, u8"您的账号存在安全风险暂不能发贴，请先进行手机绑定后再发贴吧。"},
    {9000, u8"您还没有用户名，不能在本吧发贴。请先填写用户名。"},
    {402011,u8"图片宽度超出限制"},
    {402012, u8"图片高度超出限制"},
    {402013, u8"图片标签无效"},
    {220900, u8"禁止挖坟"},

};
}//namespace
}//namespace

namespace {
class ArgError {
    QString what_;
public:
    ArgError() {}
    ArgError(decltype(nullptr)) {}
    ArgError(const char * d):what_(QString::fromUtf8(d)) {}
    ArgError(const QString & v):what_(v) {}
    const QString & what()const { return what_; }
};
}

BaiDuTieBa::BaiDuTieBa(QObject *parent) :
    QObject(parent){

    /*create thisp*/
    thisp = cct::make_unique_shared_ptr< BaiDuTieBaPrivate >();
    thisp->thisp = thisp;

    /*connect signals ans slot*/

}

std::shared_ptr<BaiDuUser> BaiDuTieBa::getBaiDuUser()const {
    return thisp->baiDuUser;
}

void BaiDuTieBa::setBaiDuUser(std::shared_ptr<BaiDuUser> u) {
    if (u) { if ( u->isLogin() ) { 
        thisp->baiDuUser=u; 
        //设置 tieba cookie
        if (u->getCookies()->find("TIEBAUID") == u->getCookies()->end()) {
            QNetworkRequest req( QUrl{ "http://tieba.baidu.com/f?ie=utf-8&kw=%E9%B2%9C%E4%B8%BA%E4%BA%BA%E7%9F%A5&fr=search" } )  ;
            req.setRawHeader("User-Agent", u->getUserAgent().first );
            req.setHeader(QNetworkRequest::CookieHeader, u->getAllCookies() );
            auto m = u->getManager();
            auto r = m->get( req );

            std::shared_ptr< QNetworkReply > r_(r );
            std::weak_ptr< QNetworkReply >  wr(r_);
            std::weak_ptr< BaiDuNetworkAccessManager > wm(m);
            std::weak_ptr< BaiDuUser > wu( u );
            m->addReply(r_);

            connect( r,&QNetworkReply::finished,
                this,[ wm,wr,wu ]() {
                try {
                    auto m=wm.lock();auto r=wr.lock();
                    cct::check_args< ArgError>(m,"",r,"");
                    m->removeReply(r);
                    auto u=wu.lock();cct::check_args< ArgError>(u,"");
                    auto rdata=r->rawHeaderPairs();
                    auto c=u->getCookies();cct::check_args< ArgError>(c,"");
                    auto & allCookies = * u->getCookies() ;
                    for (const auto & i : rdata ) {
                        if (i.first == "Set-Cookie") {
                            const auto ak_ = QNetworkCookie::parseCookies(i.second);
                            for (const auto & j : ak_) {
                                //qDebug()<<j.name();
                                allCookies[ j.name()] =j  ;
                            }
                        }
                    }

                }
                catch (const ArgError &  ) { }
            }
                );

        }

    } }
    else { 
        thisp->baiDuUser.reset();
    }
}

BaiDuTieBa::~BaiDuTieBa(){

    if (thisp) {
        disconnect(this,nullptr,thisp.get(),nullptr);
        disconnect(thisp.get(),nullptr,this,nullptr);
        thisp.reset();
    }

}


BaiDuTieBaPrivate::BaiDuTieBaPrivate(){

}

BaiDuTieBaPrivate::~BaiDuTieBaPrivate(){

}

SendTieBaDataPack::SendTieBaDataPack() {
}

SendTieBaDataPack::~SendTieBaDataPack() {
}

//static
#define _zfunc cct::FunctionType< decltype( &BaiDuTieBa::mouse_pwd ) >
void BaiDuTieBa::mouse_pwd(_zfunc::_0 now,_zfunc::_1 fun,_zfunc::_2 fp) try{
    cct::check_args<ArgError>( !now.isEmpty(),"null timer",fun ,"callbakc is null");
    const QByteArray static ans="118%2C113%2C114%2C104%2C113%2C119%2C119%2C116%2C77%2C117%2C104%2C116%2C104%2C117%2C104%2C116%2C104%2C117%2C104%2C116%2C104%2C117%2C104%2C116%2C104%2C117%2C104%2C116%2C77%2C119%2C117%2C124%2C119%2C114%2C77%2C117%2C114%2C124%2C116%2C104%2C117%2C116%2C113%2C116%2C";
    fun( ans+now+"0" , std::move( fp ) );
}
catch (const ArgError & e) {if (fp) { fp->finished(false,e.what()+" "+__func__ ); }}
#undef _zfunc

//static
//http://tieba.baidu.com/dc/common/imgtbs
#define _zfunc cct::FunctionType< decltype( &BaiDuTieBa::imgtbs ) >
void BaiDuTieBa::imgtbs(
    _zfunc::_0 u_,
    _zfunc::_1 fun,
    _zfunc::_2 fp)try{
    cct::check_args<ArgError>( u_,"null user",
        fun ,"callbakc is null",
        u_->isLogin(),"user is not login"
        );

    auto manager_ = u_->getManager();
    cct::check_args<ArgError>( manager_,"network manager is null" );
    QNetworkRequest req(QUrl("http://tieba.baidu.com/dc/common/imgtbs"));
    req.setRawHeader("User-Agent", u_->getUserAgent().first );
    req.setHeader(QNetworkRequest::CookieHeader, u_->getAllCookies() );

    auto * r_ = manager_->get( req );
    std::shared_ptr<QNetworkReply> rpl(r_,
        [](QNetworkReply * d) { d->deleteLater(); });

    manager_->addReply( rpl );
    std::weak_ptr<QNetworkReply> rp_(rpl);
    std::weak_ptr<BaiDuNetworkAccessManager> mn_( manager_ );
    rpl->connect( rpl.get(),&QNetworkReply::finished,
        [ fun , rp_ ,fp , mn_ ](  ) {
        try {
            auto rp=rp_.lock(); auto mn=mn_.lock();
            cct::check_args<ArgError>(rp,"endl ... ",mn,"endl .... ");
            mn->removeReply(rp);
            auto ans=rp->readAll();auto a1=ans.split('\"');
            for (const auto &a:a1) {
                if (a.size()>10) { return fun(a,fp);}
            }
            if (fp) { fp->finished(false,"null reply ... " +QString(__func__) ); }
        }
        catch ( const ArgError & e) {
            if (fp) { fp->finished(false,e.what()); }
        }
    });

}catch (const ArgError & e) {if (fp) { fp->finished(false,e.what()+" "+__func__ ); }}
#undef _zfunc

//static
#define _zfunc cct::FunctionType< decltype( &BaiDuTieBa::tbs ) >
void BaiDuTieBa::tbs(
    _zfunc::_0 u_   ,
    _zfunc::_1 fun  ,
    _zfunc::_2 fp   )try{
    cct::check_args<ArgError>( u_,"null user",
        fun ,"callbakc is null",
        u_->isLogin(),"user is not login"
        );

    auto manager_ = u_->getManager();
    cct::check_args<ArgError>( manager_,"network manager is null" );
    QNetworkRequest req(QUrl("http://tieba.baidu.com/dc/common/tbs"));
    req.setRawHeader("User-Agent", u_->getUserAgent().first );
    req.setHeader(QNetworkRequest::CookieHeader, u_->getAllCookies() );

    auto * r_ = manager_->get( req );
    std::shared_ptr<QNetworkReply> rpl(r_,
        [](QNetworkReply * d) { d->deleteLater(); });

    manager_->addReply( rpl );
    std::weak_ptr<QNetworkReply> rp_(rpl);
    std::weak_ptr<BaiDuNetworkAccessManager> mn_( manager_ );
    rpl->connect( rpl.get(),&QNetworkReply::finished,
        [ fun , rp_ ,fp , mn_ ](  ) {
        try {
            auto rp=rp_.lock(); auto mn=mn_.lock();
            cct::check_args<ArgError>(rp,"endl ... ",mn,"endl .... ");
            mn->removeReply(rp);
            auto ans=rp->readAll();auto a1=ans.split('\"');
            for (const auto &a:a1) {
                if (a.size()>10) { return fun(a,fp);}
            }
            if (fp) { fp->finished(false,"null reply ... " +QString(__func__) ); }
        }
        catch ( const ArgError & e) {
            if (fp) { fp->finished(false,e.what()); }
        }
    });

}catch (const ArgError & e) {if (fp) { fp->finished(false,e.what()+" "+__func__ ); }}
#undef _zfunc

void SendTieBaDataPack::finished(bool v,QString) {
    isValueSet=true;
    hasError=!v;

}

namespace
{
QByteArray get_rand_name() {
    constexpr const static char table_[]{
        '0','1','2','3','X','Y','Z','W',
        '4','5','6','7','T','N','V','Q',
        '8','9','a','b','K','M','O','R',
        'c','d','e','f','J','L','I','U',
    };

    enum {table_size_ = (sizeof(table_)/sizeof(char)) };

    QByteArray ans("IMAGE_");
    ans.reserve(32);
    const auto n=(rand()&7)+1;
    for (int i=0; i<n;++i) {
        ans.push_back( table_[((rand())%table_size_ )] );
        ans.push_back("_");
    }
    return ans+".jpg";
}
}

#define _zfunc cct::FunctionType< decltype( &BaiDuTieBa::image2html ) >
void BaiDuTieBa::image2html(
    _zfunc::_r3 fid_  ,
    _zfunc::_r2 image_,
    _zfunc::_r1 fun   ,
    _zfunc::_r0 fp    ) try{

    cct::check_args<ArgError>(
        !fid_.isEmpty(),"fid is null",
        !image_.isNull(),"image is null",
        fun,"callback is null",
        thisp,"this is null",
        thisp->baiDuUser,"user is null",
        thisp->baiDuUser->isLogin(),"user is not login"
        );

    auto u=thisp->baiDuUser;
    /*设置百度贴吧图像最大宽度为360*/
    enum { MaxImageWidth = 360 };
    if (image_.width() > MaxImageWidth ) {
        double image_width=MaxImageWidth;
        double image_height=image_.height()/double(image_.width())*image_width;
        typedef std::int32_t int32_type;
        image_ = image_.scaled(MaxImageWidth,int32_type(0.6666+image_height),
            Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    }

    /*重新压缩图片至jpeg*/
    QByteArray imageData;
    {
        QBuffer buffer(&imageData);buffer.open( QIODevice::WriteOnly );
        image_.save( &buffer ,"jpeg" );
    }

    cct::check_args<ArgError>( !imageData.isEmpty(),"jpeg image data is null ." );

    {image_=QImage();/*clear image*/ }

    std::weak_ptr<BaiDuTieBaPrivate> wthisp(thisp);
    imgtbs(u,[u,fid_,fun,imageData,wthisp](QByteArray itbs_,_zfunc::_r0 fp) {
        try {
            auto thisp=wthisp.lock();
            cct::check_args<ArgError>(thisp,"endl ");
            QByteArray per__(u8R"(---------------------------7df2b05f091c)");

            //设置数据
            //begin;
            QByteArray post_before(   "--"+per__+"\r\n"  );
            QByteArray post_after( "\r\n--"  + per__ + "--" "\r\n"   );
            QByteArray postData;

            //设置数据
            {//保存成jpg 不支持动态图片
                postData+="Content-Disposition: form-data; name=\"file\"; filename=\""
                    + get_rand_name() +
                    "\"" "\r\n" ;
                postData+="Content-Type: image/jpg"  "\r\n" "\r\n" ;
                postData+=imageData; 
            }

            for(;;){
                std::regex reg(per__.constData() ,per__.size() );
                if( std::regex_search( postData.cbegin(),postData.cend(),reg )==false ){
                    postData= post_before+postData+post_after;
                    break ;
                }
                per__=QByteArray("---------------------------7d");
                for(int i=0;i<10;++i){
                    constexpr const static char table_[]{
                        '0','1','2','3',
                        '4','5','6','7',
                        '8','9','a','b',
                        'c','d','e','f',
                    };
                    per__.append( table_[(std::rand()) & ((sizeof(table_)/sizeof(char))-1) ] );
                }
                post_before = QByteArray( "--" +per__ +"\r\n"  );
                post_after  = QByteArray( "\r\n" "--"  + per__ + "--" "\r\n"   );
            }
            //endl

            QByteArray url_("http://upload.tieba.baidu.com/upload/pic");
            url_.append( QByteArray("?tbs=") + itbs_ );
            url_.append( "&fid=" + fid_ );
            url_.append( "&save_yun_album=1" );

            QUrl url__(url_);
            QNetworkRequest req( url__ );
            req.setRawHeader("Accept","*/*");
            req.setRawHeader("Host","upload.tieba.baidu.com");
            req.setRawHeader("User-Agent", u->getUserAgent().first );
            req.setRawHeader("Accept-Encoding","gzip, deflate");
            req.setRawHeader("Accept-Language","zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3");
            //req.setRawHeader("Referer","http://tieba.baidu.com");
            req.setRawHeader("Content-Type", u8R"(multipart/form-data; boundary=)"+per__);
            req.setRawHeader("Origin","http://tieba.baidu.com");
            req.setRawHeader("Connection","keep-alive");
            req.setRawHeader("Pragma", "no-cache");
            req.setRawHeader("Cache-Control", "no-cache");

            req.setHeader(QNetworkRequest::CookieHeader,u->getAllCookies() );
            auto m=u->getManager();
            cct::check_args<ArgError>(m,"endl ");
            auto * r = m->post( req,postData );

            std::shared_ptr< QNetworkReply > rpl(r,[](QNetworkReply * d) {d->deleteLater(); });
            m->addReply( rpl );std::weak_ptr< QNetworkReply> wrp(rpl);
            std::weak_ptr< BaiDuNetworkAccessManager > wm( m );

            r->connect(r,&QNetworkReply::finished, 
                [fun,fp,wrp,wm]() {
                try {
                    auto m=wm.lock();auto r=wrp.lock();
                    cct::check_args<ArgError>(m,"endl ",r,"endl");m->removeReply(r);
                    QByteArray all_data=r->readAll();
                    all_data = gzip::QCompressor::gzipDecompress( all_data );
                    cct::check_args<ArgError>(!all_data.isEmpty(),"post image error!!");
                    QScriptEngine eng;
                    auto evans_ = eng.evaluate("iurl = "+all_data);
                    cct::check_args<ArgError>(!evans_.isError() ,"post image error!!!");
                    evans_=eng.evaluate(u8R"(iurl["info"]["pic_id_encode"])");
                    cct::check_args<ArgError>(!evans_.isError() , "post image error!!!!"
                        +QString( all_data )
                        );
                    auto ii=TieBaTextImageType( nullptr );
                    ii.width = eng.evaluate(u8R"(iurl["info"]["fullpic_width"])").toString();
                    ii.height = eng.evaluate(u8R"(iurl["info"]["fullpic_height"])").toString();
                    ii.type = eng.evaluate(u8R"(iurl["info"]["pic_type"])").toString();
                    ii="http://imgsrc.baidu.com/forum/pic/item/"+evans_.toString()+".jpg";
                    fun( ii,fp );

                }
                catch (const ArgError & e) {
                    if (fp) { fp->finished(false,e.what()+" "+__func__); }
                }
            });

        }
        catch (const ArgError & e) {
            if (fp) { fp->finished(false,e.what()+" "+__func__); }
        }
    },fp);

}
catch (const ArgError & e) {
    if (fp) { fp->finished(false,e.what()+" "+ QString(__func__)); }
}
#undef _zfunc

void BaiDuTieBa::images2html(
    QByteArray        fid_   ,
    QList<QString>    images_names_,
    QList<QImage>     images_,
    std::function<void(cct::List<TieBaTextImageType>,BaiDuFinishedCallBackPointer)> fun ,
    BaiDuFinishedCallBackPointer fp ) try{
    
    cct::check_args<ArgError>( !fid_.isEmpty(),"fid is emperty",
        !images_.isEmpty(),"images is null",
        (images_names_.size() == images_.size()),"???",
        fun,"callback is null"
        );

    auto all_size_=images_.size();
    cct::check_args<ArgError>(all_size_<11,"images is too large");

    /*所有图片上传完成回调函数*/
    class FinishedPack :
        public BaiDuFinishedCallBack  {
    public:
        FinishedPack() {}
        ~FinishedPack() {
            
            if (error_call_back) { if (image_count != int(ans_data->size()) ) {
                error_call_back->finished(false,"some picture post error!");
            } }

            if ( ans_data->empty()==false ) {
                if (call_back) {
                    call_back( ans_data, error_call_back);
                }
            }

        }
        void finished(bool v, QString) override { hasError=!v; }
        int image_count;
        cct::List<TieBaTextImageType> ans_data;
        BaiDuFinishedCallBackPointer error_call_back;
        std::function<void(cct::List<TieBaTextImageType>,BaiDuFinishedCallBackPointer)> call_back;
    };

    auto pack_=std::make_shared<FinishedPack>();
    pack_->image_count=all_size_;
    pack_->error_call_back=fp;
    pack_->call_back=fun;
    
    auto ib = images_names_.cbegin();
    for (const auto & i:images_) {
        QString image_local_name__ = *ib;
        image2html(fid_,i,[pack_,image_local_name__ ](TieBaTextImageType item, BaiDuFinishedCallBackPointer ) mutable {
            item.localPath=std::shared_ptr<QString>( new QString(image_local_name__) );
            pack_->ans_data->push_back( item );
        },
            pack_ );
        ++ib;
    }

}
catch (const ArgError & e) {
    if (fp) { fp->finished(false,e.what()+ " " +__func__); }
}

void BaiDuTieBa::localTieBa2BaiDuTieBa(
    QByteArray /*fid*/ fid_,
    QString dir_,
    std::shared_ptr<TieBaFormatData> ldata_,
    std::function<void(std::shared_ptr<TieBaFormatData>,BaiDuFinishedCallBackPointer)> fun,
    BaiDuFinishedCallBackPointer fp) try{

    cct::check_args<ArgError>( 
        fun,"callback is null",
        ldata_,"data is null",
        !( ldata_->empty() ),"data is null."
        );
    
    QList<QString > about_to_post_names_;
    QList<QImage> about_post_images_;
    for ( auto & j:*ldata_ ) {
        if (j.isImage) {
            if (j.startsWith("http://")) { continue; }
            about_post_images_.push_back( QImage(dir_+"/"+QString(j)));
            about_to_post_names_.push_back(j);
        }
    }

    if ( about_to_post_names_.empty() ) {
        return fun(ldata_,fp);
    }

    std::shared_ptr<TieBaFormatData> ans=TieBaFormatData::instance() ;
    *ans=*ldata_;//copy data

    images2html(
        fid_,
        about_to_post_names_,
        about_post_images_,
        [ans,fun](
        cct::List<TieBaTextImageType> html_images_,
        BaiDuFinishedCallBackPointer  fp
        ) mutable {

        if (bool(html_images_)==false) {if (fp) { fp->finished(false,"?!?@?"); }return;}

        auto & m = ans->localPath2HtmlPath ;
        for (const auto & i: *html_images_) {
            if (i.localPath) {
                m[ *(i.localPath) ] = i;
            }
        }
        html_images_->clear();

        for ( auto & i:(*ans) ) {
            if (i.isImage) {
                if (i.startsWith("http://")) { continue; }
                auto ip_ = m.find( i );
                if (ip_ != m.end()) {i=ip_->second;}
            }
        }

        m.clear();

        fun( ans,fp );

    },fp);

}catch (const ArgError & e) {
    if (fp) { fp->finished(false,e.what()+ " " +__func__); }
}

namespace {
namespace BaiDuTieBa__{
/*操作系统回收资源*/
std::recursive_mutex * mutex = nullptr ;
/*操作系统回收资源*/
std::map<QString,QByteArray> * fidMap = nullptr  ;

void read() {
    auto dir_ = QCoreApplication::applicationDirPath();
    {
        QDir dir(dir_);
        dir.mkdir(dir_+"/data");
        dir.mkdir(dir_+"/data/tid");
    }

    QString fileName(dir_+"/data/tid/tid.txt");
    QFile file( fileName);

    if (file.exists()) {
        file.open(QIODevice::ReadOnly);
        QDataStream stream(&file);
        stream.setVersion(QDataStream::Version::Qt_5_5);
        QString key; QByteArray value;
        auto & fid=*fidMap;
        while (stream.atEnd()==false) {
            stream>>key;
            stream>>value;
            fid[key]=value;
        }
    }
    else {
        file.open(QIODevice::WriteOnly);
    }

}//read
 
void write() {
    auto dir_ = QCoreApplication::applicationDirPath();
    QString fileName(dir_+"/data/tid/tid.txt");
    QFile file( fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream stream(&file);
        stream.setVersion(QDataStream::Version::Qt_5_5);
        auto & fid= *fidMap ;
        for (const auto & i: fid ) {
            stream<<i.first;
            stream<<i.second;
        }

    }

}//write

void inster(QString k,QByteArray v) {
    std::unique_lock<std::recursive_mutex> _(*mutex);
    auto & fid=*fidMap;
    fid[k.toLower()]=v;
}

QByteArray find( QString name_ ){
    std::unique_lock<std::recursive_mutex> _(*mutex);
    auto & fid = *fidMap;
    auto pos_ = fid.find( name_.toLower() );
    if (pos_!=fid.end()) { return pos_->second; }
    return QByteArray();
}


class Locker {
public:
    Locker() {
        if (mutex) { return; }
        mutex=new std::recursive_mutex;
        std::unique_lock<std::recursive_mutex> _(*mutex);
        fidMap=new std::map<QString,QByteArray>;
        auto & fid=*fidMap;
        /*先将包含特殊符号的贴吧存储*/
        fid.insert({u8"C++"_qutf8,"20975"});
        fid.insert({u8"c++"_qutf8,"20975"});
        fid.insert({u8"c#"_qutf8,"20998"});
        fid.insert({u8"C#"_qutf8,"20998"});
        /*读入以前访问过的贴吧*/
        read();
    }
    ~Locker() {
        /*析构就不必加锁了*/
        /*保存访问过的贴吧*/
        write();
    }
};

}
}

void BaiDuTieBa::fid(
    std::shared_ptr< BaiDuUser > u,
    QString /*贴吧名字*/ tbname ,
    std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> fun,
    BaiDuFinishedCallBackPointer fp) try{
    static BaiDuTieBa__::Locker __locker__;
    tbname=tbname.trimmed();
    
    cct::check_args<ArgError>(fun,"callback is null");
    auto ans = BaiDuTieBa__::find( tbname );

    if (ans.isEmpty()==false) { return fun(ans,fp); }

    cct::check_args<ArgError>(u,"user is null");
    auto m = u->getManager();
    cct::check_args<ArgError>(m,"manager is null");

    //http://tieba.baidu.com/f?kw=%E7%BE%8E%E5%89%A7&ie=utf-8
    QByteArray url_="http://tieba.baidu.com/f?kw="
        +tbname.toUtf8().toPercentEncoding()
        +"&ie=utf-8";
    QUrl url(url_);
    QNetworkRequest req(url);

    req.setRawHeader("User-Agent", u->getUserAgent().first );
    req.setRawHeader("Accept-Encoding", "gzip, deflate");
    req.setRawHeader("Connection", "keep-alive");
    req.setRawHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");

    auto * r=m->get( req );
    std::shared_ptr< QNetworkReply > rp(r,[](QNetworkReply * d) {d->deleteLater(); });
    std::weak_ptr< QNetworkReply > wr( rp );
    std::weak_ptr< BaiDuNetworkAccessManager > wm(m);
    m->addReply(rp);

    r->connect(r,&QNetworkReply::finished,
        [tbname,wr,wm,fun,fp]() {
        auto r=wr.lock();
        auto m=wm.lock();
        try {
            cct::check_args<ArgError>(r,"",m,"");
            m->removeReply(r);
            QByteArray ans=r->readAll();
            ans=gzip::QCompressor::gzipDecompress(ans);
            cct::check_args<ArgError>(!ans.isEmpty(),"can not find tieba ");

            const char * begin=ans.constBegin();
            const char * end=ans.constEnd();

            std::cmatch match;
            if (std::regex_search(begin, end, match, std::regex("PageData.forum"))) {
                begin=match[0].second;
                if (std::regex_search(begin, end, match, std::regex(R"('id':)"))) {
                    begin=match[0].second;
                    QString ans;
                    for (; begin!=end; ++begin) {
                        if ((*begin>='0')&&(*begin<='9')) {
                            break;
                        }
                    }
                    for (; begin!=end; ++begin) {
                        if ((*begin>='0')&&(*begin<='9')) {
                            ans.push_back(*begin);
                            continue;
                        }break;
                    }

                    BaiDuTieBa__::inster( tbname, ans.trimmed().toUtf8()  );
                    fun(ans.trimmed().toUtf8(),fp);
                }
                else {
                    throw ArgError("id:");
                }
            }
            else {
                throw ArgError("PageData.forum");
            }

        }
        catch (const ArgError & e) {
            if (fp) { fp->finished(false,e.what()+ " " +__func__); }
        }
    });

}catch (const ArgError & e) {
    if (fp) { fp->finished(false,e.what()+ " " +__func__); }
}

/*
 * endl of the file
*/
