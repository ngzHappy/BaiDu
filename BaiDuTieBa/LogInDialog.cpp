#include "LogInDialog.hpp"
#include <QUrl>
#include <QQuickItem>
#include <QDebug>
#include <QApplication>
#include <QQmlContext>
#include <BaiDuUser.hpp>

LogInDialog::LogInDialog()
{

    setFlags(Qt::FramelessWindowHint|flags());
    setColor(QColor(Qt::transparent));

    this->rootContext()->setContextProperty("thisDialog",this); ;

    this->setSource( QUrl("qrc:/LogInDialog.qml") );
    this->setResizeMode( SizeRootObjectToView );

    this->setMaximumHeight(512/2);
    this->setMinimumHeight(512/2);

    this->setMaximumWidth(512);
    this->setMinimumWidth(512);

    QQuickItem * root_ = nullptr ;
    {
        QQuickItem * item_= this->rootObject() ;
        QObject * obj = item_->findChild<QObject *>("root");
        root_ = qobject_cast<QQuickItem * >(obj);
        if(root_ == nullptr ){return ;}
    }

    connect(root_ , SIGNAL(quitLogIn()) ,this,SLOT(quitLogIn() ));
    connect(root_,SIGNAL(logIn(QString,QString,QString)),
            this,SLOT(logIn(QString,QString,QString)));
    connect(this,SIGNAL(showVerifyCodeValue( QVariant )),
            root_,SLOT(showVerifyCodeValue( QVariant ))
            );
    connect(this,SIGNAL(showErrorText(QVariant)) ,
            root_,SLOT(showErrorText(QVariant)));

}

void LogInDialog::quitLogIn(){
    /* 退出应用程序 */
    QApplication::exit(0);
}
void LogInDialog::logIn(
        QString userName,
        QString passWord,
        QString verifyCode) {

    if( baiDuUser ){
        this->disconnect( baiDuUser.get() );
        baiDuUser.get()->disconnect( this );
        baiDuUser.reset();
    }

    baiDuUser = std::make_shared<BaiDuUser>();

    connect(baiDuUser.get() ,&BaiDuUser::loginVerifyCodeURL,
            [this](QByteArray url_ , QByteArray url_id_ ){
        showVerifyCodeValue( url_ );
        verifyCodeID=url_id_;
    }
                );

    connect(baiDuUser.get() , &BaiDuUser::loginFinished,
            this,&LogInDialog::_logInFinished
                );     

    {
        BaiDuVertifyCode vc_;
        if (verifyCode.size()>0) {
            vc_.id=verifyCodeID;
            vc_.ans=verifyCode.toUtf8();
            baiDuUser->login(userName,passWord,vc_);
        }
        else {
            baiDuUser->login(userName,passWord,vc_);
        }
    }

}

void LogInDialog::_logInFinished(bool isLogIn_ ,QString value_ ) {
    if (isLogIn_) { 
        showErrorText(QString::fromUtf8(u8"登录成功")); 
        logInFinished( isLogIn_ );
        return;
    }
    showErrorText( value_ );
}

LogInDialog::~LogInDialog(){

}

