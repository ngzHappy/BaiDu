CONFIG   += c++14
CONFIG   += crypto # qca if you have it
QT       += core
QT       += gui
QT       += network
QT       += script
QT       += widgets
QT       += quick

#chang local text codec in different system
win32{
TextCodeC_Type = GBK
}else{
TextCodeC_Type = UTF-8
}
DEFINES += TEXTCODECTYPE=$$join( TextCodeC_Type , , "\\\"" , "\\\"" )

#

TARGET = BaiDuTieBa
TEMPLATE = app

SOURCES += main.cpp \
        MainWindow.cpp \
    LogInDialog.cpp

HEADERS  += $$PWD/MainWindow.hpp
HEADERS  += $$PWD/LogInDialog.hpp

INCLUDEPATH += $$PWD/../cct
INCLUDEPATH += $$PWD/../NGZBaiDu

include( $$PWD/../out_path.pri )
DESTDIR = $$PROJECT_OUT_PATH

LIBS += -L$$PROJECT_OUT_PATH -lNGZBaiDu

RESOURCES += LoginInDialog.qrc \
    MainWindow.qrc

unix {
    QMAKE_LFLAGS += -Wl,-rpath .
}



