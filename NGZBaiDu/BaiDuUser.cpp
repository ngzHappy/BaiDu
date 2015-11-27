#include "private/PBaiDuUser.hpp"
#include "BaiDuUser.hpp"
#include <QDateTime>
#include <QUrl>
#include <QNetworkCookieJar>

namespace  {

class ObjectDelete{
    QObject * obj ;
public:
    ObjectDelete( decltype(nullptr) ): obj(nullptr) {}
    ObjectDelete():obj(nullptr ){}
    ObjectDelete(QObject * o):obj(o){}
    ~ObjectDelete(){ delete obj;}

    ObjectDelete & operator=(ObjectDelete && o){
        std::swap( this->obj,o.obj );
        return *this;
    }

    ObjectDelete(ObjectDelete && o){
        obj = o.obj;
        o.obj = nullptr;
    }

    ObjectDelete(const ObjectDelete &) =delete;
    ObjectDelete& operator=( ObjectDelete & ) =delete;
};

}

BaiDuUserLoginNetworkAccessManager::BaiDuUserLoginNetworkAccessManager( QObject * o)
    :QNetworkAccessManager(o){}

BaiDuUser::BaiDuUserPrivate::BaiDuUserPrivate(BaiDuUser * s):
    super(s){
    this->__all__bits__ = char(0);
    manager = new BaiDuUserLoginNetworkAccessManager(this);
}

BaiDuUserLoginPack::BaiDuUserLoginPack(QObject * o)
    :QObject(o){
}

BaiDuUserLoginPack::~BaiDuUserLoginPack(){

}

BaiDuUser::BaiDuUserPrivate::~BaiDuUserPrivate( ){

}

void BaiDuUser::BaiDuUserPrivate::setLogInPackData( BaiDuUserLoginPack * p ){
    p->baiduUser = super ;
    p->baiduUserPrivate = this;
    p->userName = p->userNameBase.toUtf8().toPercentEncoding();
}

void BaiDuUserLoginPack::finished(bool v, QString r){
    loginFinished(v,r);
}

void BaiDuUser::BaiDuUserPrivate::connectLoginPack(BaiDuUserLoginPack * p){
    connect(p,&BaiDuUserLoginPack::loginFinished,this,&BaiDuUser::BaiDuUserPrivate::loginFinished );
}

void BaiDuUser::BaiDuUserPrivate::login(
        QString userName,
        QString passWord,
        BaiDuVertifyCode vertifyCode_
        ){

    auto * loginPack =new BaiDuUserLoginPack(this);
    BaiDuUserLoginPackPointer pack( loginPack );

    //设置基本数据
    loginPack->userNameBase = userName;
    loginPack->passWordBase = passWord;

    //连接信号槽
    connectLoginPack(loginPack);

    //进行状态检查
    if(this->isLogIn){//对象已经登录则退出
        loginPack->finished(false,QString("the ") + "user" +  " has login!!");
        return ;
    }

    if(this->isLogInIng){//对象正在登录则退出
        loginPack->finished(false,QString("the ") + "user" +  " is logining!!");
        return ;
    }

    //进一步设置数据
    loginPack->vertifyCode = vertifyCode_;
    setLogInPackData(loginPack);

    //TODO : login
//获得baidu cookie
    getBaiduCookie( [pack]( auto cookies ,auto errorFunction ) mutable {
        auto * loginPack_ = pack.get();
        loginPack_->baiduUserPrivate->cookies=std::move(cookies);

    },
    pack
    );

}

BaiDuUser::BaiDuUser( QObject * o)
    :QObject(o){

    thisp = new BaiDuUserPrivate(this);

    connect(this,&BaiDuUser::login,thisp,&BaiDuUser::BaiDuUserPrivate::login );
    connect(thisp,&BaiDuUser::BaiDuUserPrivate::loginFinished,this,&BaiDuUser::loginFinished);
}

void BaiDuUser::gid(
        std::function< void(QByteArray,BaiDuFinishedCallBackPointer) > fun,
        BaiDuFinishedCallBackPointer fp ){
    if( bool(fun) == false) {
        if(fp){ fp->finished(false,"call back is null " +QString( __func__ )); }
        return;
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
    delete thisp;
}

void BaiDuUser::BaiDuUserPrivate::getBaiduCookie(
        std::function< void(std::map<QByteArray, QNetworkCookie>, BaiDuFinishedCallBackPointer) > fun ,
        BaiDuFinishedCallBackPointer fp){

    if( bool(fun) == false) {
        if(fp){ fp->finished(false,"call back is null " +QString( __func__ )); }
        return;
    }

    //ask
    const QUrl url("http://www.baidu.com");
    QNetworkRequest req(url);
    req.setRawHeader("User-Agent", this->userAgent);
    auto * reply = manager->get( req );

    //设置reply生命周期
    connect(this,&QObject::destroyed,reply,[reply](QObject *){
        reply->blockSignals(true);
        reply->deleteLater();
    });

    //获得返回值
    connect(reply,&QNetworkReply::finished,
            this,[this,fun,fp,reply](){
        ObjectDelete _dr( reply );

         if (reply->error() != QNetworkReply::NoError) {
             if(fp){
                 fp->finished(false,"reply error");
                 return;
             }
         }

        auto * manager_ = manager;
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
            if(fp){
                fp->finished(false,"can not find BAIDUID");
            }
            return;
        }

        fun(std::move(ans) , fp);
    });

}

void getBaiduToken(
    std::function<void(QByteArray, BaiDuFinishedCallBackPointer)> fun,
    BaiDuFinishedCallBackPointer fp) {

    if( bool(fun) == false) {
        if(fp){ fp->finished(false,"call back is null " +QString( __func__ )); }
        return;
    }



}
