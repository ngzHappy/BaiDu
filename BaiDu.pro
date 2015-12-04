
TEMPLATE = subdirs

#sudo apt-get install openssl
#sudo apt-get install libssl-dev
#sudo apt-get install cmake
#download qca: http://delta.affinix.com/qca/
#make && install qca
#-DCMAKE_BUILD_TYPE=Debug -DCMAKE_BUILD_TYPE=Release

#.subdir	Use the specified subdirectory instead of SUBDIRS value.
#.file	Specify the subproject pro file explicitly. Cannot be used in conjunction with .subdir modifier.
#.depends	This subproject depends on specified subproject. Available only on platforms that use makefiles.
#.makefile	The makefile of subproject. Available only on platforms that use makefiles.
#.target	Base string used for makefile targets related to this subproject. Available only on platforms that use makefiles.

libNGZBaiDu.file = $$PWD/NGZBaiDu/NGZBaiDu.pro
binBaiDuTieBa.file = $$PWD/BaiDuTieBa/BaiDuTieBa.pro
binBaiDuTieBa.depends += libNGZBaiDu

SUBDIRS += libNGZBaiDu
SUBDIRS += NGZBaiDuTest
SUBDIRS += $$PWD/libs/boost
SUBDIRS += cct

SUBDIRS += binBaiDuTieBa










