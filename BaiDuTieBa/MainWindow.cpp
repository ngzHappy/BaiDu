#include "MainWindow.hpp"
#include <BaiDuUser.hpp>
#include <QUrl>
#include <QQuickItem>
#include <QDebug>
#include <QApplication>
#include <QQmlContext>

MainWindow::MainWindow( )
    : QQuickView( ){

    //setFlags(Qt::FramelessWindowHint|flags());
    //setColor(QColor(Qt::transparent));

    this->rootContext()->setContextProperty("thisWindow",this); ;

    this->setSource( QUrl("qrc:/MainWindow.qml") );
    this->setResizeMode( SizeRootObjectToView );

    this->setMinimumHeight(320);
    this->setMinimumWidth(240);

}

MainWindow::~MainWindow(){

}
