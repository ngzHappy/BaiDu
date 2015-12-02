#if !defined( BAIDUVERTIFYCODE_HPP )
#define BAIDUVERTIFYCODE_HPP

#include "ngzbaidu_global.hpp"

class NGZBAIDUSHARED_EXPORT BaiDuVertifyCode{
public:
    QByteArray id ;/* 百度要求的验证码 */
    QByteArray url;/* 验证码对应的url */
    QByteArray ans;/* 用户识别的验证码 */
};
typedef std::shared_ptr<BaiDuVertifyCode> BaiDuVertifyCodePointer;

Q_DECLARE_METATYPE( BaiDuVertifyCode )
Q_DECLARE_METATYPE( BaiDuVertifyCodePointer )
#endif // BAIDUVERTIFYCODE_HPP
 