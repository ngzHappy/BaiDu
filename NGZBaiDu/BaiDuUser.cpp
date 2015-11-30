#include "private/PBaiDuUser.hpp"
#include "private/GZipCompressor.hpp"
#include "BaiDuUser.hpp"
#include <QDateTime>
#include <QUrl>
#include <QNetworkCookieJar>
#include <QScriptEngine>
#include <ObjectDelete.hpp>
#include <cstddef>
#include <cstdint>
#include <QtCrypto>
#include <iostream>
#include <sstream>

namespace {

QString operator""_qutf8(const char * d,std::size_t n) {
    return QString::fromUtf8(d,n);
}

}

BaiDuUserLoginNetworkAccessManager::BaiDuUserLoginNetworkAccessManager(QObject * o)
    :QNetworkAccessManager(o) {}

BaiDuUser::BaiDuUserPrivate::BaiDuUserPrivate(std::shared_ptr<BaiDuUserPrivate> o):
    thisPointer(o) {
    this->__all__bits__=char(0);
    manager=std::make_shared<BaiDuUserLoginNetworkAccessManager>(nullptr);
}

BaiDuUserLoginPack::BaiDuUserLoginPack(QObject * o)
    :QObject(o) {
}

BaiDuUserLoginPack::~BaiDuUserLoginPack() {
    
    if (isValueSet) { return; }
    else {
        emit loginFinished(false,"endl : "+QString(__func__));
    }
}

BaiDuUser::BaiDuUserPrivate::~BaiDuUserPrivate() {

    isOnDestory.store(true);
    {
        //clear all temp objects
        std::unique_lock< std::recursive_mutex > __(this->tempObjectsMutex);
        tempObjects=nullptr;
    }

    manager=nullptr;
}

void BaiDuUser::BaiDuUserPrivate::setLogInPackData(BaiDuUserLoginPack * p) {

    p->baiduUserPrivate=thisPointer;
    p->userName=p->userNameBase.toUtf8().toPercentEncoding();
}

void BaiDuUserLoginPack::finished(bool v,QString r) {
    if (isValueSet) { return; }
    isValueSet=true;
    //TODO : log in finished
    hasError=!v;
    emit loginFinished(v,r);
    //just call once
    
}

void BaiDuUser::BaiDuUserPrivate::connectLoginPack(BaiDuUserLoginPack * p) {

    connect(p,&BaiDuUserLoginPack::loginFinished,this,&BaiDuUser::BaiDuUserPrivate::loginFinished);
}

void BaiDuUser::BaiDuUserPrivate::upDateGID(BaiDuFinishedCallBackPointer fp) {

    auto & gid__=this->gid;
    BaiDuUser::gid([&gid__](auto ans,auto) { gid__=ans; },fp);
}

void BaiDuUser::BaiDuUserPrivate::login(
    QString userName,
    QString passWord,
    BaiDuVertifyCode vertifyCode_
    ) {

    auto * loginPack=new BaiDuUserLoginPack(this);
    BaiDuUserLoginPackPointer pack(loginPack);

    //设置基本数据
    loginPack->userNameBase=userName;
    loginPack->passWordBase=passWord;

    //连接信号槽
    connectLoginPack(loginPack);

    //进行状态检查
    if (this->isLogIn) {//对象已经登录则退出
        loginPack->finished(false,QString("the ")+"user"+" has login!!");
        return;
    }

    if (this->isLogInIng) {//对象正在登录则退出
        loginPack->finished(false,QString("the ")+"user"+" is logining!!");
        return;
    }

    //进一步设置数据
    loginPack->vertifyCode=vertifyCode_;
    setLogInPackData(loginPack);

    //更新gid
    upDateGID(pack);
    if (pack->hasError) { return; }

    typedef BaiDuFinishedCallBackPointer BCP_;
    auto thisp = thisPointer;
    //TODO : login
//获得baidu cookie
    getBaiduCookie([thisp,pack](
        cct::Map<QByteArray,QNetworkCookie> cookies,
        BCP_ errorFunction) mutable {
        auto thisPointer=thisp.lock();
        if (bool(thisPointer)==false) { if (errorFunction) { errorFunction->finished(false,"endl"); }return; }
           
        thisPointer->cookies=cookies;
                
        //获得baidu token
        thisPointer->getBaiduToken([thisp ,pack](
            QByteArray token_,
            BCP_ errorFunction) mutable {
            auto thisPointer=thisp.lock();
            if (bool(thisPointer)==false) { if (errorFunction) { errorFunction->finished(false,"endl"); }return; }
            thisPointer->token=token_;

            //获得rsa key
            thisPointer->getRSAKey(
                [thisp,pack](
                QByteArray rsa_key_,
                QByteArray public_key_,
                BCP_ errorFunction) {
                auto thisPointer=thisp.lock();
                if (bool(thisPointer)==false) { if (errorFunction) { errorFunction->finished(false,"endl"); }return; }

                pack->publicKey=public_key_;
                thisPointer->rsaKey=rsa_key_;

                //加密
                //static 函数
                encryptRSA(
                    pack->publicKey,
                    pack->passWordBase.toUtf8(),
                    [thisp,pack](
                    QByteArray enc_password_,
                    BCP_ errorFunction
                    ) mutable {

                    auto thisPointer=thisp.lock();
                    if (bool(thisPointer)==false) { if (errorFunction) { errorFunction->finished(false,"endl"); }return; }

                    thisPointer->postLogin(
                        pack->userNameBase.toUtf8().toPercentEncoding(),
                        thisPointer->rsaKey,
                        enc_password_,
                        thisPointer->token,
                        [thisp,pack](
                        std::shared_ptr< std::weak_ptr<QNetworkReply> > reply_,
                        BaiDuFinishedCallBackPointer errorFunction
                        ) {
                        auto thisPointer=thisp.lock();
                        if (bool(reply_)==false) {if (errorFunction) { errorFunction->finished(false,"reply error!"); }return;}
                        auto reply = reply_->lock();
                        if (bool(reply)==false) {if (errorFunction) { errorFunction->finished(false,"reply error!"); }return;}
                        if (bool(thisPointer)==false) { if (errorFunction) { errorFunction->finished(false,"endl"); }return; }

                        reply->connect(reply.get(),&QNetworkReply::finished,
                            thisPointer.get(),
                            [thisp,pack,reply_,errorFunction]() {
                            auto thisPointer=thisp.lock();
                            if (bool(thisPointer)==false) { if (errorFunction) { errorFunction->finished(false,"endl"); }return; }
                            
                            thisPointer->onLoginFinished( reply_ ,[thisp,pack](
                                BaiDuVertifyCode vc_,
                                BaiDuFinishedCallBackPointer errorFunction
                                ) {

                                auto thisPointer=thisp.lock();
                                if (bool(thisPointer)==false) { if (errorFunction) { errorFunction->finished(false,"endl"); }return; }

                                //emit
                                thisPointer->setVertifyCode( vc_.id,vc_.url );

                            },
                                errorFunction);
                        }
                        );

                    },
                        errorFunction
                        );

                },
                    errorFunction
                    );

            },
                errorFunction);

        },
            errorFunction);
    },
        pack
        );

}

BaiDuUser::BaiDuUser(QObject * o):QObject(o) {
    //创建子对象
    {
        thisp=std::make_shared<BaiDuUserPrivate>(thisp);
        thisp->thisPointer=thisp;
    }
    connect(this,&BaiDuUser::login,thisp.get(),&BaiDuUser::BaiDuUserPrivate::login);
    connect(thisp.get(),&BaiDuUser::BaiDuUserPrivate::loginFinished,this,&BaiDuUser::loginFinished);
}

void BaiDuUser::gid(
        std::function< void(QByteArray,BaiDuFinishedCallBackPointer) > fun,
        BaiDuFinishedCallBackPointer fp) {
    if (bool(fun)==false) {
        if (fp) { fp->finished(false,"call back is null "+QString(__func__)); }
        return;
    }

    QByteArray ans{ 35,Qt::Uninitialized };

    constexpr const static char toHex0[]={
        '0','1','2','3','4','5','6','7',
        '8','9','A','B','C','D','E','F',
    };

    constexpr const static char toHex1[]={
        '8','9','A','B','C','D','E','F',
        '8','9','A','B','C','D','E','F',
    };

    class Array {
        char data[35];
    public:
        Array():data{
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            '-',
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            '-',
            '4',
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            '-',
            toHex1[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            '-',
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15],
            toHex0[std::rand()&15]
        } {
        }
    };

    new(ans.data()) Array;
    fun(std::move(ans),fp);
}

void BaiDuUser::currentTimer(
        std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>  fun,
        BaiDuFinishedCallBackPointer fp) {
    if (bool(fun)==false) {
        if (fp) { fp->finished(false,"call back is null "+QString(__func__)); }
        return;
    }
    fun(QByteArray::number(QDateTime::currentMSecsSinceEpoch()),fp);
}

BaiDuUser::~BaiDuUser() {

    const auto __copy=thisp;
    if (thisp) {
        thisp->isOnDestory.store(true);
        thisp.reset();
    }

}

void BaiDuUser::BaiDuUserPrivate::getBaiduCookie(
        std::function< void(cct::Map<QByteArray,QNetworkCookie>,BaiDuFinishedCallBackPointer) > fun,
        BaiDuFinishedCallBackPointer fp) {

    if (bool(fun)==false) {
        if (fp) { fp->finished(false,"call back is null "+QString(__func__)); }
        return;
    }

    //ask
    const QUrl url("http://www.baidu.com");
    QNetworkRequest req(url);
    req.setRawHeader("User-Agent",this->userAgent);
    auto  reply__=std::shared_ptr<QNetworkReply>(manager->get(req),
        [](QNetworkReply * d) {d->deleteLater(); });
    std::weak_ptr<QNetworkReply> reply_(reply__);
    manager->addReply(reply__);//++
    auto thisPointer_=thisPointer;

    //获得返回值
    connect(reply__.get(),&QNetworkReply::finished,
            this,[thisPointer_,fun,fp,reply_]() {

        auto thisPointer=thisPointer_.lock();
        auto reply=reply_.lock();

        if ((bool(thisPointer)==false)||(bool(reply)==false)) {
            if (fp) { fp->finished(false,"endl"); }
            return;
        }

        thisPointer->manager->removeReply(reply);//--

        if (reply->error()!=QNetworkReply::NoError) {
            if (fp) { fp->finished(false,"reply error"); }
            return;
        }

        auto manager_=thisPointer->manager;
        auto allCookies=manager_->cookieJar()->cookiesForUrl(reply->url());

        for (const auto & i:reply->rawHeaderPairs()) {
            if (i.first=="Set-Cookie") {
                const auto ak_=QNetworkCookie::parseCookies(i.second);
                for (const auto & j:ak_) {
                    allCookies.push_back(j);
                }
            }
        }

        std::map<QByteArray,QNetworkCookie> ans;
        for (const auto & i:allCookies) {
            ans.insert({ i.name() ,i });
        }

        if (ans.find("BAIDUID")==ans.end()) {
            if (fp) { fp->finished(false,"can not find BAIDUID"); }
            return;
        }

        fun(std::move(ans),fp);
    });

}

namespace {

template<typename IB,typename IE>
QByteArray toHtmlUrl(QByteArray ans,IB b,IE e) {
    for (; b!=e; ++b) {
        const auto & first_=b->first;
        const auto & second_=b->second;
        ans.append("&"+first_+"="+second_);
    }
    return std::move(ans);
}

}

QVariant BaiDuUser::BaiDuUserPrivate::getAllCookies()const {

    QList< QNetworkCookie > ans;
    if (cookies) {
        for (const auto & i:*cookies) {
            ans.push_back(i.second);
        }
    }
    return std::move(QVariant::fromValue(std::move(ans)));
}

//userAgent
//cookies
void BaiDuUser::BaiDuUserPrivate::getBaiduToken(
    std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> fun,
    BaiDuFinishedCallBackPointer fp) {

    if (bool(fun)==false) {
        if (fp) { fp->finished(false,"call back is null "+QString(__func__)); }
        return;
    }

    /* 发送接下来的请求 */
    QUrl rURL;
    {
        const static QByteArray url_0("https://passport.baidu.com/v2/api/?getapi");
        QByteArray ctt;
        BaiDuUser::currentTimer([&ctt](auto ans,auto) {ctt=ans; },fp);
        if (fp) { if (fp->hasError) { return; } }

        std::pair< const QByteArray,const QByteArray > urlData[]{
            { "tpl","mn"}                   ,
            { "apiver","v3" }               ,
            { "tt",ctt }        ,
            { "class","login" }             ,
            { "gid",this->gid }             ,
            { "logintype","dialogLogin" }   ,
            { "callback","bd__cbs__89tioq" },
        };

        auto url__=toHtmlUrl(url_0,std::begin(urlData),std::end(urlData));
        rURL.setUrl(url__);
    }

    QNetworkRequest req(rURL);
    req.setRawHeader("User-Agent",this->userAgent);
    req.setHeader(QNetworkRequest::CookieHeader,getAllCookies());

    // 
    auto replyNext_=std::shared_ptr<QNetworkReply>(manager->get(req),
        [](QNetworkReply * d) { d->deleteLater(); }
    );

    manager->addReply(replyNext_);//++
    std::weak_ptr<QNetworkReply> replyNext(replyNext_);
    auto thisPointer_=thisPointer;

    //读取返回值
    connect(replyNext_.get(),&QNetworkReply::finished,
        this,[replyNext,thisPointer_,fp,fun]() mutable {
        auto reply_=replyNext.lock();
        auto thisPointer=thisPointer_.lock();

        if (bool(reply_)==false) {
            if (fp) { fp->finished(false,"null""endl"); }
            return;
        }

        if (bool(thisPointer)==false) {
            if (fp) { fp->finished(false,"null""endl"); }
            return;
        }

        //delete
        thisPointer->manager->removeReply(reply_);//--

        auto json=reply_->readAll();

        if (json.isEmpty()) {
            if (fp) { fp->finished(false,"null""BaiDuUser::BaiDuUserPrivate::getBaiduToken"); }
            return;
        }

        json=json.mid(json.indexOf("(")+1);
        json.resize(json.size()-1);

        QScriptEngine eng;
        eng.evaluate("var bd__cbs__89tioq = "+json);
        auto error=eng.evaluate(u8R"(bd__cbs__89tioq["errInfo"]["no"])").toString();
        auto token=eng.evaluate(u8R"(bd__cbs__89tioq["data"]["token"])").toString();

        if (error!="0") {
            if (fp) { fp->finished(false,"reply error "+QString(__func__)); }
            return;
        }

        //执行回调
        fun(token.toUtf8(),fp);

    }
    );
}

//获得rsa key 
void BaiDuUser::BaiDuUserPrivate::getRSAKey(
    cct::Func< void(QByteArray/*rsa key*/,
    QByteArray/*pub key*/,
    BaiDuFinishedCallBackPointer) > fun,
    BaiDuFinishedCallBackPointer fp
    ) {

    if (bool(fun)==false) {
        if (fp) { fp->finished(false,"call back is null "+QString(__func__)); }
        return;
    }

    //获得当前时间
    QByteArray ctt;
    BaiDuUser::currentTimer([&ctt](auto ans,auto) {ctt=ans; },fp);
    if (fp) { if (fp->hasError) { return; } }

    QUrl rURL;
    {
        const static QByteArray url_0("https://passport.baidu.com/v2/getpublickey?token=");
        QByteArray url_1=url_0+this->token;
        std::pair< const QByteArray,const QByteArray > urlData[]{
            { "tpl","mn" }                   ,
            { "apiver","v3" }               ,
            { "tt",ctt }        ,
            { "class","login" }             ,
            { "gid", gid }            ,
            { "callback","bd__cbs__dmwxux" },
        };
        auto url__=toHtmlUrl(url_1,std::begin(urlData),std::end(urlData));
        rURL.setUrl(url__);
    }

    QNetworkRequest req(rURL);
    req.setRawHeader("User-Agent",userAgent);
    req.setRawHeader("Accept-Encoding","gzip, deflate");

    auto manager_=manager;
    auto replyNext__=std::shared_ptr<QNetworkReply>(manager_->get(req),
        [](QNetworkReply * d) { d->deleteLater(); }
    );
    manager->addReply(replyNext__);//++
    std::weak_ptr<QNetworkReply> replyNext_(replyNext__);
    // 
    auto thisPointer_=thisPointer;

    connect(replyNext__.get(),&QNetworkReply::finished,
        this,[replyNext_,thisPointer_,fp,fun]() mutable {

        auto replyNext=replyNext_.lock();
        auto thisPointer=thisPointer_.lock();

        if (bool(replyNext)==false) {
            if (fp) { fp->finished(false,"null""endl"); }
            return;
        }

        if (bool(thisPointer)==false) {
            if (fp) { fp->finished(false,"null""endl"); }
            return;
        }

        //delete
        thisPointer->manager->removeReply(replyNext);//--

        auto * reply_=replyNext.get();

        //
        {
            QString publickey_;
            auto json=reply_->readAll();
            json=gzip::QCompressor::gzipDecompress(json);

            if (json.isEmpty()) {
                if (fp) { fp->finished(false,"BaiDuLogIn_Step3 : empty reply ! "); }
                return;
            }

            json=json.mid(json.indexOf("(")+1);
            json.resize(json.size()-1);

            QScriptEngine eng;

            eng.evaluate("var bd__cbs__dmwxux = "+json);
            const auto error=eng.evaluate(u8R"(bd__cbs__dmwxux["errno"])").toString();
            publickey_=eng.evaluate(u8R"(bd__cbs__dmwxux["pubkey"])").toString();
            const auto key=eng.evaluate(u8R"(bd__cbs__dmwxux["key"])").toString();

            if (error!="0") {
                if (fp) { fp->finished(false,"BaiDuLogIn_Step3 : jsom reply error ! "); }
                return;
            }

            auto rsa_key=key.toUtf8();
            fun(rsa_key,publickey_.toUtf8(),fp);
        }

    });

}

//static function
//使用rsa 加密
void BaiDuUser::BaiDuUserPrivate::encryptRSA(
    QByteArray public_key_,
    QByteArray pass_word_,
    cct::Func< void(QByteArray,BaiDuFinishedCallBackPointer) > fun,
    BaiDuFinishedCallBackPointer fp
    ) {

    if (bool(fun)==false) {
        if (fp) { fp->finished(false,"call back is null "+QString(__func__)); }
        return;
    }

    {
        QCA::ConvertResult pubkey_isok_;
        QCA::PublicKey pubkey_=
            QCA::RSAPublicKey::fromPEM(public_key_,&pubkey_isok_);

        if (!(QCA::ConvertGood==pubkey_isok_)) {
            if (fp) { fp->finished(false,"qca get public key error!!"); }
            return;
        }

        if (pubkey_.canEncrypt()==false) {
            if (fp) { fp->finished(false,"BaiDuLogIn_Step3 : rsa error ! "); }
            return;
        }

        /* reset password */
        QCA::SecureArray result_=pubkey_.encrypt(
            pass_word_,
            QCA::EME_PKCS1v15_SSL
            );

        QByteArray result=result_.toByteArray();
        if (result_.isEmpty()) {
            if (fp) { fp->finished(false,"BaiDuLogIn_Step3 : rsa encode error ! "); }
            return;
        }

        fun(result.toBase64().toPercentEncoding(),fp);

    }

}

//unused
void BaiDuUser::BaiDuUserPrivate::setChildrenPointer(QObject * o) {

    if (o) {
        connect(this,&QObject::destroyed,
            o,[o](QObject *) { o->blockSignals(true); o->deleteLater(); }
        );
    }

}

//void 
void  BaiDuUser::BaiDuUserPrivate::postLogin(
    QByteArray user_name_,
    QByteArray rsa_key_,
    QByteArray enc_password_,
    QByteArray token_,
    cct::Func< void(std::shared_ptr< std::weak_ptr<QNetworkReply> >,BaiDuFinishedCallBackPointer) > fun,
    BaiDuFinishedCallBackPointer fp
    ) {

    if (bool(fun)==false) {
        if (fp) { fp->finished(false,"call back is null "+QString(__func__)); }
        return;
    }

    const static constexpr char * staticPage="https%3A%2F%2Fwww.baidu.com%2Fcache%2Fuser%2Fhtml%2Fv3Jump.html";
    const static constexpr char * u="https%3A%2F%2Fwww.baidu.com%2F";
    const static constexpr char * splogin="rate";
    const static constexpr char * logLoginType="pc_loginDialog";
    const static constexpr char * safeflg="0";
    const static constexpr char * detect="1";
    const static constexpr char * quick_user="0";
    const static constexpr char * memberPass="on";
    const static constexpr char * loginType="dialogLogin";
    const static constexpr bool isPhone=false;
    const static constexpr bool loginmerge=true;

    /* 发起登录请求 */
    QUrl url("https://passport.baidu.com/v2/api/?login");
    QNetworkRequest req(url);
    QByteArray postData=QByteArray("staticpage=")+staticPage;

    QByteArray current_time_;

    BaiDuUser::currentTimer([&current_time_](auto ans,auto) {current_time_=ans; },fp);
    if (fp) { if (fp->hasError) { return; } }

    {
        std::pair< const QByteArray,const QByteArray > postData_[]{
            {"charset","utf-8"},
            {"token",token_ },
            {"tpl","mn"},
            {"subpro",""},
            {"apiver","v3"},
            {"tt",current_time_ },
            {"codestring", this->vertifyCode.id },/*验证码*/
            {"safeflg",safeflg},
            {"u", u },
            {"isPhone",isPhone?"true":"false"},
            {"detect", detect},
            {"gid", this->gid },
            {"quick_user",quick_user},
            {"logintype",loginType},
            {"logLoginType",logLoginType },
            {"idc",""},
            {"loginmerge",loginmerge?"true":"false"},
            {"splogin",splogin },
            {"username",user_name_ },
            {"password",enc_password_ },
            {"verifycode",this->vertifyCode.ans },/*验证码id*/
            {"mem_pass",memberPass},
            {"rsakey",rsa_key_ },
            {"crypttype","12"},
            {"ppui_logintime",QByteArray::number(10000+(rand()%9999)) },/*随机数*/
            {"countrycode",""},
            {"callback","parent.bd__pcbs__s09032"}
        };
        postData=toHtmlUrl(postData,std::begin(postData_),std::end(postData_));
    }

    req.setHeader(QNetworkRequest::CookieHeader,this->getAllCookies());
    req.setRawHeader("Accept","text/html, application/xhtml+xml, */*");
    req.setRawHeader("Referer","https://www.baidu.com/");
    req.setRawHeader("Accept-Language","zh-CN");
    req.setRawHeader("User-Agent",this->userAgent);
    req.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    req.setRawHeader("Accept-Encoding","gzip, deflate");

    auto manager_=this->manager;
    auto * replyNext_=manager_->post(req,postData);
    auto replyNext=std::shared_ptr<QNetworkReply>(replyNext_,
        [](QNetworkReply * d) {  d->deleteLater();  });

    manager_->addReply(replyNext);//++
    std::weak_ptr< BaiDuUserLoginNetworkAccessManager > wm_(manager_);

    std::shared_ptr< std::weak_ptr<QNetworkReply> > ans(
        new std::weak_ptr<QNetworkReply>(replyNext),
        [wm_](std::weak_ptr<QNetworkReply> * d) mutable {
        auto m_=wm_.lock();//get a copy of manager
        auto d_=d->lock();//get a copy of data
        if (d_) { if (m_) { m_->removeReply(d_); } }//remove data //--
        delete d;//delete watcher
    }
    );

    //结束回调
    return fun(ans,fp);

}

/*
错误处理以及分词
*/
namespace {

class BaiDuLogIn_Step4 {
private:
    static const std::map<int,QString> & _errorCode() {

        static std::map<int,QString> ans{
            { -1	    ,u8"系统错误,请您稍后再试"_qutf8 }	,
            { 1	        ,u8"您输入的帐号格式不正确"_qutf8 }	,
            { 2	        ,u8"您输入的帐号不存在"_qutf8 }	,
            { 3	        ,u8"验证码不存在或已过期,请重新输入"_qutf8 }	,
            { 4	        ,u8"您输入的帐号或密码有误"_qutf8 }	,
            { 5	        ,u8"请在弹出的窗口操作,或重新登录"_qutf8 }	,
            { 6	        ,u8"您输入的验证码有误"_qutf8 }	,
            { 7	        ,u8"密码错误"_qutf8 }	,
            { 16	    ,u8"您的帐号因安全问题已被限制登录"_qutf8 }	,
            { 257	    ,u8"请输入验证码"_qutf8 }	,
            { 100027	,u8"百度正在进行系统升级，暂时不能提供服务，敬请谅解"_qutf8 }	,
            { 400031	,u8"请在弹出的窗口操作,或重新登录"_qutf8 }	,
            { 401007	,u8"您的手机号关联了其他帐号，请选择登录"_qutf8 }	,
            { 120021	,u8"登录失败,请在弹出的窗口操作,或重新登录"_qutf8 }	,
            { 500010	,u8"登录过于频繁,请24小时后再试"_qutf8 }	,
            { 200010	,u8"验证码不存在或已过期"_qutf8 }	,
            { 100005	,u8"系统错误,请您稍后再试"_qutf8 }	,
            { 120019	,u8"请在弹出的窗口操作,或重新登录"_qutf8 }	,
            { 110024	,u8"此帐号暂未激活"_qutf8 }	,
            { 100023	,u8"开启Cookie之后才能登录"_qutf8 }	,
            { 17	    ,u8"您的帐号已锁定"_qutf8 },
            { 500002    ,u8"您输入的验证码有误"_qutf8},
            { 500018    ,u8"验证码已失效，请重试"_qutf8}
        };

        return ans;
    }
public:

    static const std::map<int,QString> & errorCode() {
        static const std::map<int,QString> & ans=_errorCode();
        return ans;
    }

    template<typename T,typename N>
    static std::map< std::string,std::string >
        getAnsMap(T & rData,N  fp) {
        std::map< std::string,std::string > ansMap;
        {
            std::list< std::string > allLines;
            {
                std::string line(rData.data(),rData.size());
                auto enp=line.find("err_no=");
                if (enp==std::string::npos) {
                    if (fp) { fp->finished(false,"BaiDuLogIn_Step4 : err_no= can not find ! "); }
                    return std::map< std::string,std::string >();
                }
                line=std::string(line.begin()+enp,line.end());
                std::stringstream stream(std::move(line));
                while (std::getline(stream,line,'&')) {
                    allLines.push_back(line);
                }
                if (allLines.empty()) {
                    if (fp) { fp->finished(false,"BaiDuLogIn_Step4 :& can not find ! "); }
                    return std::map< std::string,std::string >();
                }

                line=*allLines.rbegin();
                allLines.pop_back();
                enp=line.find("\"");
                if (enp!=std::string::npos) {
                    allLines.push_back(std::string(line.begin(),line.begin()+enp));
                }

            }
            for (const auto & i:allLines) {
                auto pos=i.find('=');
                if (pos==std::string::npos) { continue; }
                auto tmp=i.cbegin();
                ansMap[std::string(tmp,tmp+pos)]=
                    std::string(tmp+pos+1,i.cend());
            }
        }

        return std::move(ansMap);

    }
};

}


void BaiDuUser::BaiDuUserPrivate::onLoginFinished(
    std::shared_ptr< std::weak_ptr<QNetworkReply> > rp,
    cct::Func< void(BaiDuVertifyCode,BaiDuFinishedCallBackPointer) > fun,/*验证码回调*/
    BaiDuFinishedCallBackPointer fp /*结果回调,true false*/
    ) {

    if (bool(rp)==false) {
        if (fp) { fp->finished(false," reply null  "); }
        return;
    }

    auto rp_=rp->lock();
    if (bool(rp)==false) {
        if (fp) { fp->finished(false," reply null . "); }
        return;
    }

    if (bool(fun)==false) {
        if (fp) { fp->finished(false,"call back is null "+QString(__func__)); }
        return;
    }

    auto * reply_=rp_.get();

    {
        auto rData=reply_->readAll();
        rData=gzip::QCompressor::gzipDecompress(rData);

        if (rData.isEmpty()) {
            if (fp) { fp->finished(false,"BaiDuLogIn_Step4 : empty reply ! "); }
            return;
        }

        auto ansMap=BaiDuLogIn_Step4::getAnsMap(rData,fp);
        if (fp) { if (fp->hasError) { return; } }

        int err_no=0;
        if (ansMap["err_no"]!="0") {
            QString error_;
            std::stringstream ss(ansMap["err_no"]);
            ss>>err_no;
            auto e_=BaiDuLogIn_Step4::errorCode().find(err_no);
            if (e_==BaiDuLogIn_Step4::errorCode().end()) {
                error_=u8R"(未知百度错误:)"_qutf8+QString::fromStdString(ansMap["err_no"]);
            }
            else {
                error_=e_->second+":"+QString::fromStdString(ansMap["err_no"]);
            }

            {
                //https://passport.baidu.com/cgi-bin/genimage?
                const std::string & gv_=ansMap["codeString"];
                if (gv_.empty()==false) {
                    //验证码
                    if (fp) { fp->finished(false,"验证码"_qutf8); }
                    BaiDuVertifyCode vc_;
                    vc_.url=QByteArray("https://passport.baidu.com/cgi-bin/genimage?")+gv_.c_str();
                    vc_.id =QByteArray(gv_.c_str());
                    if (fun) { fun(vc_,fp); }
                }
                return;
            }

            if (fp) { fp->finished(false,error_); }
            return;
        }

        /* 保存cookie */
        {
            const auto rawHeaderPairs=reply_->rawHeaderPairs();
            auto & cks_=cookies;
            for (const auto & i:rawHeaderPairs) {
                if (i.first=="Set-Cookie") {
                    auto c_=QNetworkCookie::parseCookies(i.second);
                    for (const auto & j:c_) {
                        cks_->operator[](j.name())=j;
                    }
                }
            }
        }
        
        /*set more cookie*/
        {
            auto  _manager=manager;
            QNetworkRequest _req(QUrl{ "https://www.baidu.com/?tn=98012088_5_dg&ch=12" });
            _req.setHeader(QNetworkRequest::CookieHeader,getAllCookies());
            _req.setRawHeader("Accept-Encoding","gzip, deflate");
            _req.setRawHeader("User-Agent",userAgent);

            auto __r = std::shared_ptr< QNetworkReply>(_manager->get(_req),
                [](QNetworkReply * d) {d->deleteLater(); }
            );

            std::weak_ptr<QNetworkReply> _0r(__r);
            auto thisPointer_=thisPointer;

            manager->addReply(__r);//++
            connect(__r.get(),&QNetworkReply::finished,
                this,[_0r,thisPointer_]() {
                auto thisPointer=thisPointer_.lock();
                auto _r=_0r.lock();

                if (bool(_r)==false) { return; }
                if (bool(thisPointer)==false) { return; }

                thisPointer->manager->removeReply(_r);//--

                /* 保存cookie */
                {
                    const auto rawHeaderPairs=_r->rawHeaderPairs();
                    _r->deleteLater();
                    auto & cks_=thisPointer->cookies;
                    for (const auto & i:rawHeaderPairs) {
                        if (i.first=="Set-Cookie") {
                            auto c_=QNetworkCookie::parseCookies(i.second);
                            for (const auto & j:c_) {
                                // qDebug()<<"!"<<j.name();
                                cks_->operator[](j.name())=j;
                            }
                        }
                    }
                }

            });//~lambda

        }

    }

    //完成
    if (fp) { fp->finished(true,""); }

}

/*
endl of the file
*/
