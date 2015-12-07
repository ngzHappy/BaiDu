#include "private/PBaiduTieBa.hpp"
#include "private/GZipCompressor.hpp"
#include "BaiDuNetworkAccessManager.hpp"
#include "BaiDuTieBa.hpp"
#include <FunctionType.hpp>
#include <CheckArgs.hpp>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkCookieJar>
#include <QScriptEngine>
#include <cstddef>
#include <QBuffer>
#include <regex>
#include <QCoreApplication>
#include <QDir>
#include <QDataStream>
#include <QTextCodec>
#include <QDebug>
#include <fstream>
#include "TextConvert.hpp"
namespace {

QString operator""_qutf8(const char * d,std::size_t n) {
    return QString::fromUtf8(d,n);
}

}

namespace {

template<typename IB, typename IE>
QByteArray toHtmlUrl(QByteArray ans, IB b, IE e) {

    for (; b!=e; ++b) {
        const auto & first_=b->first;
        const auto & second_=b->second;
        ans.append("&"+first_+"="+second_);
    }
    return std::move(ans);
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
//"[emotion+pic_type=1+width=30+height=30]http://tb2.bdstatic.com/tb/editor/images/face/i_f15.png?t=20140803[/emotion] 
namespace private_{
constexpr const char * baiDuTieBaEmotion_[]{
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f01.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f02.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f03.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f04.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f05.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f06.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f07.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f08.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f09.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f10.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f11.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f12.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f13.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f14.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f15.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f16.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f17.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f18.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f19.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f20.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f21.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f22.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f23.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f24.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f25.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f26.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f27.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f28.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f29.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f30.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f31.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f32.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f33.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f34.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f35.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f36.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f37.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f38.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f39.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f40.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f41.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f42.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f43.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f44.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f45.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f46.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f47.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f48.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f49.png%3Ft%3D20140803%5B%2Femotion%5D",
    "%5Bemotion+pic_type%3D1+width%3D30+height%3D30%5Dhttp%3A%2F%2Ftb2.bdstatic.com%2Ftb%2Feditor%2Fimages%2Fface%2Fi_f50.png%3Ft%3D20140803%5B%2Femotion%5D",
};

constexpr const auto baiDuTieBaEmotionSize_=(sizeof(baiDuTieBaEmotion_)/sizeof(const char *));

}
}

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
    connect(this,&BaiDuTieBa::send,
        thisp.get(),&BaiDuTieBaPrivate::sendData ,Qt::QueuedConnection );
    connect(thisp.get(),&BaiDuTieBaPrivate::sendDataFinished,
        this,&BaiDuTieBa::finishedSend,Qt::QueuedConnection
        );
    connect(thisp.get(),&BaiDuTieBaPrivate::vertifyCode,
        this,&BaiDuTieBa::vertifyCode,Qt::QueuedConnection );
    connect(this,&BaiDuTieBa::post,
        thisp.get(),&BaiDuTieBaPrivate::postData ,Qt::QueuedConnection );
    connect(thisp.get(),&BaiDuTieBaPrivate::genImageContent,
            this,&BaiDuTieBa::imageContentChanged ,Qt::QueuedConnection );
    connect(this,&BaiDuTieBa::sign,thisp.get(),&BaiDuTieBaPrivate::sign,Qt::QueuedConnection);
    connect(this,&BaiDuTieBa::postUnderFloor,thisp.get(),&BaiDuTieBaPrivate::postUnderFloorData,Qt::QueuedConnection);
}

std::shared_ptr<BaiDuUser> BaiDuTieBa::getBaiDuUser()const {
    return thisp->baiDuUser;
}

#define _zfunc cct::FunctionType< decltype( &BaiDuTieBa::setBaiDuUser ) >
void BaiDuTieBa::setBaiDuUser( _zfunc::_0 u ) {
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
#undef _zfunc

BaiDuTieBa::~BaiDuTieBa(){

    if (thisp) {
        thisp->isOnDestory.store(true);
        disconnect(this,nullptr,thisp.get(),nullptr);
        disconnect(thisp.get(),nullptr,this,nullptr);
        thisp.reset();
    }

}


BaiDuTieBaPrivate::BaiDuTieBaPrivate(){

}

BaiDuTieBaPrivate::~BaiDuTieBaPrivate(){
    isOnDestory.store(true);
}

SendTieBaDataPack::SendTieBaDataPack() {
}

void SendTieBaDataPack::finished(bool v,QString d) {
    if (isValueSet) { return; }
    isValueSet=true;
    hasError_=!v;
    sendFinished(v,d);

}

SendTieBaDataPack::~SendTieBaDataPack() {

    if (isValueSet) {}
    else {
        sendFinished(false,"??? /SendTieBaDataPack::~SendTieBaDataPack endl ");
    }
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
        [ fun , rp_ ,fp/*shared_ptr*/ , mn_ ](  ) {
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
        [ fun , rp_ ,fp/*shared_ptr*/ , mn_ ](  ) {
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

namespace
{
QByteArray get_rand_name() {
    /*
    获得一个随机的图片名称
    防止和谐
    */
    constexpr const static char table_[]{
        'x','y','z','w','X','Y','Z','W',
        't','n','v','q','T','N','V','Q',
        'k','m','o','r','K','M','O','R',
        'j','l','i','u','J','L','I','U',
    };

    enum {table_size_ = (sizeof(table_)/sizeof(char)) };

    QByteArray ans("I_M_A_G_E)");
    ans.reserve(32);
    const auto n=(rand()&7)+1;
    for (int i=0; i<n;++i) {
        ans.push_back(table_[((rand())%table_size_)]);  ans.append('_');
    }
    return ans+".jpg";
}
}

#define _zfunc cct::FunctionType< decltype( &BaiDuTieBaPrivate::image2html ) >
void BaiDuTieBaPrivate::image2html(
    _zfunc::_r3 fid_  ,
    _zfunc::_r2 image_,
    _zfunc::_r1 fun   ,
    _zfunc::_r0 fp    ) try{

    cct::check_args<ArgError>(
        !fid_.isEmpty(),"fid is null",
        !image_.isNull(),"image is null",
        fun,"callback is null",
        baiDuUser,"user is null",
        baiDuUser->isLogin(),"user is not login"
        );

    auto u= baiDuUser;
    /*设置百度贴吧图像最大宽度为1024*/
    enum { MaxImageWidth = 1024 };
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

    auto wthisp = thisp;
    BaiDuTieBa::imgtbs(u,[u,fid_,fun,imageData,wthisp](QByteArray itbs_,_zfunc::_r0 fp) {
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
                    ii.isImage = true;
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

#define _zfunc cct::FunctionType< decltype(&BaiDuTieBaPrivate::images2html ) >
void BaiDuTieBaPrivate::images2html(
    _zfunc::_r4 fid_   ,
    _zfunc::_r3 images_names_,
    _zfunc::_r2 images_,
    _zfunc::_r1 fun ,
    _zfunc::_r0 fp ) try{

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
        void finished(bool v, QString) override { hasError_=!v; }
        int image_count;
        cct::List<TieBaTextImageType> ans_data;
        BaiDuFinishedCallBackPointer error_call_back;
        _zfunc::_r1 call_back;
    };

    auto pack_=std::make_shared<FinishedPack>();
    pack_->image_count=all_size_;
    pack_->error_call_back=fp;
    pack_->call_back=fun;

    auto ib = images_names_.cbegin();
    for (const auto & i:images_) {
        QString image_local_name__ = *ib;
        image2html(fid_,i,[pack_,image_local_name__ ](
            TieBaTextImageType item,
            BaiDuFinishedCallBackPointer ) mutable {
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
#undef _zfunc

#define _zfunc cct::FunctionType< decltype(&BaiDuTieBaPrivate::localTieBa2BaiDuTieBa ) >
void BaiDuTieBaPrivate::localTieBa2BaiDuTieBa(
    _zfunc::_r4 /*fid*/ fid_,
    _zfunc::_r3 dir_,
    _zfunc::_r2 ldata_,
    _zfunc::_r1 fun,
    _zfunc::_r0 fp) try{

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
            QImage image__( dir_+"/"+QString(j) ) ;/*change here to add speed*/
            about_post_images_.push_back( std::move( image__ ) );
            about_to_post_names_.push_back( j );
        }
    }

    if ( about_to_post_names_.empty() ) {
        return fun(ldata_,fp);
    }

    std::shared_ptr<TieBaFormatData> ans = TieBaFormatData::instance() ;
    *ans=*ldata_;//copy data

    auto thisPointer = thisp ;
    images2html(
        fid_,
        about_to_post_names_,
        about_post_images_,
        [ans, fun , thisPointer ](
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
        /*
        */

        {/*保存结果*/
            auto thisp=thisPointer.lock();
            if (thisp) {
                QString ans_;QTextStream stream_(&ans_);
                ans->write(stream_);thisp->genImageContent(ans_);
            }
        }

        fun( ans,fp );

    },fp);

}catch (const ArgError & e) {
    if (fp) { fp->finished(false,e.what()+ " " +__func__); }
}
#undef _zfunc

namespace {
namespace BaiDuTieBa__{
/*操作系统回收资源*/
std::recursive_mutex * mutex = nullptr ;
/*操作系统回收资源*/
std::map<QString,QByteArray> * fidMap = nullptr  ;
/*操作系统回收资源*/
QString * fidFileName = nullptr;

void read() {
    auto dir_ = QCoreApplication::applicationDirPath();
    {
        QDir dir(dir_);
        dir.mkdir(dir_+"/data");
        dir.mkdir(dir_+"/data/tid");
    }

    QString fileName(dir_+"/data/tid/tid.txt");
    fidFileName = new auto( fileName );
    QFile file( fileName);

    if ( file.exists() ) {
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

    QFile file( *fidFileName );
    if ( file.open(QIODevice::WriteOnly) ) {
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

#define _zfunc cct::FunctionType< decltype(&BaiDuTieBa::fid) >
void BaiDuTieBa::fid(
    _zfunc::_r3 u,
    _zfunc::_r2 /*贴吧名字*/ tbname ,
    _zfunc::_r1 fun,
    _zfunc::_r0 fp) try{
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

    auto user_agent=u->getUserAgent();
    req.setRawHeader("User-Agent", user_agent.first );
    req.setRawHeader("Accept-Encoding", "gzip, deflate");
    req.setRawHeader("Connection", "keep-alive");
    req.setRawHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");

    auto * r=m->get( req );
    std::shared_ptr< QNetworkReply > rp(r,[](QNetworkReply * d) {d->deleteLater(); });
    std::weak_ptr< QNetworkReply > wr( rp );
    std::weak_ptr< BaiDuNetworkAccessManager > wm(m);
    m->addReply(rp);

    bool isPhone_=user_agent.second;
    r->connect(r,&QNetworkReply::finished,
        [isPhone_,tbname,wr,wm,fun,fp]() {
        auto r=wr.lock();
        auto m=wm.lock();
        try {
            cct::check_args<ArgError>(r,"",m,"");
            m->removeReply(r);
            QByteArray ans=r->readAll();
            ans=gzip::QCompressor::gzipDecompress(ans);
            cct::check_args<ArgError>(!ans.isEmpty(),"can not find tieba ");
            
            if ( isPhone_ ) {
                const char * begin=ans.constBegin();const char * end=ans.constEnd();
                //"fid" : "2256767",  
                // var _sl = new SignArrow({            $el: $('#j_light_forum_top_area'),            conf : {                'likeOperateUrl' : _singConf.baseUrl + 'favolike',                'signOperateUrl' : _singConf.baseUrl + 'sign',                'firstLikeSucceedTip': '恭喜你成为本吧第'+ memberNum +'位会员。',                "baseUrl" : _singConf.baseUrl,                "is_sign": "0",                "is_like": "1",                "cur_score":"50",                "user_level":"5",                "ifLogin":true,                "levelup_score":"100",                "uid" : "172018404",                "fid" : "2256767",                "tbs" : "adad9e52bdb905671449364762",                "kw" : "垬",                'sign_dialog_title' : "签到神器",                'sign_dialog_content' : "启动贴吧客户端签到送4倍经验！",  
                const static std::regex reg(u8R"(["']fid["'][ ]*:[ ]*["']([0-9]+)["'],)");
                std::cmatch match;
                if (std::regex_search(begin,end,match,reg)) {
                    auto mans=match[1]; QByteArray ans(mans.first,mans.length());
                    BaiDuTieBa__::inster(tbname,ans );
                    fun(ans ,fp);
                }
                else {
                    throw ArgError("phone fid can not find");
                }
            }
            else {
                const char * begin=ans.constBegin();const char * end=ans.constEnd();
                std::cmatch match;
                if (std::regex_search(begin,end,match,std::regex("PageData.forum"))) {
                    begin=match[0].second;
                    if (std::regex_search(begin,end,match,std::regex(R"(['"]?id['"]?[ ]*:)"))) {
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

                        BaiDuTieBa__::inster(tbname,ans.trimmed().toUtf8());
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

        }
        catch (const ArgError & e) {
            if (fp) { fp->finished(false,e.what()+ " " +__func__); }
        }
    });

}catch (const ArgError & e) {
    if (fp) { fp->finished(false,e.what()+ " " +__func__); }
}
#undef _zfunc

//TODO: gen post data
QByteArray BaiDuTieBaPrivate::genPostData(
    SendTieBaDataPack::Type type,
    std::shared_ptr<TieBaFormatData> data
    ) {
    if (bool(data)==false) { return QByteArray(); }
    if (data->empty()) { return QByteArray(); }
    QByteArray about_post_;
    for (const auto & i: (*data) ) {
        if (i.isImage) {

            double width_= i.width.toInt();
            double height_=i.height.toInt();

            /*百度最大图片宽度*/
            constexpr static const int max_width_=560;
            constexpr static const char * max_width_string="560";

            if (width_ <= max_width_ ) {
                /* %5B [%3D =%2F /%5D ] */
                QByteArray img__;
                //img__.append("%5Bbr%5D");
                img__.append("%5Bimg");
                img__.append("+""pic_type%3D1");//type 1 jpeg
                img__.append("+""width%3D"    +i.width );//
                img__.append("+""height%3D"   +i.height);//
                img__.append("%5D");
                img__.append( i.trimmed().toUtf8().toPercentEncoding()  );
                img__.append("%5B%2Fimg%5D");
                img__.append("%5Bbr%5D");
                about_post_.append( img__  );
            }
            else {
                height_/=width_; height_*=max_width_ ;
                QByteArray img__;
                //img__.append("%5Bbr%5D");
                img__.append("%5Bimg");
                img__.append("+""pic_type%3D1");//type 1 jpeg
                img__.append("+" "width%3D"   );//
                img__.append( max_width_string );
                img__.append("+" "height%3D" + QByteArray::number(int(height_+0.6666)) );//
                img__.append("%5D");
                img__.append( i.trimmed().toUtf8().toPercentEncoding()  );
                img__.append("%5B%2Fimg%5D");
                img__.append("%5Bbr%5D");
                about_post_.append( img__  );
            }

        }
        else {

            std::list<QString > all_lists;
            {
                QString __tmp=i;
                QTextStream stream( &__tmp );
                while ( stream.atEnd()==false ) {
                    all_lists.push_back( stream.readLine().trimmed() );
                }
            }

            for(auto  _istr_ : all_lists ){
                {//简体字转繁体字
                    QString __istr__; __istr__.reserve(_istr_.size());
                    for (const auto & j:_istr_) {
                        auto ans_=TextConvert::c2tc((char16_t)(j.unicode()));
                        __istr__.push_back(ans_[0]);
                    }
                    _istr_=__istr__;
                }

                if ( type == SendTieBaDataPack::Type::REPLY_FLOOR_TIEBABAIDU ) {
                    const QByteArray space_0( private_::baiDuTieBaEmotion_[ rand()%(private_::baiDuTieBaEmotionSize_) ] );
                    const QByteArray space_1( private_::baiDuTieBaEmotion_[ rand()%(private_::baiDuTieBaEmotionSize_) ] );
                    about_post_.append(space_0+space_1+_istr_.toUtf8().toPercentEncoding()+"%5Bbr%5D");
                }
                else {
                    const QByteArray space_0("%E3%80%80");
                    const QByteArray space_1("%E3%80%80");                    
                    about_post_.append(space_0+space_1+_istr_.toUtf8().toPercentEncoding()+"%5Bbr%5D");
                }
            }

        }
    }
    return about_post_;
}

#define _zfunc
void BaiDuTieBaPrivate::sendDetail(
    const SendTieBaDataPack::Type type,
    const QString/*tbname*/& tbname,
    const QString/*title*/& ttitle,
    const QByteArray/*data*/& data,
    const QByteArray/*tbs*/& tbs,
    const BaiDuVertifyCode& vc,
    const QByteArray/*fid*/& fid ,
    const QByteArray/**/&  _tid ,
    const QByteArray/**/&_floor_num ,
    const QByteArray & _pid,
    const std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>  & fun,
    BaiDuFinishedCallBackPointer  fp) try{

    auto thisPointer = thisp.lock();
    cct::check_args<ArgError>(thisPointer,"endl");
    auto u=thisPointer->baiDuUser;
    cct::check_args<ArgError>(u,"endl");
    cct::check_args<ArgError>(u->isLogin(),"endl");
    auto m=u->getManager();
    cct::check_args<ArgError>(m,"endl");

    QByteArray postdata="ie=utf-8";
    {
        QByteArray ctime_;
        BaiDuUser::currentTimer([&ctime_](auto ans,auto) { ctime_=ans; },fp);
        if (fp) { if (fp->hasError() ) { return; } }
        QByteArray mouse_pwd_;
        BaiDuTieBa::mouse_pwd(ctime_,[&mouse_pwd_](auto ans,auto) {
            mouse_pwd_=ans;
        },fp);
        if (fp) { if (fp->hasError() ) { return; } }
        
        if(type==SendTieBaDataPack::REPLY_FLOOR_TIEBABAIDU){
            /*回复楼中楼*/
            std::pair<QByteArray,QByteArray> post_[]={
                //{"ie","utf-8"},
                {"kw", tbname.toUtf8().toPercentEncoding()},
                {"fid",fid },/*fid is a num*/
                {"tid",_tid}, /*发帖tid为0*/
                {"vcode_md5", vc.id },/*验证码*/
                {"floor_num",_floor_num},/*发帖floor_num为0*/
                {"quote_id",_pid},
                {"rich_text","1"},
                {"tbs",tbs },
                {"content", data },  /*数据*/
                {"lp_type","0"},
                {"lp_sub_type","0"},
                {"new_vcode","1"},
                {"tag","11"},
                {"repostid",_pid},
                {"anonymous","0"}
                //{"__type__","thread"},
            };
            postdata=toHtmlUrl(postdata,std::begin(post_),std::end(post_));
        }
        else {
            /*发帖或回复*/
            std::pair<QByteArray,QByteArray> post_[]={
                //{"ie","utf-8"},
                {"kw", tbname.toUtf8().toPercentEncoding()},
                {"fid",fid },/*fid is a num*/
                {"tid",_tid}, /*发帖tid为0*/
                {"vcode_md5", vc.id },/*验证码*/
                {"floor_num",_floor_num},/*发帖floor_num为0*/
                {"rich_text","1"},
                {"tbs",tbs },
                {"content", data },  /*数据*/
                {"title"  , ttitle.toUtf8().toPercentEncoding() }, /*标题*/
                {"prefix" ,  "" },
                {"files","%5B%5D"},//[]
                {"mouse_pwd",mouse_pwd_},
                {"mouse_pwd_t",ctime_},
                {"mouse_pwd_isclick","0"},
                //{"__type__","thread"},
            };
            postdata=toHtmlUrl(postdata,std::begin(post_),std::end(post_));
            switch (type) {
                case SendTieBaDataPack::THREAD_TIEBABAIDU: { postdata.append("&__type__=""thread"); } break;
                case SendTieBaDataPack::REPLY_TIEBABAIDU: { postdata.append("&__type__=""reply"); }break;
                case SendTieBaDataPack::REPLY_FLOOR_TIEBABAIDU:break;
                case SendTieBaDataPack::UNKNOW_TIEBABAIDU: throw ArgError("unknow type"); break;
                default:throw ArgError("unknow type");  break;
            }
        }
        /*验证码*/
        if ( vc.ans.isEmpty()==false ) { postdata.append("&vcode="+vc.ans); /*验证码*/ }
    }

    QUrl url_0_;
    //http://tieba.baidu.com/f/commit/post/add
    //http://tieba.baidu.com/f/commit/thread/add
    switch(type){
        case SendTieBaDataPack::THREAD_TIEBABAIDU: { url_0_=QUrl("http://tieba.baidu.com/f/commit/thread/add");} break;
        case SendTieBaDataPack::REPLY_TIEBABAIDU: {url_0_=QUrl("http://tieba.baidu.com/f/commit/post/add"); } break;
        case SendTieBaDataPack::REPLY_FLOOR_TIEBABAIDU:{url_0_=QUrl("http://tieba.baidu.com/f/commit/post/add"); }break;
        case SendTieBaDataPack::UNKNOW_TIEBABAIDU:break;
    }

    QNetworkRequest req( url_0_ );
    {
        static auto * tcodec=QTextCodec::codecForName("gbk");
        QByteArray gbk_tname=tcodec->fromUnicode(tbname ).toPercentEncoding();
        req.setRawHeader("User-Agent", u->getUserAgent().first );
        req.setRawHeader("Host", "tieba.baidu.com");
        req.setRawHeader("Accept", "application/json, text/javascript, */*; q=0.01");
        req.setRawHeader("Accept-Language", "zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3");
        req.setRawHeader("Accept-Encoding", "gzip, deflate");
        req.setRawHeader("Content-Type", "application/x-www-form-urlencoded; charset=UTF-8");
        req.setRawHeader("X-Requested-With", "XMLHttpRequest");
        req.setRawHeader("Pragma", "no-cache");
        req.setRawHeader("Cache-Control", "no-cache");
        req.setRawHeader("Referer", "http://tieba.baidu.com/f?kw="+gbk_tname+"&fr=index");
        req.setHeader(QNetworkRequest::CookieHeader,u->getAllCookies() );
    }

    auto rp = m->post(req,postdata);
    std::shared_ptr< QNetworkReply > r(rp);
    std::weak_ptr< QNetworkReply > wr(r);
    std::weak_ptr< BaiDuNetworkAccessManager > wm(m);
    m->addReply(r);
    auto thisp_ = thisp;
    rp->connect(rp,&QNetworkReply::finished,
        [thisp_ ,wm,wr,fp,fun]() {
        auto w=wm.lock();
        auto r=wr.lock();
        try {
            cct::check_args<ArgError>(w,"endl");
            cct::check_args<ArgError>(r,"endl");
            w->removeReply(r);
            auto thisp = thisp_.lock();
            cct::check_args<ArgError>(thisp,"endl");

            auto data_=gzip::QCompressor::gzipDecompress(r->readAll());
            cct::check_args<ArgError>(!data_.isEmpty(),"endl");

            //qDebug()<<data_;

            {
                std::ofstream ofs( "last_reply_baidutieba.txt" );
                if ( ofs.is_open() ) {ofs.write( data_.constBegin(),data_.size() );}
            }

            QByteArray tid_;
            do{/**/
                QScriptEngine eng;
                auto ans__ = eng.evaluate("jsvalue="+data_);

                if(ans__.isError()){
                    throw ArgError("json error");
                }

                auto no_ = eng.evaluate(u8R"(jsvalue["no"])").toString() ;
                auto err_code_ = eng.evaluate(u8R"(jsvalue["err_code"])").toInt32() ;

                //ok
                if( no_ == "0"){
                    tid_ = eng.evaluate(u8R"(jsvalue["data"]["tid"])").toString().toUtf8();
                    break;
                }

                /*
                {"no":40,"err_code":40,"error":"","data":{"autoMsg":"","fid":2256767,"fname":"\u57ac","tid":0,"is_login":1,"content":"","vcode":{"need_vcode":1,"str_reason":"\u8bf7\u70b9\u51fb\u9a8c\u8bc1\u7801\u5b8c\u6210\u53d1\u8d34","captcha_vcode_str":"captchaservice3263343573514d4c58506d47427467306b4d49594d62306b2f482f533156707a506241615249423739662b326e46342b49714d542b342b6a6352465673794944336a32736e385476345969545a4736792b3352393943676c34686762647730777931772b76782b6459716f50477539343572446b574d6d6c41644b5378544e49345456706f70774b75326b7370476f6b554f546438396d73596d667772753233597776752b6962446255394a62566e4844512f4c356d3855324b75517076527857426e41546b485a4232596a7236514c5548597036614c30684c744e532f37326465434c62616b557955545761722b507a6d4e593037594b4c586a67682f44357a51744f494a6250744e674a6f79774b6b5648314a334d4c50786c744b44444b47484c4e39446c7533473770735077385754574b","captcha_code_type":4,"userstatevcode":0}}}
                */

                //qDebug()<<data_;
                if (1 == eng.evaluate(u8R"(jsvalue["data"]["vcode"]["need_vcode"])").toInt32()) {
                    QString vcdoe=eng.evaluate(u8R"(jsvalue["data"]["vcode"]["captcha_vcode_str"])").toString();
                    if (vcdoe.size()>16) {
                        /*验证码网址*/ /*验证码id*/
                        const QByteArray id__=vcdoe.toUtf8();
                        thisp->vertifyCode("http://tieba.baidu.com/cgi-bin/genimg?"+id__,id__);
                        //throw ArgError(QString::fromUtf8(u8"验证码"));
                    }
                }

                auto i_ = baidutieba_::error_code.find(err_code_);
                if ( i_!=baidutieba_::error_code.end() ) {
                    throw ArgError( QString::fromUtf8(i_->second) );
                }
                else {
                    throw ArgError( QString::fromUtf8(u8"未知错误"+data_));
                }

            }while(0);

            /*完成发帖,返回tid*/
            if (fp) { fp->finished(true,tid_ ); }
            return fun( tid_ ,fp ) ;

        }
        catch (const ArgError & e) {
            if (fp) { fp->finished(false,e.what()); }
        }
    });
}
catch (const ArgError & e) {
    if (fp) { fp->finished(false,e.what()+" "+__func__); }
}
#undef _zfunc

#define _zfunc cct::FunctionType< decltype(&BaiDuTieBaPrivate::send ) >
void BaiDuTieBaPrivate::send(
    _zfunc::_r2 pack,
    _zfunc::_r1 fun,
    _zfunc::_r0 fp
    ) try{

    cct::check_args<ArgError>(pack,"data is null");
    auto & tbname=pack->tbname;
    auto & ttitle=pack->ttitle;
    auto & tdata=pack->content;
    const auto __thisp = thisp.lock() ;

    cct::check_args<ArgError>(
        !tbname.isEmpty(),"tbname is null",
        !ttitle.isEmpty(),"tbname is null",
        fun,"callback is null",
        tdata,"tdata is null",
        !tdata->empty(),"tdata is null",
        __thisp,"thisp is null"
        );

    auto u= baiDuUser;
    cct::check_args<ArgError>(u,"baidu user is null");
    cct::check_args<ArgError>(u->isLogin() ,"baidu user is not login");

    typedef BaiDuFinishedCallBackPointer EP;
    using namespace std;
    BaiDuTieBa::tbs(u,[ fun=move(fun) ,tdata=move(tdata) ,pack,u ](QByteArray tbs_,EP fp) mutable {
        const auto  & tbname=pack->tbname;
        using namespace std;
        pack->tbs=tbs_;

        auto fid_call_back_ = [ fun  ,pack ,tdata ](QByteArray fid,EP fp) mutable{
            try {
                auto thisp=pack->thisp.lock();
                cct::check_args<ArgError>(thisp,"endl");
                pack->fid=fid;
                thisp->localTieBa2BaiDuTieBa(
                    fid,
                    pack->localDir,
                    tdata,
                    [fun ,pack](
                    std::shared_ptr<TieBaFormatData> tdata,
                    EP fp
                    ) {
                    auto thisp=pack->thisp.lock();
                    if (bool(thisp)==false) { if (fp) { fp->finished(false,"endl"); }return; }
                    if (fp->hasError() ) { return; }
                    QByteArray about_post_ = genPostData(pack->type, tdata );
                    if (about_post_.isEmpty()) { if (fp) { fp->finished(false,"post data is null"); }return; }
                    thisp->sendDetail(pack->tbname,pack->ttitle,about_post_,
                        pack->tbs,pack->vcode,pack->fid,fun ,fp);

                },
                    fp);

            }
            catch (const ArgError & e) {
                if (fp) { fp->finished(false,e.what()); }
            }
        };

        BaiDuTieBa::fid(u,tbname, std::move(fid_call_back_) ,fp );

    },pack );

}
catch (const ArgError & e) {
    if (fp) { fp->finished(false,e.what()+ " " +__func__); }
}
#undef _zfunc

void BaiDuTieBaPrivate::sendData(
    QString tbname,
    QString tbtitle,
    QString tlocal,
    QString tbdata,
    BaiDuVertifyCode vc) {

    auto item = TieBaFormatData::instance();
    QTextStream stream( &tbdata );
    item->read( stream );

    typedef BaiDuFinishedCallBackPointer EP;
    auto pack=std::make_shared< SendTieBaDataPack >();
    pack->thisp=this->thisp;
    pack->content=item;
    pack->tbname=tbname;
    pack->ttitle=tbtitle;
    pack->localDir=tlocal;
    pack->vcode=vc;

    connect(pack.get(),&SendTieBaDataPack::sendFinished,
        this,&BaiDuTieBaPrivate::sendDataFinished
        );

    send( pack ,[pack](QByteArray tid_  ,EP){
        qDebug()<<tid_;
    }, pack );

}

namespace {
//PageData.thread = {        author: "xiao而部雨",        thread_id:4193212507,        title: "请问吧里的大神，明朝汉服抄袭韩服吗", reply_num:5, thread_type: "0",
const char * gen_thread_data_(
    const char * begin_,const char * end_,
    QString & author,
    QString & title ,
    QString & reply_num
    ) {

    std::cmatch rans;
    const char * pos_=begin_;
    const static std::regex begin_reg(u8R"(PageData[.]thread)");
    const static std::regex author_reg(u8R"_(author[ ]*:[ ]*"(.*?)",)_");
    const static std::regex title_reg(u8R"_(title[ ]*:[ ]*"(.*?)",)_");
    const static std::regex reply_num_reg(u8R"_(reply_num[ ]*:[ ]*([0-9]*?),)_");

    if (std::regex_search(pos_,end_,rans,begin_reg)) {
        pos_=rans[0].second;
    }
    else { throw ArgError("can not find PageData.thread"); }

    /*这个参数是无用的*/
    if (std::regex_search(pos_,end_,rans,author_reg)) {
        pos_=rans[0].second; author=QString::fromUtf8(rans[1].first,rans[1].length());
    }
    else { throw ArgError("can not find author"); }

    if (std::regex_search(pos_,end_,rans,title_reg)) {
        pos_=rans[0].second;title=QString::fromUtf8(rans[1].first,rans[1].length());
    }
    else { throw ArgError("can not find title"); }

    if (std::regex_search(pos_,end_,rans,reply_num_reg)) {
        pos_=rans[0].second;reply_num=QString::fromUtf8(rans[1].first,rans[1].length());
    }
    else { throw ArgError("can not find reply_num"); }
    return pos_;
}
}

void BaiDuTieBaPrivate::_private_postData(std::shared_ptr<SendTieBaDataPack> pack) {
    typedef BaiDuFinishedCallBackPointer EP;
    connect(pack.get(),&SendTieBaDataPack::sendFinished,
        this,&BaiDuTieBaPrivate::sendDataFinished
        );

    try {
        /*下载网页*/
        auto thisPointer=thisp.lock();
        cct::check_args<ArgError>(thisPointer,"thisPointer");
        auto u=thisPointer->baiDuUser;
        cct::check_args<ArgError>(u,"user",u->isLogin(),"user login");
        auto m=u->getManager();
        cct::check_args<ArgError>(m,"manager");
        const auto & tid=pack->tid;
        QUrl url_( QString("http://tieba.baidu.com/p/")+tid );
        QNetworkRequest req(url_);/*req.setRawHeader("User-Agent",u->getUserAgent().first);*/
                                  /*固定下载桌面版本的网页进行分析*/
        req.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko");
        req.setRawHeader("Accept-Encoding", "gzip, deflate");
        req.setRawHeader("Connection", "keep-alive");
        req.setRawHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
        req.setHeader(QNetworkRequest::CookieHeader,u->getAllCookies());

        auto r=m->get(req);

        std::shared_ptr<QNetworkReply> rpl(r,[](QNetworkReply * d) {d->deleteLater(); });
        std::weak_ptr<QNetworkReply> wr(rpl);

        m->addReply(rpl);
        std::weak_ptr< BaiDuNetworkAccessManager > wm(m);

        connect(r,&QNetworkReply::finished,
            [pack,wm,wr]() {
            auto m=wm.lock(); auto r=wr.lock();
            try {
                cct::check_args<ArgError>(m,"manager",r,"reply");
                m->removeReply(r);
                auto thisPointer=pack->thisp.lock();
                cct::check_args<ArgError>(thisPointer,"endl..");
                /*******************************************************/
                const auto data_ = gzip::QCompressor::gzipDecompress( r->readAll() );
                cct::check_args<ArgError>(!data_.isEmpty(),"can not fid the tid");

                {
                    QString author,title,reply_num;
                    gen_thread_data_(
                        data_.constBegin(),data_.constEnd(),
                        author,title,reply_num
                        );
                    pack->ttitle=title;
                    pack->floor_num=reply_num.toUtf8();
                }

                //"tieba.baidu.com/f?kw=%E8%9B%8A%E7%9C%9F%E4%BA%BA&ie=utf-8"
                {//tbname
                    const char * begin=data_.constBegin();
                    const char * end=data_.constEnd();
                    const static std::regex reg(u8R"(tieba[.]baidu[.]com/f[?]kw=)");
                    QByteArray ans;
                    std::cmatch rans;
                    if ( std::regex_search(begin,end,rans,reg) ) {
                        begin=rans[0].second;
                        for (;begin!=end;++begin) {
                            if (*begin=='&') { break; } ans.push_back(*begin);
                        }
                        pack->tbname=QString::fromUtf8( ans.fromPercentEncoding( ans ) );
                    }
                    else {
                        throw ArgError("tbname:");
                    }

                }

                {/*fid*/
                    const char * begin=data_.constBegin();
                    const char * end=data_.constEnd();
                    std::cmatch match;
                    if (std::regex_search(begin,end,match,std::regex("PageData.forum"))) {
                        begin=match[0].second;
                        if (std::regex_search(begin,end,match,std::regex(R"(['"]?id['"]?[ ]*:)"))) {
                            begin=match[0].second;
                            QString ans;
                            for (; begin!=end; ++begin) {
                                if ((*begin>='0')&&(*begin<='9')) {  break;  }
                            }
                            for (; begin!=end; ++begin) {
                                if ((*begin>='0')&&(*begin<='9')) {  ans.push_back(*begin); continue;  }break;
                            }

                            //
                            pack->fid=ans.toUtf8();

                        }
                        else {  throw ArgError("id:");  }
                    }
                    else {
                        throw ArgError("PageData.forum");
                    }
                }

                auto fileb=data_.constBegin(); auto filee=data_.constEnd();
                //var PageData
                //"tbs": "f5fa73afe67b79221449061609",
                {
                    const static std::regex reg_pagedata(u8R"(var PageData)");std::cmatch pagedata_ans;
                    if ( std::regex_search(fileb,filee,pagedata_ans,reg_pagedata) ) {
                        auto b=pagedata_ans[0].second;
                        const static std::regex tbs_reg(u8R"(["']tbs["'][ ]*:)");
                        if(std::regex_search( b,filee,pagedata_ans,tbs_reg)) {
                            b=pagedata_ans[0].second;
                            const static std::set<char> char_set{
                                'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                                '1','2','3','4','5','6','7','8','9','0'
                            };
                            auto & tbs=pack->tbs; tbs.clear();
                            for (;b!=filee;++b) {
                                if (*b==',') { break; }
                                if (char_set.count(*b)>0) { tbs.push_back(*b); }
                            }
                            fileb=b;
                        }
                        else {
                            throw ArgError(u8R"(can not find 'tbs')");
                        }
                    }
                    else {
                        throw ArgError(u8R"(can not find 'var PageData')");
                    }
                }

                //style="margin-right:3px">74</span>回复贴，
                /* {
                const static std::regex reg(u8R"(([0-9]*)</span>回复贴)");
                std::cmatch pagedata_ans;
                if (std::regex_search(fileb,filee,pagedata_ans,reg)) {
                if (pagedata_ans.size()<2) { throw ArgError(u8R"(can not find floor num )"); }
                pack->floor_num = QByteArray(pagedata_ans[1].first,pagedata_ans[1].length());
                }
                else {
                throw ArgError(u8R"(can not find floor num )");
                }
                }*/
                /*******************************************************/
                thisPointer->post(pack,[pack](QByteArray tid_,EP) {
                    qDebug()<<tid_;
                },pack);
            }
            catch (const ArgError & e) {
                pack->finished(false,e.what());
            }
        });
    }
    catch (const ArgError & e) {
        pack->finished(false,e.what());
    }


}

void BaiDuTieBaPrivate::postData(
    QString tid,
    QString tlocal,
    QString tbdata,
    BaiDuVertifyCode vc) {

    auto item=TieBaFormatData::instance();
    {
        QTextStream stream(&tbdata);
        item->read(stream);
    }

    auto pack=std::make_shared< SendTieBaDataPack >();
    
    {//set pack data
        pack->thisp=this->thisp;
        pack->content=item;
        pack->tid=tid.toUtf8().trimmed();
        pack->localDir=tlocal;
        pack->vcode=vc;
        pack->type= SendTieBaDataPack::Type::REPLY_TIEBABAIDU ;
    }

    _private_postData( pack );

}

//tid floor_num
#define _zfunc cct::FunctionType< decltype(&BaiDuTieBaPrivate::post ) >
void BaiDuTieBaPrivate::post(
    _zfunc::_r2 pack,
    _zfunc::_r1 fun,
    _zfunc::_r0 fp
    ) try{

    cct::check_args<ArgError>(pack,"data is null");
    auto & tbname=pack->tbname;
    auto & ttitle=pack->ttitle;
    auto & tdata=pack->content;

    const auto __thisp=thisp.lock();

    cct::check_args<ArgError>(
        !tbname.isEmpty(),"tbname is null",
        !ttitle.isEmpty(),"tbname is null",
        fun,"callback is null",
        tdata,"tdata is null",
        !tdata->empty(),"tdata is null",
        __thisp,"thisp is null"
        );

    auto u=baiDuUser;
    cct::check_args<ArgError>(u,"baidu user is null");
    cct::check_args<ArgError>(u->isLogin(),"baidu user is not login");

    typedef BaiDuFinishedCallBackPointer EP;
    using namespace std;


    auto fid_call_back_=[fun,pack,tdata](QByteArray fid,EP fp) mutable {
        try {
            auto thisp=pack->thisp.lock();
            cct::check_args<ArgError>(thisp,"endl");
            pack->fid=fid;
            thisp->localTieBa2BaiDuTieBa(
                fid,
                pack->localDir,
                tdata,
                [fun,pack](
                std::shared_ptr<TieBaFormatData> tdata,
                EP fp
                ) {
                auto thisp=pack->thisp.lock();
                if (bool(thisp)==false) { if (fp) { fp->finished(false,"endl"); }return; }
                if (fp->hasError()) { return; }
                QByteArray about_post_=genPostData(pack->type, tdata);
                if (about_post_.isEmpty()) { if (fp) { fp->finished(false,"post data is null"); }return; }
                thisp->sendDetail(
                    pack->type ,pack->tbname, pack->ttitle,
                    about_post_, pack->tbs,pack->vcode, 
                    pack->fid, pack->tid,pack->floor_num,
                    pack->pid,fun, fp);
            },
                fp);

        }
        catch (const ArgError & e) {
            if (fp) { fp->finished(false,e.what()); }
        }
    };

    BaiDuTieBa::fid(u,tbname,std::move(fid_call_back_),fp);


}
catch (const ArgError & e) {
    if (fp) { fp->finished(false,e.what()+ " " +__func__); }
}
#undef _zfunc

void BaiDuTieBaPrivate::sign(QString tbname )try {
    tbname=tbname.trimmed().toLower();
    cct::check_args<ArgError>(!tbname.isEmpty(),"tbname is null");
    auto u=this->baiDuUser;
    cct::check_args<ArgError>(u,"baidu user is null");
    cct::check_args<ArgError>(u->isLogin(),"baidu user is not login");
    //不判断是否签到和是否签到成功

    BaiDuFinishedCallBackPointer null_;
    std::weak_ptr<BaiDuUser> wu(u);
    BaiDuTieBa::tbs(u,[ wu,tbname ](QByteArray tbs_, BaiDuFinishedCallBackPointer ) {
        auto u=wu.lock();
        try {
            cct::check_args<ArgError>(u,"user is null");
            auto m = u->getManager();
            cct::check_args<ArgError>(m,"manager is null");
            const static QUrl url_("http://tieba.baidu.com/sign/add");
            QNetworkRequest req_(url_);
            /*set req*/
            {
                req_.setRawHeader("User-Agent", u->getUserAgent().first );
                req_.setRawHeader("Host", "tieba.baidu.com");
                req_.setRawHeader("Accept", "application/json, text/javascript, */*; q=0.01");
                req_.setRawHeader("Accept-Language", "zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3");
                req_.setRawHeader("Accept-Encoding", "gzip, deflate");
                req_.setRawHeader("Content-Type", "application/x-www-form-urlencoded; charset=UTF-8");
                req_.setRawHeader("X-Requested-With", "XMLHttpRequest");
                req_.setRawHeader("Pragma", "no-cache");
                req_.setRawHeader("Cache-Control", "no-cache");
                req_.setHeader(QNetworkRequest::CookieHeader, u->getAllCookies() );
            }
            QByteArray post_data_;
            /*set post data*/
            {
                post_data_="ie=utf-8";
                auto tbn=tbname.toUtf8().toPercentEncoding();
                post_data_.append("&kw="+tbn );
                post_data_.append("&tbs="+tbs_);
            }
            auto r = m->post(req_,post_data_);
            std::weak_ptr<BaiDuNetworkAccessManager> wm(m);
            std::shared_ptr<QNetworkReply> rep(r,[](auto d) {d->deleteLater(); });
            std::weak_ptr<QNetworkReply> wr(rep);
            m->addReply(rep);
            r->connect(r,&QNetworkReply::finished,
                [wr,wm]() {
                auto r=wr.lock(); auto m=wm.lock();
                try {
                    cct::check_args<ArgError>(r,"reply is null",m,"manager is null");
                    m->removeReply(r);
                    //auto ans = gzip::QCompressor::gzipDecompress( r->readAll() );
                    //qDebug()<<ans;
                }
                catch (const ArgError & e) {
                    qDebug()<<e.what();
                }
            });
        }
        catch (const ArgError & e) {
            qDebug()<<e.what();
        }
    },null_);

}
catch (const ArgError & e) {
    qDebug()<<__func__<<e.what();
}

void BaiDuTieBaPrivate::postUnderFloorData(
    QString tid ,
    QString pid ,
    QString tlocal ,
    QString tbdata ,
    BaiDuVertifyCode vc ) {

    auto item=TieBaFormatData::instance();
    {
        QTextStream stream(&tbdata);
        item->read(stream);
    }

    auto pack=std::make_shared< SendTieBaDataPack >();

    {//set pack data
        pack->thisp=this->thisp;
        pack->content=item;
        pack->tid=tid.toUtf8().trimmed();
        pack->localDir=tlocal;
        pack->vcode=vc;
        pack->pid=pid.toUtf8().trimmed();
        pack->type= SendTieBaDataPack::Type::REPLY_FLOOR_TIEBABAIDU ;
    }

    _private_postData( pack );

}


/*
 * endl of the file
*/
