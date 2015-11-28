#if !defined(BAIDUUSER_ngz_HPP)
#define BAIDUUSER_ngz_HPP

#include <functional>
#include <memory>
#include "ngzbaidu_global.hpp"

class NGZBAIDUSHARED_EXPORT BaiDuVertifyCode{
public:
    QByteArray id ;
    QByteArray url;
    QByteArray ans;
};

class NGZBAIDUSHARED_EXPORT BaiDuFinishedCallBack{
public:
    BaiDuFinishedCallBack(){}
    virtual ~BaiDuFinishedCallBack(){}

    bool hasError = false;
    virtual void finished(bool v, QString) { hasError=!v; }

};

typedef std::shared_ptr<BaiDuVertifyCode> BaiDuVertifyCodePointer;
typedef std::shared_ptr<BaiDuFinishedCallBack> BaiDuFinishedCallBackPointer;

class NGZBAIDUSHARED_EXPORT BaiDuUser :
        public  QObject{
    Q_OBJECT
public:

    BaiDuUser( QObject * );
    ~BaiDuUser();
public:

    static void gid( std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> ,BaiDuFinishedCallBackPointer );
    static void currentTimer( std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> ,BaiDuFinishedCallBackPointer);

signals:

    /* 登录 : 注意,没有logout 需要logout只需要delete this即可
     * 如果isLoging_ == true 直接返回
    */
    void login(
            QString userName,
            QString passWord,
            BaiDuVertifyCode vertifyCode
            );

    void loginFinished( bool,QString );
public:
    class BaiDuUserPrivate;
    friend class BaiDuUserPrivate;
private:

    std::shared_ptr< BaiDuUserPrivate > thisp  ;
};


#endif
