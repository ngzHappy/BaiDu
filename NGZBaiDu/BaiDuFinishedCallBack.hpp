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
typedef std::shared_ptr<BaiDuFinishedCallBack> BaiDuFinishedCallBackPointer;

#endif // BAIDUFINISHEDCALLBACK_HPP
