#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QQuickView>
#include <memory>
#include <QVariant>

class BaiDuUser  ;
class BaiDuTieBa ;

class MainWindow : public QQuickView
{
    Q_OBJECT

public:

    MainWindow( );
    ~MainWindow(); 
public slots:
    void postShow();
    void send(QString,QString,QString,QString);
    void post(QString,QString,QString);
    void postFloorData(QString,QString,QString,QString);
    void hideVertifyDialog();
    void showVertifyDialog();
    void updateVertifyImages();
    void sign(  );
signals:
    void setContent(QVariant);
    void sendFinished(QVariant,QVariant);
public:
    void setBaiDuUser( std::shared_ptr<BaiDuUser > );
private:
    std::shared_ptr< BaiDuTieBa > tieba;
    class ThisData;
    ThisData * thisd = nullptr ;
private slots:
    void _sendFinished(bool,QString);
    void _additem(int);
    void _removeItem();
};

#endif // MAINWINDOW_HPP
