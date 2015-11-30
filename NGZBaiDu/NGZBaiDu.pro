
#
#
#

CONFIG   += c++14
QT       += core
QT       += gui
QT       += network
QT       += script
CONFIG   += crypto # qca if you have it

TARGET = NGZBaiDu
TEMPLATE = lib

DEFINES += NGZBAIDU_LIBRARY

SOURCES += NGZBaiDu.cpp \
    BaiDuTieBa.cpp \
    TieBaFormatData.cpp
SOURCES += BaiDuUser.cpp
SOURCES += private/GZipCompressor.cpp

HEADERS += $$PWD/NGZBaiDu.hpp \
    BaiDuNetworkAccessManager.hpp \
    TieBaFormatData.hpp
HEADERS += $$PWD/BaiDuTieBa.hpp
HEADERS += $$PWD/private/PBaiduTieBa.hpp
HEADERS += $$PWD/BaiDuVertifyCode.hpp
HEADERS += $$PWD/BaiDuFinishedCallBack.hpp
HEADERS += $$PWD/private/GZipCompressor.hpp
HEADERS += $$PWD/BaiDuUser.hpp
HEADERS += $$PWD/private/PBaiDuUser.hpp
HEADERS += $$PWD/ngzbaidu_global.hpp


INCLUDEPATH += $$PWD/../cct

include( $$PWD/../out_path.pri )
DESTDIR = $$PROJECT_OUT_PATH

###############



