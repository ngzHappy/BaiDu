﻿#ifndef PBAIDUTIEBA_HPP
#define PBAIDUTIEBA_HPP

#include "BaiDuUser.hpp"
#include "../BaiDuTieBa.hpp"
#include <QObject>
#include <SharedFromSuper.hpp>
#include "BaiDuFinishedCallBack.hpp"

class NGZBAIDUSHARED_EXPORT SendTieBaDataPack : 
    public QObject,
    public BaiDuFinishedCallBack{
    Q_OBJECT
public:
    SendTieBaDataPack();
    ~SendTieBaDataPack();

    bool hasError =  false;
    bool isValueSet= false;
    virtual void finished(bool v,QString) override;
};

class NGZBAIDUSHARED_EXPORT BaiDuTieBaPrivate :
        public QObject {
    Q_OBJECT
public:
    cct::SharedFromSuper<BaiDuTieBaPrivate> thisp ;
public:
    BaiDuTieBaPrivate();
    ~BaiDuTieBaPrivate();

    std::shared_ptr<BaiDuUser> baiDuUser;

};

#endif // PBAIDUTIEBA_HPP
