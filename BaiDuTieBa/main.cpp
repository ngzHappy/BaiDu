#include <cmath>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QtCrypto>
#include <QImage>
#include <QTextCodec>
#include <QDateTime>
#include <QTimer>
#include <MainWindow.hpp>
#include <LogInDialog.hpp>

int main(int argc, char *argv[]){

    /*初始化主线程+事件队列*/
    QApplication app(argc, argv);
    /*初始化常用密码库(qca)*/
    QCA::Initializer initqca;
    /*初始化图片库*/
    { auto * i=new QImage(".....png"); delete i; }
    /*初始化本地文字编码*/
    QTextCodec::setCodecForLocale(QTextCodec::codecForName(TEXTCODECTYPE));
    /*初始化opengl渲染环境*/
    if (argc>1) { QApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);/*Qt::AA_UseSoftwareOpenGL*/ }

    /*主窗口*/
    MainWindow * mainWindow= new MainWindow;
    /*登录*/
    LogInDialog * dialog_login=new LogInDialog;

    {//move
        int x, y, w, h;

        auto rect=QApplication::desktop()->availableGeometry();
        w=dialog_login->minimumWidth();
        h=dialog_login->minimumHeight();
        x=std::abs(rect.width()-w)/2;
        y=std::abs(rect.height()-h)/2;

        dialog_login->setGeometry(x, y, w, h);
        dialog_login->show();
        dialog_login->setGeometry(x, y, w, h);
    }

    /* 如果登录成功则显示主窗口 */
    dialog_login->connect(dialog_login, &LogInDialog::logInFinished,
        [dialog_login,mainWindow](bool islogin) {
        if (islogin) {
            auto user_=dialog_login->getUser();
            dialog_login->setVisible(false);

            /*主窗口*/
            mainWindow->setBaiDuUser(user_);
            mainWindow->show();
            delete dialog_login;

            {//move
                int x, y, w, h;

                auto rect=QApplication::desktop()->availableGeometry();
                w= 512;
                h= 512;
                x=std::abs(rect.width()-w)/2;
                y=std::abs(rect.height()-h)/2;

                mainWindow->setGeometry(x, y, w, h);
                mainWindow->postShow();
            }

        }
    });

    {
        const auto app_ans=app.exec();
        return app_ans;
    }

}

/**/
