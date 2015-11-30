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
#include "BaiDuNetworkAccessManager.hpp"
#include "../BaiDuUser.hpp"


class NGZBAIDUSHARED_EXPORT BaiDuUserLoginNetworkAccessManager :
        public BaiDuNetworkAccessManager{
    Q_OBJECT
private:
    
public:
    BaiDuUserLoginNetworkAccessManager( QObject * ) ;     
    ~BaiDuUserLoginNetworkAccessManager() { }
};

class NGZBAIDUSHARED_EXPORT BaiDuUserLoginPack :
        public QObject,
        public BaiDuFinishedCallBack {
    Q_OBJECT
public:
    
    bool isValueSet=false;
    cct::SharedFromSuper< BaiDuUser::BaiDuUserPrivate > baiduUserPrivate  ;
    QString userNameBase;/*用户名原始字符串*/
    QString passWordBase;/*密码原始字符串*/
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
    bool isPhone{false};
    std::atomic< bool > isOnDestory{ false };

    bool onDestory() const volatile { return isOnDestory.load(); }

    BaiDuUserPrivate( std::shared_ptr<BaiDuUserPrivate> );
    ~BaiDuUserPrivate( );

    void setLogInPackData( BaiDuUserLoginPack * );
    void connectLoginPack( BaiDuUserLoginPack *);

    void setChildrenPointer(QObject *  );
    QVariant getAllCookies()const;

public:
    //update gid
    void upDateGID(  BaiDuFinishedCallBackPointer );

    // ask  http://www.baidu.com  then set cookie
    void getBaiduCookie( std::function<void(cct::Map< QByteArray, QNetworkCookie>, BaiDuFinishedCallBackPointer)> ,BaiDuFinishedCallBackPointer );

    //token
    void getBaiduToken( 
        std::function< void(QByteArray,BaiDuFinishedCallBackPointer) >,
        BaiDuFinishedCallBackPointer );

    //rsa key
    void getRSAKey(
        std::function< void(QByteArray/*rsa key*/,QByteArray/*pub key*/,BaiDuFinishedCallBackPointer) >,
        BaiDuFinishedCallBackPointer
        );

    //
    static void encryptRSA(
        QByteArray public_key,
        QByteArray pass_Word,
        std::function< void(QByteArray ,BaiDuFinishedCallBackPointer) >,
        BaiDuFinishedCallBackPointer
        );

    //void 
    void postLogin(
        QByteArray user_name_,
        QByteArray rsa_key_,
        QByteArray enc_password_,
        QByteArray token_,
        std::function< void( std::shared_ptr< std::weak_ptr<QNetworkReply> >  ,BaiDuFinishedCallBackPointer) >,
        BaiDuFinishedCallBackPointer
        );

    //
    void onLoginFinished(
        std::shared_ptr< std::weak_ptr<QNetworkReply> >  ,
        std::function< void(BaiDuVertifyCode,BaiDuFinishedCallBackPointer) > ,/*验证码回调*/
        BaiDuFinishedCallBackPointer                                      /*结果回调,true false*/
        );

private:

signals:
    void loginFinished( bool,QString );
    void setVertifyCode(QByteArray url_ ,QByteArray id_);

public slots:
    void login(
            QString userName,
            QString passWord,
            BaiDuVertifyCode vertifyCode
            );

};

#endif
