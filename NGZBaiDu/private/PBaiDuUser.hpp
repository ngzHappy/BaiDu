#if !defined(PBAIDUUSER_ngz_HPP)
#define PBAIDUUSER_ngz_HPP

#include <mutex>
#include <atomic>
#include <functional>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkCookie>
#include <Map.hpp>
#include <Set.hpp>
#include <QVariant>
#include <QNetworkReply>
#include <SharedFromSuper.hpp>
#include "../BaiDuUser.hpp"

namespace cct{
template<typename T>
using Func =std::function<T>;
}


class BaiDuUserLoginNetworkAccessManager :
        public QNetworkAccessManager{
    Q_OBJECT
private:
    std::recursive_mutex reply_mutex;
    cct::Set< std::shared_ptr<QNetworkReply> > replys;
public:
    BaiDuUserLoginNetworkAccessManager( QObject * ) ;     

    void addReply( std::shared_ptr<QNetworkReply> r ) {
        {
            std::unique_lock<std::recursive_mutex> __lock(reply_mutex);
            if (replys) {
                replys->insert(r);
            }
        }

    }

    template< typename Tp >
    void removeReply( Tp r ) {
        {
            std::unique_lock<std::recursive_mutex> __lock(reply_mutex);
            if (replys) {
                replys->erase( r );
            }
        }
    }

    ~BaiDuUserLoginNetworkAccessManager() {
        {
            std::unique_lock<std::recursive_mutex> __lock;
            if (replys) {
                replys.reset();//close all replys
            }
        }

    }
};

class NGZBAIDUSHARED_EXPORT BaiDuUserLoginPack :
        public QObject,
        public BaiDuFinishedCallBack {
    Q_OBJECT
public:
    
    bool isValueSet=false;
    cct::SharedFromSuper< BaiDuUser::BaiDuUserPrivate > baiduUserPrivate  ;
    BaiDuVertifyCode vertifyCode;/*验证码*/
    QString userNameBase;/*用户名原始字符串*/
    QString passWordBase;/*密码原始字符串*/
    QByteArray userName;/*用户名*/
    QByteArray passWord;/*密码*/
    QByteArray publicKey;
    
public:
    BaiDuUserLoginPack( QObject * );
    ~BaiDuUserLoginPack();

    void finished(bool, QString) override;
signals:
    void loginFinished( bool ,QString );

private:

};

typedef std::shared_ptr<BaiDuUserLoginPack> BaiDuUserLoginPackPointer;

class NGZBAIDUSHARED_EXPORT BaiDuUser::BaiDuUserPrivate
    :public QObject{
    Q_OBJECT
public:

    union{
        struct{
            bool isLogIn :1 ;
            bool isLogInIng :1 ;
        };
        char __all__bits__;
    };
    
    cct::SharedFromSuper< BaiDuUserPrivate > thisPointer;
    std::shared_ptr< BaiDuUserLoginNetworkAccessManager> manager ;
    QByteArray userAgent;
    cct::Map< QByteArray, QNetworkCookie > cookies;
    std::recursive_mutex tempObjectsMutex;
    cct::Set< std::shared_ptr<QObject> > tempObjects;
    QByteArray gid;
    QByteArray token;
    QByteArray rsaKey;/*rsa -- key*/
    BaiDuVertifyCode vertifyCode;
    std::atomic< bool > isOnDestory{ false };

    bool onDestory() const volatile { return isOnDestory.load(); }

    BaiDuUserPrivate( std::shared_ptr<BaiDuUserPrivate> );
    ~BaiDuUserPrivate( );

    void setLogInPackData( BaiDuUserLoginPack * );
    void connectLoginPack(BaiDuUserLoginPack *);

    void setChildrenPointer(QObject *  );
    QVariant getAllCookies()const;

public:
    //update gid
    void upDateGID(  BaiDuFinishedCallBackPointer );

    // ask  http://www.baidu.com  then set cookie
    void getBaiduCookie( cct::Func<void(cct::Map< QByteArray, QNetworkCookie>, BaiDuFinishedCallBackPointer)> ,BaiDuFinishedCallBackPointer );

    //token
    void getBaiduToken( 
        cct::Func< void(QByteArray,BaiDuFinishedCallBackPointer) >,
        BaiDuFinishedCallBackPointer );

    //rsa key
    void getRSAKey(
        cct::Func< void(QByteArray/*rsa key*/,QByteArray/*pub key*/,BaiDuFinishedCallBackPointer) >,
        BaiDuFinishedCallBackPointer
        );

    //
    static void encryptRSA(
        QByteArray public_key,
        QByteArray pass_Word,
        cct::Func< void(QByteArray ,BaiDuFinishedCallBackPointer) >,
        BaiDuFinishedCallBackPointer
        );

    //void 
    void postLogin(
        QByteArray user_name_,
        QByteArray rsa_key_,
        QByteArray enc_password_,
        QByteArray token_,
        cct::Func< void( std::shared_ptr< std::weak_ptr<QNetworkReply> >  ,BaiDuFinishedCallBackPointer) >,
        BaiDuFinishedCallBackPointer
        );

    //
    void onLoginFinished(
        std::shared_ptr< std::weak_ptr<QNetworkReply> >  ,
        cct::Func< void(BaiDuVertifyCode,BaiDuFinishedCallBackPointer) > ,/*验证码回调*/
        BaiDuFinishedCallBackPointer                                      /*结果回调,true false*/
        );

private:

signals:
    void loginFinished( bool,QString );
    void setVertifyCode(QByteArray id_,QByteArray url_);
public slots:
    void login(
            QString userName,
            QString passWord,
            BaiDuVertifyCode vertifyCode
            );

};

#endif
