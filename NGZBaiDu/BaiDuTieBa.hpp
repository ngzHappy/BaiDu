#if !defined( BAIDUTIEBA_HPP )
#define BAIDUTIEBA_HPP

#include "ngzbaidu_global.hpp"
#include "BaiDuVertifyCode.hpp"
#include "BaiDuFinishedCallBack.hpp"
#include <QObject>
#include <UniqueSharedPointer.hpp>
#include <functional>

class BaiDuUser;

class BaiDuTieBaPrivate ;

class NGZBAIDUSHARED_EXPORT BaiDuTieBa :
        public QObject
{
    Q_OBJECT
public:
    explicit BaiDuTieBa(QObject *parent = nullptr );
    ~BaiDuTieBa();

public:
    std::shared_ptr<BaiDuUser> getBaiDuUser()const;
    void setBaiDuUser( std::shared_ptr<BaiDuUser> );

    static void mouse_pwd(QByteArray now_ ,std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer  ) ;
    static void imgtbs(std::shared_ptr< BaiDuUser >,std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer );
signals:

public slots:

private:
    cct::unique_shared_ptr<BaiDuTieBaPrivate> thisp ;
};

#endif // BAIDUTIEBA_HPP
