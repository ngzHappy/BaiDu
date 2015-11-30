#ifndef LOGINDIALOG_HPP
#define LOGINDIALOG_HPP

#include <QQuickView>
#include <memory>

class BaiDuUser ;
class LogInDialog :
        public QQuickView
{
    Q_OBJECT
private:
    typedef QQuickView Super ;
    std::shared_ptr<BaiDuUser> baiDuUser ;
    QByteArray verifyCodeID;

public:
    LogInDialog();
    ~LogInDialog();

    std::shared_ptr<BaiDuUser> getUser() const{ return baiDuUser; }
private:

public slots:
    void quitLogIn();/*退出*/
    void logIn( QString, QString, QString );/*用户名 密码 验证码*/

signals:
    void showVerifyCodeValue( QVariant );
    void showErrorText( QVariant );
    void logInFinished( bool ) ;
private slots:
    void _logInFinished( bool,QString ) ;
};

#endif // LOGINDIALOG_HPP
