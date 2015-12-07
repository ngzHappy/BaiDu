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

    enum Type {
        THREAD_TIEBABAIDU,
        REPLY_TIEBABAIDU,
        REPLY_FLOOR_TIEBABAIDU,
        UNKNOW_TIEBABAIDU
    };

    Type type=THREAD_TIEBABAIDU;
    QString tbname;
    QString ttitle;
    QByteArray tbs;
    QByteArray fid;
    BaiDuVertifyCode vcode;
    QString localDir;
    QByteArray tid;
    QByteArray pid;
    QByteArray floor_num;
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
    void genImageContent( QString );
public slots:
    void sign(QString);
    void sendData(QString,QString,QString,QString,BaiDuVertifyCode);
    void postData(QString tid,QString tlocal,QString tbdata,BaiDuVertifyCode vc);
    void postUnderFloorData(QString/*tid*/,QString/*pid*/,QString/*local*/,QString/*data*/,BaiDuVertifyCode);
private:
    void _private_postData( std::shared_ptr<SendTieBaDataPack> );
public:
    bool onDestory() const volatile { return isOnDestory.load(); }

    void sendDetail(
        const SendTieBaDataPack::Type,
        const QString/*tbname*/ & ,
        const QString/*title*/ &  ,
        const QByteArray/*data*/& ,
        const QByteArray/*tbs*/&  ,
        const BaiDuVertifyCode/*vcode*/ &,
        const QByteArray/*fid*/ & ,
        const QByteArray/*tid*/ & ,
        const QByteArray/*floor num*/ &,
        const QByteArray/*pid*/&,
        const std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> & ,
        BaiDuFinishedCallBackPointer
        );/*发帖实现细节*/

    void sendDetail(
        const SendTieBaDataPack::Type a,
        const QString/*tbname*/ & b,
        const QString/*title*/ &  c,
        const QByteArray/*data*/& d,
        const QByteArray/*tbs*/&  e,
        const BaiDuVertifyCode/*vcode*/ & f,
        const QByteArray/*fid*/ & g,
        const QByteArray/*tid*/ & h,
        const QByteArray/*floor num*/ & i,
        std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> j,
        BaiDuFinishedCallBackPointer k
        ) {sendDetail(a,b,c,d,e,f,g,h,i,"",std::move(j),std::move(k)); }

    void sendDetail(
        QString/*tbname*/ a,
        QString/*title*/ b,
        QByteArray/*data*/c,
        QByteArray/*tbs*/d,
        BaiDuVertifyCode e ,
        QByteArray/*fid*/f,
        std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> g,
        BaiDuFinishedCallBackPointer h)/*发帖实现细节*/ {
        return sendDetail(
            SendTieBaDataPack::Type::THREAD_TIEBABAIDU,
            std::move(a),std::move(b),std::move(c),std::move(d) ,
            std::move(e),std::move(f),"0","0",std::move(g),std::move(h)
            );
    }

    void post(
        std::shared_ptr< SendTieBaDataPack > ,
        std::function<void(QByteArray,BaiDuFinishedCallBackPointer)>  ,
        BaiDuFinishedCallBackPointer );/*发帖*/

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
        std::function<void(cct::List<TieBaTextImageType> ,BaiDuFinishedCallBackPointer)>,
        BaiDuFinishedCallBackPointer);

    void image2html(
        QByteArray /*fid*/ ,
        QImage,
        std::function<void(TieBaTextImageType,BaiDuFinishedCallBackPointer)> ,
        BaiDuFinishedCallBackPointer);

    static QByteArray genPostData( SendTieBaDataPack::Type, std::shared_ptr<TieBaFormatData> );
    std::shared_ptr<BaiDuUser> baiDuUser;
    std::atomic<bool> isOnDestory{false};

};

#endif // PBAIDUTIEBA_HPP
