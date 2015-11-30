#if !defined( BAIDUTIEBA_HPP )
#define BAIDUTIEBA_HPP

#include "ngzbaidu_global.hpp"
#include "BaiDuVertifyCode.hpp"
#include "BaiDuFinishedCallBack.hpp"
#include <QObject>
#include <UniqueSharedPointer.hpp>

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

signals:

public slots:

private:
    cct::unique_shared_ptr<BaiDuTieBaPrivate> thisp ;
};

#endif // BAIDUTIEBA_HPP
