#if !defined(PBAIDUUSER_ngz_HPP)
#define PBAIDUUSER_ngz_HPP

#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkCookie>
#include <Map.hpp>
#include "../BaiDuUser.hpp"

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
    QByteArray rsaKey;/*rsa -- key*/

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
    cct::Map< QByteArray, QNetworkCookie> cookies;

    BaiDuUserPrivate(BaiDuUser * s);
    ~BaiDuUserPrivate( );

    void setLogInPackData( BaiDuUserLoginPack * );
    void connectLoginPack(BaiDuUserLoginPack *);
public:
    // ask  http://www.baidu.com  then set cookie
    void getBaiduCookie( std::function<void(cct::Map< QByteArray, QNetworkCookie>, BaiDuFinishedCallBackPointer)> ,BaiDuFinishedCallBackPointer );

    //token
    void getBaiduToken( std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer );
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
