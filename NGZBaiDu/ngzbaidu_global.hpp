#if !defined(NGZBAIDU_GLOBAL_HPP )
#define NGZBAIDU_GLOBAL_HPP

#include <QObject>
#include <cstddef>
#include <cstdint>
#include <cstdbool>
#include <tuple>
#include <utility>
#include <algorithm>
#include <memory>
#include <limits>
#include <ciso646>
#include <QtCore/qglobal.h>

#if !defined( STATIC_NGZBAIDU_LIBRARY )

#if defined(NGZBAIDU_LIBRARY)
#  define NGZBAIDUSHARED_EXPORT Q_DECL_EXPORT
#else
#  define NGZBAIDUSHARED_EXPORT Q_DECL_IMPORT
#endif

#else

#define NGZBAIDUSHARED_EXPORT /*  */

#endif





#endif // NGZBAIDU_GLOBAL_HPP
