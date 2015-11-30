
TEMPLATE = subdirs

#.subdir	Use the specified subdirectory instead of SUBDIRS value.
#.file	Specify the subproject pro file explicitly. Cannot be used in conjunction with .subdir modifier.
#.depends	This subproject depends on specified subproject. Available only on platforms that use makefiles.
#.makefile	The makefile of subproject. Available only on platforms that use makefiles.
#.target	Base string used for makefile targets related to this subproject. Available only on platforms that use makefiles.

libNGZBaiDu.file = $$PWD/NGZBaiDu/NGZBaiDu.pro
binBaiDuTieBa.file = $$PWD/BaiDuTieBa/BaiDuTieBa.pro
binBaiDuTieBa.depends += libNGZBaiDu

SUBDIRS += libNGZBaiDu \
    NGZBaiDuTest
SUBDIRS += libs/Boost
SUBDIRS += cct

SUBDIRS += binBaiDuTieBa










