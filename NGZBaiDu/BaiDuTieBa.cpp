#include "private/PBaiduTieBa.hpp"
#include "BaiDuTieBa.hpp"
#include <FunctionType.hpp>
#include <CheckArgs.hpp>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkCookieJar>
#include <QScriptEngine>

namespace {

QString operator""_qutf8(const char * d,std::size_t n) {
    return QString::fromUtf8(d,n);
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

}

std::shared_ptr<BaiDuUser> BaiDuTieBa::getBaiDuUser()const {
    return thisp->baiDuUser;
}

void BaiDuTieBa::setBaiDuUser(std::shared_ptr<BaiDuUser> u) {
    if (u) { if ( u->isLogin() ) { thisp->baiDuUser=u; } }
    else { thisp->baiDuUser.reset(); }
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

    QNetworkRequest req(QUrl("http://tieba.baidu.com/dc/common/imgtbs"));
    req.setRawHeader("User-Agent", u_->getUserAgent().first );
    req.setHeader(QNetworkRequest::CookieHeader, u_->getAllCookies() );

    

}catch (const ArgError & e) {if (fp) { fp->finished(false,e.what()+" "+__func__ ); }}
#undef _zfunc

/*
 * endl of the file
*/
