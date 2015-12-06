CONFIG   += c++14
CONFIG   += crypto # qca if you have it
QT       += core
QT       += gui
QT       += network
QT       += script
QT       += widgets
QT       += quick
CONFIG   += console

DEFINES *= STATIC_NGZBAIDU_LIBRARY
TARGET = NGZBaiDuTest
TEMPLATE = app

#chang local text codec in different system
win32{
TextCodeC_Type = GBK
}else{
TextCodeC_Type = UTF-8
}
DEFINES += TEXTCODECTYPE=$$join( TextCodeC_Type , , "\\\"" , "\\\"" )

INCLUDEPATH += $$PWD/../cct
INCLUDEPATH += $$PWD/../NGZBaiDu
INCLUDEPATH += $$PWD/../BaiDuTieBa

SOURCES += main.cpp
SOURCES += $$PWD/../NGZBaiDu/BaiDuTieBa.cpp
SOURCES += $$PWD/../NGZBaiDu/TieBaFormatData.cpp
SOURCES += $$PWD/../NGZBaiDu/private/GZipCompressor.cpp
SOURCES += $$PWD/../NGZBaiDu/private/PBaiDuUser.cpp
SOURCES += $$PWD/../BaiDuTieBa/LogInDialog.cpp
SOURCES += $$PWD/../BaiDuTieBa/MainWindow.cpp
SOURCES += $$PWD/../NGZBaiDu/BaiDuUser.cpp
SOURCES += $$PWD/../NGZBaiDu/NGZBaiDu.cpp

HEADERS  += $$PWD/../BaiDuTieBa/LogInDialog.hpp \
    TestData.hpp
HEADERS  += $$PWD/../NGZBaiDu/BaiDuFinishedCallBack.hpp
HEADERS  += $$PWD/../NGZBaiDu/BaiDuNetworkAccessManager.hpp
HEADERS  += $$PWD/../NGZBaiDu/BaiDuTieBa.hpp
HEADERS  += $$PWD/../NGZBaiDu/private/PBaiduTieBa.hpp
SOURCES  += $$PWD/../NGZBaiDu/TieBaFormatData.hpp
HEADERS  += $$PWD/../NGZBaiDu/private/GZipCompressor.hpp
HEADERS  += $$PWD/../NGZBaiDu/private/PBaiDuUser.hpp
HEADERS  += $$PWD/../BaiDuTieBa/MainWindow.hpp
HEADERS  += $$PWD/../NGZBaiDu/BaiDuUser.hpp
HEADERS  += $$PWD/../NGZBaiDu/NGZBaiDu.hpp
HEADERS  += $$PWD/../NGZBaiDu/ngzbaidu_global.hpp

RESOURCES += $$PWD/../BaiDuTieBa/LoginInDialog.qrc \
    ../BaiDuTieBa/MainWindow.qrc

DISTFILES += $$PWD/../BaiDuTieBa/LogInDialog.qml

unix {
    QMAKE_LFLAGS += -Wl,-rpath .
}
