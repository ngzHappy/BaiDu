#if !defined( BAIDUTIEBA_HPP )
#define BAIDUTIEBA_HPP

#include "ngzbaidu_global.hpp"
#include "BaiDuVertifyCode.hpp"
#include "BaiDuFinishedCallBack.hpp"
#include "TieBaFormatData.hpp" 
#include <QObject>
#include <UniqueSharedPointer.hpp>
#include <functional>
#include <QImage>
#include <List.hpp>

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

    void localTieBa2BaiDuTieBa( QByteArray /*fid*/,QString/*local dir*/ ,std::shared_ptr<TieBaFormatData>,std::function<void(std::shared_ptr<TieBaFormatData>,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer);
    void images2html(QByteArray /*fid*/,QList<QString>, QList<QImage>,std::function<void(cct::List<TieBaTextImageType>,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer);
    void image2html(QByteArray /*fid*/, QImage,std::function<void(TieBaTextImageType,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer);
    static void mouse_pwd(QByteArray now_ ,std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer  ) ;
    static void imgtbs(std::shared_ptr< BaiDuUser >,std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer );
    static void tbs(std::shared_ptr< BaiDuUser >,std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer );
    static void fid( std::shared_ptr< BaiDuUser >,QString /*贴吧名字*/ ,std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>,BaiDuFinishedCallBackPointer   );
signals:

public slots:

private:
    cct::unique_shared_ptr<BaiDuTieBaPrivate> thisp ;
};

#endif // BAIDUTIEBA_HPP
