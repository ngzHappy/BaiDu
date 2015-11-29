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
            const auto __replys{ replys };
            if (replys) {
                std::unique_lock<std::recursive_mutex> __lock(reply_mutex);
                replys->insert(r);
            }
        }

    }

    void removeReply( std::shared_ptr<QNetworkReply> r ) {
        {
            const auto __replys{ replys };
            if (replys) {
                std::unique_lock<std::recursive_mutex> __lock(reply_mutex);
                replys->erase(r);
            }
        }
    }

    ~BaiDuUserLoginNetworkAccessManager() {
        {
            const auto __replys{ replys };
            if (replys) {
                std::unique_lock<std::recursive_mutex> __lock;
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
    
    std::weak_ptr< BaiDuUserPrivate > thisPointer;
    BaiDuUserLoginNetworkAccessManager * manager ;
    QByteArray userAgent;
    cct::Map< QByteArray, QNetworkCookie > cookies;
    std::recursive_mutex tempObjectsMutex;
    cct::Set< std::shared_ptr<QObject> > tempObjects;
    QByteArray gid;
    QByteArray token;
    QByteArray rsaKey;/*rsa -- key*/
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
    void upDateGID(  BaiDuFinishedCallBackPointer);

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
        cct::Func< void(QNetworkReply *   ,BaiDuFinishedCallBackPointer) >,
        BaiDuFinishedCallBackPointer
        );

private:

signals:
    void loginFinished( bool,QString );
public slots:
    void login(
            QString userName,
            QString passWord,
            BaiDuVertifyCode vertifyCode
            );

};

#endif
