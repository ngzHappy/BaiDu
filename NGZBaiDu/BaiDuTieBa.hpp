﻿#if !defined( BAIDUTIEBA_HPP )
#define BAIDUTIEBA_HPP

#include "ngzbaidu_global.hpp"
#include "BaiDuVertifyCode.hpp"
#include "BaiDuFinishedCallBack.hpp"
#include "TieBaFormatData.hpp" 
#include <QObject>
#include <functional>
#include <QImage>
#include <List.hpp>

class BaiDuUser;
class BaiDuTieBaPrivate ;

class NGZBAIDUSHARED_EXPORT BaiDuTieBa :
        public QObject
{
    Q_OBJECT
public:
    explicit BaiDuTieBa( QObject *parent = nullptr );
    ~BaiDuTieBa();

public:
    std::shared_ptr<BaiDuUser> getBaiDuUser()const;
    void setBaiDuUser( std::shared_ptr<BaiDuUser> );
        
    static void mouse_pwd(const QByteArray  now_ ,const std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> &,BaiDuFinishedCallBackPointer  ) ;
    static void imgtbs(std::shared_ptr< BaiDuUser >,const std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> &,BaiDuFinishedCallBackPointer );
    static void tbs(std::shared_ptr< BaiDuUser >,const std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> &,BaiDuFinishedCallBackPointer );
    static void fid(std::shared_ptr< BaiDuUser >,QString /*贴吧名字*/ ,const std::function<void(QByteArray,BaiDuFinishedCallBackPointer)> &,BaiDuFinishedCallBackPointer );

signals:

public slots:

private:
    std::shared_ptr<BaiDuTieBaPrivate> thisp ;
};

#endif // BAIDUTIEBA_HPP