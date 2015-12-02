#if !defined( BAIDUFINISHEDCALLBACK_HPP )
#define BAIDUFINISHEDCALLBACK_HPP

#include "ngzbaidu_global.hpp"
class NGZBAIDUSHARED_EXPORT BaiDuFinishedCallBack{
public:
    BaiDuFinishedCallBack(){}
    virtual ~BaiDuFinishedCallBack(){}

    bool hasError_ = false;
    virtual void finished(bool v, QString) { hasError_=!v; }
    virtual bool hasError() const final { return hasError_; }
};
typedef std::shared_ptr<BaiDuFinishedCallBack> BaiDuFinishedCallBackPointer;

#endif // BAIDUFINISHEDCALLBACK_HPP
