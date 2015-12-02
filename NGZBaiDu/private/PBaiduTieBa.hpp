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
signals:
    void sendFinished(bool,QString);
public:
    SendTieBaDataPack();
    ~SendTieBaDataPack();

    QString tbname;
    QString ttitle;
    QByteArray tbs;
    QByteArray fid;
    BaiDuVertifyCode vcode;
    QString localDir;
    std::shared_ptr<TieBaFormatData> content;

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
    void sendDataFinished(bool ,QString);
public slots:
    void sendData(QString,QString,QString,QString,BaiDuVertifyCode);
public:
    bool onDestory() const volatile { return isOnDestory.load(); }

    void sendDetail(
        QString/*tbname*/,
        QString/*title*/,
        QByteArray/*data*/,
        QByteArray/*tbs*/,
        BaiDuVertifyCode,
        QByteArray/*fid*/,
        std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> ,
        BaiDuFinishedCallBackPointer );/*发帖实现细节*/

    void send( 
        std::shared_ptr< SendTieBaDataPack > ,
        std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>  ,
        BaiDuFinishedCallBackPointer );/*发帖*/

    void localTieBa2BaiDuTieBa(
        QByteArray /*fid*/,
        QString/*local dir*/ ,
        std::shared_ptr<TieBaFormatData>,
        std::function<void(std::shared_ptr<TieBaFormatData> ,BaiDuFinishedCallBackPointer)> ,
        BaiDuFinishedCallBackPointer);

    void images2html(
        QByteArray /*fid*/ ,
        QList<QString> , 
        QList<QImage>,
        std::function<void(cct::List<TieBaTextImageType> &,BaiDuFinishedCallBackPointer)>,
        BaiDuFinishedCallBackPointer);

    void image2html(
        QByteArray /*fid*/ , 
        QImage,
        std::function<void(TieBaTextImageType,BaiDuFinishedCallBackPointer)> ,
        BaiDuFinishedCallBackPointer);
    
    static QByteArray genPostData( std::shared_ptr<TieBaFormatData> );
    std::shared_ptr<BaiDuUser> baiDuUser;
    std::atomic<bool> isOnDestory{false};

};

#endif // PBAIDUTIEBA_HPP
