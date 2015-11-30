#if !defined( BAIDUFINISHEDCALLBACK_HPP )
#define BAIDUFINISHEDCALLBACK_HPP

#include "ngzbaidu_global.hpp"
class NGZBAIDUSHARED_EXPORT BaiDuFinishedCallBack{
public:
    BaiDuFinishedCallBack(){}
    virtual ~BaiDuFinishedCallBack(){}

    bool hasError = false;
    virtual void finished(bool v, QString) { hasError=!v; }

};

#endif // BAIDUFINISHEDCALLBACK_HPP
