
#
#
#

CONFIG += c++14
QT += core
QT -= gui
QT += network

TARGET = NGZBaiDu
TEMPLATE = lib

DEFINES += NGZBAIDU_LIBRARY

SOURCES += NGZBaiDu.cpp \
    BaiDuUser.cpp

HEADERS += $$PWD/NGZBaiDu.hpp
HEADERS += $$PWD/BaiDuUser.hpp
HEADERS += $$PWD/private/PBaiDuUser.hpp
HEADERS += $$PWD/ngzbaidu_global.hpp


INCLUDEPATH += $$PWD/../cct



###############
