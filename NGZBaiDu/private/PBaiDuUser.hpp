#if !defined(PBAIDUUSER_ngz_HPP)
#define PBAIDUUSER_ngz_HPP

#include <functional>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkCookie>
#include <Map.hpp>
#include <QVariant>
#include <QNetworkReply>
#include "../BaiDuUser.hpp"

namespace cct{
template<typename T>
using Func =std::function<T>;
}


class BaiDuUserLoginNetworkAccessManager :
        public QNetworkAccessManager{
    Q_OBJECT
public:
    BaiDuUserLoginNetworkAccessManager( QObject * ) ;
};

class NGZBAIDUSHARED_EXPORT BaiDuUserLoginPack :
        public QObject,
        public BaiDuFinishedCallBack {
    Q_OBJECT
public:
    class BaiDuUser * baiduUser = nullptr ;
    class BaiDuUser::BaiDuUserPrivate * baiduUserPrivate = nullptr ;
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

    BaiDuUser * super ;
    BaiDuUserLoginNetworkAccessManager * manager ;
    QByteArray userAgent;
    cct::Map< QByteArray, QNetworkCookie > cookies;
    QByteArray gid;
    QByteArray token;
    QByteArray rsaKey;/*rsa -- key*/

    BaiDuUserPrivate(BaiDuUser * s);
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
