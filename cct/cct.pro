TEMPLATE  = app
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt
CONFIG   += c++14
SOURCES  += main.cpp

HEADERS +=$$PWD/Map.hpp
HEADERS +=$$PWD/FunctionType.hpp
HEADERS +=$$PWD/UniqueSharedPointer.hpp
HEADERS +=$$PWD/SharedFromSuper.hpp
HEADERS +=$$PWD/String.hpp
HEADERS +=$$PWD/Function.hpp
HEADERS +=$$PWD/TempOptional.hpp
HEADERS +=$$PWD/Multimap.hpp
HEADERS +=$$PWD/Multiset.hpp
HEADERS +=$$PWD/ObjectDelete.hpp
HEADERS +=$$PWD/Priority_queue.hpp
HEADERS +=$$PWD/Queue.hpp
HEADERS +=$$PWD/Set.hpp
HEADERS +=$$PWD/Stack.hpp
HEADERS +=$$PWD/TemplateString.hpp
HEADERS +=$$PWD/Unordered_map.hpp
HEADERS +=$$PWD/Unordered_multimap.hpp
HEADERS +=$$PWD/Unordered_multiset.hpp
HEADERS +=$$PWD/Unordered_set.hpp
HEADERS +=$$PWD/Vector.hpp
HEADERS +=$$PWD/CheckArgs.hpp
HEADERS +=$$PWD/Containers.hpp
HEADERS +=$$PWD/Deque.hpp
HEADERS +=$$PWD/Forward_list.hpp
HEADERS +=$$PWD/List.hpp

unix {
    QMAKE_LFLAGS += -Wl,-rpath .
}
