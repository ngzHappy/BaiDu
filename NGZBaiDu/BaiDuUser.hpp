#if !defined(BAIDUUSER_ngz_HPP)
#define BAIDUUSER_ngz_HPP

#include <functional>
#include <UniqueSharedPointer.hpp>
#include "ngzbaidu_global.hpp"
#include "BaiDuVertifyCode.hpp"
#include "BaiDuFinishedCallBack.hpp"

typedef std::shared_ptr<BaiDuVertifyCode> BaiDuVertifyCodePointer;
typedef std::shared_ptr<BaiDuFinishedCallBack> BaiDuFinishedCallBackPointer;

class NGZBAIDUSHARED_EXPORT BaiDuUser :
        public  QObject{
    Q_OBJECT
public:

    BaiDuUser( QObject * = nullptr );
    ~BaiDuUser();
public:

    static void gid( std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> ,BaiDuFinishedCallBackPointer );
    static void currentTimer( std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> ,BaiDuFinishedCallBackPointer);
public:

    void setUserAgent(const QByteArray & , bool isPhone = false );
    const std::pair<QByteArray,bool> getUserAgent()const;

    bool isLogin() const;

signals:

    /* 登录 : 注意,没有logout 需要logout只需要delete this即可
     * 如果isLoging_ == true 直接返回
    */
    void login(
            QString userName,
            QString passWord,
            BaiDuVertifyCode vertifyCode
            );

    /*
    登录成功返回true
    否则返回 false,以及失败原因
    */
    void loginFinished( bool,QString );

    /*
    验证码 url id
    */
    void loginVerifyCodeURL( QByteArray,QByteArray );

public:
    class BaiDuUserPrivate;
    friend class BaiDuUserPrivate;
private:

    cct::unique_shared_ptr< BaiDuUserPrivate > thisp  ;
};


#endif
