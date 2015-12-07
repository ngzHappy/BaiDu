#include "MainWindow.hpp"
#include <BaiDuUser.hpp>
#include <QUrl>
#include <QQuickItem>
#include <QDebug>
#include <QApplication>
#include <QQmlContext>
#include <BaiDuTieBa.hpp>
#include <BaiDuUser.hpp>
#include <QQmlProperty>
#include <vector>
#include <QImage>
#include <QQuickImageProvider>
#include <QQmlEngine>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <string>
#include <sstream>
#include <QUrl>
#include <set>
#include <QTimer>
#include <algorithm>
namespace {

class TieBaImageProvider_ : public QQuickImageProvider {
public:
    TieBaImageProvider_()
        : QQuickImageProvider( QQuickImageProvider::Image ) {
        manager=new QNetworkAccessManager;
        vimage=QImage( ":/vctest.png" );
    }
    ~TieBaImageProvider_() {
        manager->deleteLater();
    }

    QNetworkAccessManager * manager;
    QImage vimage;

    /*下载图片,因为图片很小应该很快*/
    void downLoad( QByteArray url_ ) {
        auto r = manager->get( QNetworkRequest( QUrl( url_ ) ) );
        QEventLoop loop;
        r->connect(r,&QNetworkReply::finished, &loop, &QEventLoop::quit );
        loop.exec();
        vimage = QImage::fromData( r->readAll() );
    }

    /**/
    virtual QImage requestImage(
        const QString &id,
        QSize *size,
        const QSize& requestedSize) override {

        if (vimage.width()<=0) {
            QImage ans = QImage( requestedSize,QImage::Format_ARGB32 ); ans.fill(QColor(0,0,0,0));
            if (size) { *size=requestedSize; } return ans;
        }

        int cid=-1;
        {
            std::string id_=id.toStdString();
            std::stringstream ss(std::move(id_));
            ss>>cid;
        }

        if ( cid>19 ) {
            QImage ans = QImage( QSize(80,80) ,QImage::Format_ARGB32 );
            ans.fill(QColor(0,0,0,0));
            if (size) { *size = QSize(80,80) ; } return ans;
        }

        if (cid==9) {
            if (size) { *size=vimage.size(); }
            return vimage;
        }

        {
            *size=QSize(80,80);
            QRect rect;
            switch (cid) {
                case 0:rect=QRect(0  ,80 ,80,80); return vimage.copy(rect); break;
                case 1:rect=QRect(80 ,80 ,80,80); return vimage.copy(rect); break;
                case 2:rect=QRect(160,80 ,80,80); return vimage.copy(rect); break;
                case 3:rect=QRect(0  ,160,80,80); return vimage.copy(rect); break;
                case 4:rect=QRect(80 ,160,80,80); return vimage.copy(rect); break;
                case 5:rect=QRect(160,160,80,80); return vimage.copy(rect); break;
                case 6:rect=QRect(0  ,240,80,80); return vimage.copy(rect); break;
                case 7:rect=QRect(80 ,240,80,80); return vimage.copy(rect); break;
                case 8:rect=QRect(160,240,80,80); return vimage.copy(rect); break;
            }
        }
        *size=QSize(0,0);
        return QImage();

    }

};

}

class MainWindow::ThisData {
public:
    TieBaImageProvider_ * images_;
    BaiDuVertifyCode vertifyCode;
    QQuickItem * vertifyDialog = nullptr;
    QQuickItem * content = nullptr ;
    std::vector< int > vertifyCodeAns ;
    std::vector< QString > vertifyImages ;
    QString key; int key_id;
    std::set<int> vertifyCodeSet;

    ~ThisData() {

    }
    ThisData() {
        images_ = new TieBaImageProvider_;
        updataVertifyImages();
        key_id=0;
    }

    void nextKey() {
        constexpr const char  key_[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        enum { KEY_SIZE = (sizeof(key_)/sizeof(char)) };
        if ((++key_id)>=KEY_SIZE) { key_id=0; }
        if (key_id<0) { key_id=0; }
        key=QString("key_")+QString(key_[key_id]);
    }

    void updataVertifyImages(   ) {
        nextKey();
        vertifyImages.clear();
        vertifyImages.push_back("image://vertifyImage/20/ab"+key);
        vertifyImages.push_back("image://vertifyImage/21/ab"+key);
        vertifyImages.push_back("image://vertifyImage/22/ab"+key);
        vertifyImages.push_back("image://vertifyImage/23/ab"+key);
        vertifyImages.push_back("image://vertifyImage/9/ab"+key);

        QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,0   ),Q_ARG(QVariant,vertifyImages[0]+key));
        QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,1   ),Q_ARG(QVariant,vertifyImages[1]+key));
        QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,2   ),Q_ARG(QVariant,vertifyImages[2]+key));
        QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,3   ),Q_ARG(QVariant,vertifyImages[3]+key));
        QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,4   ),Q_ARG(QVariant,vertifyImages[4]+key));

    }

    void clear() {
        images_->vimage=QImage();
        vertifyCodeAns.clear();
        vertifyCodeSet.clear();
        vertifyCode = BaiDuVertifyCode();
    }

    void hideVertifyDialog() {
        if (vertifyDialog==nullptr) { return; }
        QQmlProperty::write(vertifyDialog,"visible",false);
    }

    void showVertifyDialog() {

        if (vertifyDialog==nullptr) { return; }
        updataVertifyImages();/**/
        QQmlProperty::write(vertifyDialog,"visible",true);

    }

    QByteArray getVertifyCode() {
        if ( vertifyCodeAns.size()==4 ) {
            QByteArray ans; ans.reserve(36);
            for (const auto & i:vertifyCodeAns) {
                switch (i) {
                    case 0:ans.push_back("00000000") ; break;
                    case 1:ans.push_back("00010000"); break;
                    case 2:ans.push_back("00020000"); break;
                    case 3:ans.push_back("00000001"); break;
                    case 4:ans.push_back("00010001"); break;
                    case 5:ans.push_back("00020001"); break;
                    case 6:ans.push_back("00000002"); break;
                    case 7:ans.push_back("00010002"); break;
                    case 8:ans.push_back("00020002"); break;
                }
            }
            return ans;
        }
        return QByteArray();
    }

    void addItem( int i ) {
        nextKey();
        if (vertifyDialog==nullptr) { return; }
        if (vertifyCodeSet.count(i)) { return; }

        if (vertifyCodeAns.size()< 4) {
            //reset image
            vertifyCodeAns.push_back(i);
            vertifyCodeSet.insert(i);
            const auto i_=vertifyCodeAns.size()-1;
            switch ( i /*012345678*/ ) {
                case 0:vertifyImages[i_]=("image://vertifyImage/0/ab"+key); break;
                case 1:vertifyImages[i_]=("image://vertifyImage/1/ab"+key); break;
                case 2:vertifyImages[i_]=("image://vertifyImage/2/ab"+key); break;
                case 3:vertifyImages[i_]=("image://vertifyImage/3/ab"+key); break;
                case 4:vertifyImages[i_]=("image://vertifyImage/4/ab"+key); break;
                case 5:vertifyImages[i_]=("image://vertifyImage/5/ab"+key); break;
                case 6:vertifyImages[i_]=("image://vertifyImage/6/ab"+key); break;
                case 7:vertifyImages[i_]=("image://vertifyImage/7/ab"+key); break;
                case 8:vertifyImages[i_]=("image://vertifyImage/8/ab"+key); break;

            }
            switch ( i_ ) {
                case 0: QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,0),Q_ARG(QVariant,vertifyImages[0] )); break;
                case 1: QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,1),Q_ARG(QVariant,vertifyImages[1] )); break;
                case 2: QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,2),Q_ARG(QVariant,vertifyImages[2] )); break;
                case 3: QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,3),Q_ARG(QVariant,vertifyImages[3] )); break;

            }
        }
    }

    void removeItem() {
        nextKey();
        if (vertifyCodeAns.size()>0) {
            auto i =   vertifyCodeAns.size() -1 ;
            vertifyCodeSet.erase( *vertifyCodeAns.rbegin() );
            //reset image
            vertifyCodeAns.pop_back( );
            switch (i) {
                case 0: QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,0),Q_ARG(QVariant,QString( "image://vertifyImage/100" ))); break;
                case 1: QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,1),Q_ARG(QVariant,QString( "image://vertifyImage/100" ))); break;
                case 2: QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,2),Q_ARG(QVariant,QString( "image://vertifyImage/100" ))); break;
                case 3: QMetaObject::invokeMethod(vertifyDialog,"setItem",Q_ARG(QVariant,3),Q_ARG(QVariant,QString( "image://vertifyImage/100" ))); break;

            }
        }
    }

};

void MainWindow::hideVertifyDialog() { thisd->hideVertifyDialog(); }
void MainWindow::showVertifyDialog() { thisd->showVertifyDialog(); }

MainWindow::MainWindow( )
    : QQuickView( ){

    thisd=new ThisData;
    tieba = std::make_shared< BaiDuTieBa >();

    //setFlags(Qt::FramelessWindowHint|flags());
    //setColor(QColor(Qt::transparent));

    this->rootContext()->setContextProperty("thisWindow",this);
    //image://vertifyImage/[01234]/ab
    engine()->addImageProvider(QLatin1String("vertifyImage"), thisd->images_ );
    this->setSource( QUrl( u8R"(qrc:/MainWindow.qml)" ) );
    this->setResizeMode( SizeRootObjectToView );

    this->setMinimumHeight(320);
    this->setMinimumWidth(240);

    QQuickItem * root_ = nullptr ;
    {
        QQuickItem * item_= this->rootObject() ;
        QObject * obj = item_->findChild<QObject *>("VertifyCodeDialog");
        thisd->vertifyDialog = qobject_cast<QQuickItem * >(obj);
        root_ = item_;
        if(root_ == nullptr ){return ;}
        obj=item_->findChild<QObject *>("tcontentID");
        thisd->content = qobject_cast<QQuickItem * >(obj);
    }

    connect(root_,SIGNAL(postFloorData(QString,QString,QString,QString)),
            this,SLOT(postFloorData(QString,QString,QString,QString)));
    connect(root_,SIGNAL(postData(QString,QString,QString)),
        this,SLOT(post(QString,QString,QString)));
    connect( root_,SIGNAL(sendData(QString,QString,QString,QString)),
        this,SLOT(send(QString,QString,QString,QString))
        );
    connect(this,SIGNAL(setContent(QVariant)),
        root_,SLOT(setContent(QVariant)));
    connect(this,SIGNAL(sendFinished(QVariant,QVariant)),
        root_,SLOT(sendFinished(QVariant,QVariant)));
    connect(tieba.get(),&BaiDuTieBa::finishedSend,
        this,&MainWindow::_sendFinished);
    connect(tieba.get(),&BaiDuTieBa::vertifyCode,
        this,[this](QByteArray url_,QByteArray id_) {
        thisd->vertifyCode.id=id_;
        thisd->vertifyCode.url=url_;
        thisd->images_->downLoad( url_ );
        thisd->showVertifyDialog();
    }
        );
    connect(root_,SIGNAL(signData()),this,SLOT(sign()));
    connect( tieba.get(),&BaiDuTieBa::imageContentChanged,
             this,[this](QString v){ this->setContent(v); });
    connect( thisd->vertifyDialog,SIGNAL(addItem(int) ),
        this,SLOT(_additem(int)) );
    connect( thisd->vertifyDialog,SIGNAL(removeItem() ),
        this,SLOT(_removeItem()) );

    this->setMinimumWidth(512);
    this->setMinimumHeight(512);

}
void MainWindow::_additem(int i) {
    thisd->addItem( i );
}
void MainWindow::_removeItem() { thisd->removeItem(); }
void MainWindow::_sendFinished(bool v,QString t) {sendFinished(v,t);}

void MainWindow::setBaiDuUser( std::shared_ptr<BaiDuUser > u ){
    tieba->setBaiDuUser( u );
}

void MainWindow::postShow(){
    QMetaObject::invokeMethod(this, "show",Qt::QueuedConnection );
}

void MainWindow::post(QString a,QString b,QString c){
    /*隐藏验证码dialog*/
    hideVertifyDialog();
    /*计算验证码*/
    if (thisd->vertifyCode.id.size()>6) {
        thisd->vertifyCode.ans = thisd->getVertifyCode() ;
    }
    /*发布帖子*/
    if(tieba){tieba->post(a,b,c ,thisd->vertifyCode);}
    /*清空验证码*/
    thisd->clear();
}

/*发帖*/
void MainWindow::send(QString a,QString b,QString c,QString d){
    /*隐藏验证码dialog*/
    hideVertifyDialog();
    /*计算验证码*/
    if (thisd->vertifyCode.id.size()>6) {
        thisd->vertifyCode.ans = thisd->getVertifyCode() ;
    }
    /*发布帖子*/
    if(tieba){tieba->send(a,b,c,d ,thisd->vertifyCode);}
    /*清空验证码*/
    thisd->clear();

}

void MainWindow::updateVertifyImages() {
    thisd->updataVertifyImages();
}

MainWindow::~MainWindow(){
    delete thisd;
}

void MainWindow::sign( ){
    auto tieba_=tieba;
    if (tieba) {
        QString lists_=QQmlProperty::read(thisd->content,"text").toString();
        QTextStream stream(&lists_);
        std::list<QString> about_sign_;
        while (stream.atEnd()==false) {
            auto line_ = stream.readLine();line_=line_.trimmed();
            if ( line_.isEmpty()==false ) {
                about_sign_.push_back(line_);
            }
        }

        {//sort and unique
            about_sign_.sort();
            about_sign_.unique();
        }

        QTimer * sign_timer_ = new QTimer(this);
        typedef void(QTimer::*TT)();
        std::shared_ptr< std::list<QString> > about_sign(new std::list<QString>(std::move( about_sign_ )) );
        connect( sign_timer_,TT(&QTimer::timeout),
            sign_timer_,[ about_sign ,tieba_,sign_timer_ ]() mutable{
            if (about_sign->empty()) {
                sign_timer_->stop();
                sign_timer_->deleteLater();
                return;
            }
            auto tbname_ = *(about_sign->begin());about_sign->pop_front();
            tieba_->sign( tbname_ );
        });
        sign_timer_->start( 50 );/*每秒签到20次*/
    }
}

void MainWindow::postFloorData(QString a,QString b,QString c,QString d) {
    /*隐藏验证码dialog*/
    hideVertifyDialog();
    /*计算验证码*/
    if (thisd->vertifyCode.id.size()>6) {
        thisd->vertifyCode.ans = thisd->getVertifyCode() ;
    }
    /*发布帖子*/
    if(tieba){tieba->postUnderFloor(a,b,c,d ,thisd->vertifyCode);}
    /*清空验证码*/
    thisd->clear();
}

/**/
