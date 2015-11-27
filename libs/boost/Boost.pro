TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
CONFIG += c++14
SOURCES += main.cpp
CONFIG += core
CONFIG += gui

INCLUDEPATH += $$PWD/..

HEADERS +=  $$PWD/assert.hpp
HEADERS +=  $$PWD/checked_delete.hpp
HEADERS +=  $$PWD/concept_check.hpp
HEADERS +=  $$PWD/config.hpp
HEADERS +=  $$PWD/cstdint.hpp
HEADERS +=  $$PWD/current_function.hpp
HEADERS +=  $$PWD/function.hpp
HEADERS +=  $$PWD/function_equal.hpp
HEADERS +=  $$PWD/get_pointer.hpp
HEADERS +=  $$PWD/integer.hpp
HEADERS +=  $$PWD/integer_fwd.hpp
HEADERS +=  $$PWD/integer_traits.hpp
HEADERS +=  $$PWD/iterator.hpp
HEADERS +=  $$PWD/limits.hpp
HEADERS +=  $$PWD/mem_fn.hpp
HEADERS +=  $$PWD/next_prior.hpp
HEADERS +=  $$PWD/noncopyable.hpp
HEADERS +=  $$PWD/ref.hpp
HEADERS +=  $$PWD/static_assert.hpp
HEADERS +=  $$PWD/throw_exception.hpp
HEADERS +=  $$PWD/utility.hpp
HEADERS +=  $$PWD/version.hpp


