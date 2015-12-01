#ifndef PBAIDUTIEBA_HPP
#define PBAIDUTIEBA_HPP

#include <atomic>
#include "BaiDuUser.hpp"
#include "../BaiDuTieBa.hpp"
#include <QObject>
#include <SharedFromSuper.hpp>
#include "BaiDuFinishedCallBack.hpp"

class NGZBAIDUSHARED_EXPORT SendTieBaDataPack : 
    public QObject,
    public BaiDuFinishedCallBack{
    Q_OBJECT
public:
    SendTieBaDataPack();
    ~SendTieBaDataPack();

    QString tbname;
    QString ttitle;
    QByteArray tbs;
    QByteArray fid;
    BaiDuVertifyCode vcode;
    QString localDir;

    bool hasError =  false;
    bool isValueSet= false;
    virtual void finished(bool v,QString) override;
    cct::SharedFromSuper<BaiDuTieBaPrivate> thisp ;
};

class NGZBAIDUSHARED_EXPORT BaiDuTieBaPrivate :
        public QObject {
    Q_OBJECT
public:
    cct::SharedFromSuper<BaiDuTieBaPrivate> thisp ;
public:
    BaiDuTieBaPrivate();
    ~BaiDuTieBaPrivate();
signals:
    void vertifyCode(QByteArray/*url*/,QByteArray/*id*/);
public:
    bool onDestory() const volatile { return isOnDestory.load(); }

    void sendDetail(
        QString/*tbname*/,
        QString/*title*/,
        QByteArray/*data*/,
        QByteArray/*tbs*/,
        BaiDuVertifyCode,
        QByteArray/*fid*/,
        const std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>& ,
        BaiDuFinishedCallBackPointer );/*发帖实现细节*/

    void send( 
        QString/*tbname*/,
        QString/*title*/,
        QString/*local image dir*/,
        std::shared_ptr<TieBaFormatData>,
        BaiDuVertifyCode,
        const std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> & ,
        BaiDuFinishedCallBackPointer );/*发帖*/

    void localTieBa2BaiDuTieBa(
        const QByteArray /*fid*/,
        const QString/*local dir*/ ,
        std::shared_ptr<TieBaFormatData>,
        const std::function<void(std::shared_ptr<TieBaFormatData> ,BaiDuFinishedCallBackPointer)> &,
        BaiDuFinishedCallBackPointer);

    void images2html(
        const QByteArray /*fid*/ ,
        const QList<QString> & , 
        QList<QImage>,
        const std::function<void(cct::List<TieBaTextImageType> &,BaiDuFinishedCallBackPointer)>,
        BaiDuFinishedCallBackPointer);

    void image2html(
        const QByteArray /*fid*/ , 
        QImage,
        const std::function<void(TieBaTextImageType,BaiDuFinishedCallBackPointer)> &,
        BaiDuFinishedCallBackPointer);
    
    static QByteArray genPostData( std::shared_ptr<TieBaFormatData> );
    std::shared_ptr<BaiDuUser> baiDuUser;
    std::atomic<bool> isOnDestory{false};

};

#endif // PBAIDUTIEBA_HPP
