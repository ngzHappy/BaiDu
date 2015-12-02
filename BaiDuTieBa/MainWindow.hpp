#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QQuickView>
#include <memory>

class MainWindow : public QQuickView
{
    Q_OBJECT

public:
    MainWindow( );
    ~MainWindow();
};

#endif // MAINWINDOW_HPP
