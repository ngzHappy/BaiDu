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

namespace {

    QString operator""_qutf8(const char * d, std::size_t n) {
        return QString::fromUtf8(d, n);
    }

}

BaiDuUserLoginNetworkAccessManager::BaiDuUserLoginNetworkAccessManager( QObject * o)
    :QNetworkAccessManager(o){}

BaiDuUser::BaiDuUserPrivate::BaiDuUserPrivate(std::shared_ptr<BaiDuUserPrivate> o):
thisPointer(o){
    this->__all__bits__ = char(0);
    manager = new BaiDuUserLoginNetworkAccessManager(nullptr ) ;
}

BaiDuUserLoginPack::BaiDuUserLoginPack(QObject * o)
    :QObject(o){
}

BaiDuUserLoginPack::~BaiDuUserLoginPack(){

}

BaiDuUser::BaiDuUserPrivate::~BaiDuUserPrivate( ){
   
    isOnDestory.store( true );
    {
        //clear all temp objects
        std::unique_lock< std::recursive_mutex > __( this->tempObjectsMutex );
        tempObjects=nullptr;
    }
    delete manager;
    manager=nullptr;
}

void BaiDuUser::BaiDuUserPrivate::setLogInPackData( BaiDuUserLoginPack * p ){
    
    p->baiduUserPrivate = thisPointer;
    p->userName = p->userNameBase.toUtf8().toPercentEncoding();
}

void BaiDuUserLoginPack::finished(bool v, QString r){
    //TODO : log in finished
    hasError = !v;
    emit loginFinished(v,r);
}

void BaiDuUser::BaiDuUserPrivate::connectLoginPack(BaiDuUserLoginPack * p){
     
    connect(p,&BaiDuUserLoginPack::loginFinished,this,&BaiDuUser::BaiDuUserPrivate::loginFinished );
}

void BaiDuUser::BaiDuUserPrivate::upDateGID(BaiDuFinishedCallBackPointer fp) {
    
    auto & gid__=this->gid;
    BaiDuUser::gid([ &gid__ ](auto ans, auto ) { gid__=ans; }, fp);
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
        loginPack->finished(false, QString("the ")+"user"+" has login!!");
        return;
    }

    if (this->isLogInIng) {//对象正在登录则退出
        loginPack->finished(false, QString("the ")+"user"+" is logining!!");
        return;
    }

    //进一步设置数据
    loginPack->vertifyCode=vertifyCode_;
    setLogInPackData(loginPack);

    //更新gid
    upDateGID(pack);
    if (pack->hasError) { return; }

    typedef BaiDuFinishedCallBackPointer BCP_;

    //TODO : login
//获得baidu cookie
    getBaiduCookie([this, pack](
        cct::Map<QByteArray, QNetworkCookie> cookies,
        BCP_ errorFunction) mutable {

        auto * loginPack_=pack.get();
        auto pack__ = loginPack_->baiduUserPrivate.lock();
        
        if (bool(pack__) == false) {
            if (errorFunction) { errorFunction->finished(false,"endl"); }
            return;
        }

        pack__->cookies=cookies;

        //获得baidu token
        this->getBaiduToken([this, pack](
            QByteArray token_,
            BCP_ errorFunction) mutable {
            this->token=token_;

            //获得rsa key
            getRSAKey(
                [this, pack](
                QByteArray rsa_key_,
                QByteArray public_key_,
                BCP_ errorFunction) {

                pack->publicKey=public_key_;
                this->rsaKey=rsa_key_;

                //加密
                encryptRSA(
                    pack->publicKey,
                    pack->passWordBase.toUtf8(),
                    [this, pack](
                    QByteArray enc_password_,
                    BCP_ errorFunction
                    ) mutable {
                    

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
        std::function< void(QByteArray,BaiDuFinishedCallBackPointer) > fun ,
        BaiDuFinishedCallBackPointer fp ){
    if( bool(fun) == false) {
        if(fp){ fp->finished(false,"call back is null " + QString( __func__ )); }
        return ;
    }

    QByteArray ans{35,Qt::Uninitialized};

    constexpr const static char toHex0[] = {
        '0','1','2','3','4','5','6','7',
        '8','9','A','B','C','D','E','F',
    };

    constexpr const static char toHex1[] = {
        '8','9','A','B','C','D','E','F',
        '8','9','A','B','C','D','E','F',
    };

    class Array{
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
    }{}
    };

    new(ans.data()) Array;
    fun( std::move( ans ) ,fp);
}

void BaiDuUser::currentTimer(
        std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>  fun ,
        BaiDuFinishedCallBackPointer fp ){
    if( bool(fun) == false) {
        if(fp){ fp->finished(false,"call back is null " +QString( __func__ )); }
        return;
    }
    fun( QByteArray::number( QDateTime::currentMSecsSinceEpoch() ) ,fp);
}

BaiDuUser::~BaiDuUser(){
    
    const auto __copy=thisp;
    if (thisp) {
        thisp->isOnDestory.store(true );
        thisp.reset();
    }

}

void BaiDuUser::BaiDuUserPrivate::getBaiduCookie(
        std::function< void(cct::Map<QByteArray, QNetworkCookie>, BaiDuFinishedCallBackPointer) > fun ,
        BaiDuFinishedCallBackPointer fp){
    
    if( bool(fun) == false) {
        if(fp){ fp->finished(false,"call back is null " +QString( __func__ )); }
        return;
    }

    //ask
    const QUrl url("http://www.baidu.com");
    QNetworkRequest req(url);
    req.setRawHeader("User-Agent", this->userAgent);
    auto  reply__ = std::shared_ptr<QNetworkReply>( manager->get( req ) ,
        [](QNetworkReply * d) {d->deleteLater(); });
    std::weak_ptr<QNetworkReply> reply_(reply__);
    manager->addReply( reply__ );
    auto thisPointer_=thisPointer;

    //获得返回值
    connect( reply__.get(),&QNetworkReply::finished,
            this,[ thisPointer_ , fun , fp , reply_ ](){

        auto thisPointer=thisPointer_.lock();
        auto reply=reply_.lock();

        if ( (bool(thisPointer)==false)||(bool(reply)==false) ) {
            if(fp){ fp->finished(false,"endl"); }
            return;
        }

        thisPointer->manager->removeReply( reply );

         if (reply->error() != QNetworkReply::NoError) {
             if(fp){ fp->finished(false,"reply error"); }
             return;
         }

        auto * manager_ = thisPointer->manager;
        auto allCookies = manager_->cookieJar()->cookiesForUrl(reply->url());            

        for (const auto & i : reply->rawHeaderPairs()) {
            if (i.first == "Set-Cookie") {
                const auto ak_ = QNetworkCookie::parseCookies(i.second);
                for (const auto & j : ak_) {
                    allCookies.push_back(j);
                }
            }
        }

        std::map<QByteArray, QNetworkCookie> ans ;
        for (const auto & i : allCookies) {
            ans.insert({ i.name() ,i });
        }

        if (ans.find("BAIDUID") == ans.end()) {
            if(fp){ fp->finished(false,"can not find BAIDUID"); }
            return;
        }

        fun(std::move(ans) , fp);
    });

}

namespace{

    template<typename IB, typename IE>
    QByteArray toHtmlUrl(QByteArray ans, IB b, IE e) {
        for (; b != e; ++b) {
            const auto & first_ = b->first;
            const auto & second_ = b->second;
            ans.append("&" + first_ + "=" + second_);
        }
        return std::move(ans);
    }

}

QVariant BaiDuUser::BaiDuUserPrivate::getAllCookies()const {
     
    QList< QNetworkCookie > ans;
    if ( cookies ) {
        for (const auto & i:*cookies) {
            ans.push_back(i.second);
        }
    }
    return std::move( QVariant::fromValue( std::move( ans ) ) );
}

//userAgent
//cookies
void BaiDuUser::BaiDuUserPrivate::getBaiduToken(
    std::function<void(QByteArray, BaiDuFinishedCallBackPointer)> fun,
    BaiDuFinishedCallBackPointer fp) {
    
    if( bool(fun) == false) {
        if(fp){ fp->finished(false,"call back is null " +QString( __func__ )); }
        return;
    }

    /* 发送接下来的请求 */
    QUrl rURL;
    {
        const static QByteArray url_0("https://passport.baidu.com/v2/api/?getapi");
        QByteArray ctt;
        BaiDuUser::currentTimer([&ctt](auto ans, auto) {ctt=ans; }, fp);
        if (fp) { if (fp->hasError) { return; } }

        std::pair< const QByteArray, const QByteArray > urlData[]{
            { "tpl","mn"}                   ,
            { "apiver","v3" }               ,
            { "tt",ctt }        ,
            { "class","login" }             ,
            { "gid",this->gid }             ,
            { "logintype","dialogLogin" }   ,
            { "callback","bd__cbs__89tioq" },
        };

        auto url__ = toHtmlUrl(url_0, std::begin(urlData), std::end(urlData));
        rURL.setUrl(url__);
    }

    QNetworkRequest req(rURL);
    req.setRawHeader("User-Agent", this->userAgent );
    req.setHeader(QNetworkRequest::CookieHeader, getAllCookies() );

    // 
    auto replyNext_ = std::shared_ptr<QNetworkReply>( manager->get(req),
        [](QNetworkReply * d) { d->deleteLater(); }
        );

    manager->addReply( replyNext_ ); 
    std::weak_ptr<QNetworkReply> replyNext( replyNext_ );
    auto thisPointer_=thisPointer;

    //读取返回值
    connect( replyNext_.get(),&QNetworkReply::finished,
        this, [replyNext,thisPointer_,fp,fun]() mutable{
        auto reply_=replyNext.lock();
        auto thisPointer=thisPointer_.lock();

        if ( bool(reply_)==false ) { 
            if ( fp ) { fp->finished(false,"null""endl"); }
            return;
        }

        if ( bool(thisPointer)==false ) { 
            if ( fp ) { fp->finished(false,"null""endl"); }
            return;
        }

        //delete
        thisPointer->manager->removeReply( reply_ );

        auto json = reply_->readAll();            

        if (json.isEmpty()) {
            if ( fp ) { fp->finished(false,"null""BaiDuUser::BaiDuUserPrivate::getBaiduToken");}
            return;
        }

        json = json.mid(json.indexOf("(") + 1);
        json.resize(json.size() - 1);

        QScriptEngine eng;
        eng.evaluate("var bd__cbs__89tioq = " + json);
        auto error = eng.evaluate(u8R"(bd__cbs__89tioq["errInfo"]["no"])").toString();
        auto token = eng.evaluate(u8R"(bd__cbs__89tioq["data"]["token"])").toString();

        if (error != "0") {
            if (fp) { fp->finished(false,"reply error " +QString(__func__) ); }
            return;
        }

        //执行回调
        fun( token.toUtf8() ,fp );

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
        if (fp) { fp->finished(false, "call back is null "+QString(__func__)); }
        return;
    }

    //获得当前时间
    QByteArray ctt;
    BaiDuUser::currentTimer([&ctt](auto ans, auto) {ctt=ans; }, fp);
    if (fp) { if (fp->hasError) { return; } }

    QUrl rURL;
    {
        const static QByteArray url_0("https://passport.baidu.com/v2/getpublickey?token=");
        QByteArray url_1=url_0+this->token;
        std::pair< const QByteArray, const QByteArray > urlData[]{
            { "tpl","mn" }                   ,
            { "apiver","v3" }               ,
            { "tt",ctt }        ,
            { "class","login" }             ,
            { "gid", gid }            ,
            { "callback","bd__cbs__dmwxux" },
        };
        auto url__=toHtmlUrl(url_1, std::begin(urlData), std::end(urlData));
        rURL.setUrl(url__);
    }

    QNetworkRequest req(rURL);
    req.setRawHeader("User-Agent", userAgent);
    req.setRawHeader("Accept-Encoding", "gzip, deflate");

    auto * manager_=manager;
    auto replyNext__=std::shared_ptr<QNetworkReply>(manager_->get(req),
        [](QNetworkReply * d) { d->deleteLater(); }
        );
    manager->addReply( replyNext__ );
    std::weak_ptr<QNetworkReply> replyNext_( replyNext__ );
    // 
    auto thisPointer_=thisPointer;

    connect( replyNext__.get(), &QNetworkReply::finished,
        this, [replyNext_, thisPointer_, fp, fun]() mutable {
        
        auto replyNext = replyNext_.lock();
        auto thisPointer = thisPointer_.lock();

        if ( bool(replyNext )==false ) { 
            if ( fp ) { fp->finished(false,"null""endl"); }
            return;
        }

        if ( bool(thisPointer)==false ) { 
            if ( fp ) { fp->finished(false,"null""endl"); }
            return;
        }

        //delete
        thisPointer->manager->removeReply( replyNext );

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

            if ( error != "0" ) {
                if (fp) {fp->finished(false,"BaiDuLogIn_Step3 : jsom reply error ! "); }
                return;
            }

            auto rsa_key=key.toUtf8();
            fun(rsa_key, publickey_.toUtf8(), fp);
        }

    });

}

//static function
//使用rsa 加密
void BaiDuUser::BaiDuUserPrivate::encryptRSA(
    QByteArray public_key_,
    QByteArray pass_word_,
    cct::Func< void(QByteArray, BaiDuFinishedCallBackPointer) > fun,
    BaiDuFinishedCallBackPointer fp
    ) {
     
    if (bool(fun)==false) {
        if (fp) { fp->finished(false, "call back is null "+QString(__func__)); }
        return;
    }

    {
        QCA::ConvertResult pubkey_isok_;
        QCA::PublicKey pubkey_=
            QCA::RSAPublicKey::fromPEM(public_key_, &pubkey_isok_);

        if (!(QCA::ConvertGood==pubkey_isok_)) {
            if (fp) {fp->finished(false, "qca get public key error!!"); }
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
            if (fp) {fp->finished(false, "BaiDuLogIn_Step3 : rsa encode error ! ");}
            return;
        }

        fun(result.toBase64().toPercentEncoding(), fp);

    }

}

//unused
void BaiDuUser::BaiDuUserPrivate::setChildrenPointer(QObject * o) {
     
    if ( o ) {
        connect(this,&QObject::destroyed,
            o, [o](QObject *) { o->blockSignals(true); o->deleteLater(); }
            );
    }

}

//void 
void  BaiDuUser::BaiDuUserPrivate::postLogin(
    QByteArray user_name_,
    QByteArray rsa_key_,
    QByteArray enc_password_,
    cct::Func< void(QNetworkReply *, BaiDuFinishedCallBackPointer) > fun,
    BaiDuFinishedCallBackPointer fp
    ) {

    if (bool(fun)==false) {
        if (fp) { fp->finished(false, "call back is null "+QString(__func__)); }
        return;
    }



}


