#if !defined(OBJECT_DELETE_CCT)
#define OBJECT_DELETE_CCT

#include <memory>
#include <utility>
#include <cstddef>
#include <type_traits>
namespace cct {

    template<typename T,
        typename FunctionType=void(*)(typename std::remove_all_extents<T>::type *) >
    class ObjectDelete {
        std::unique_ptr< T, FunctionType > obj;
    public:
        ObjectDelete(decltype(nullptr)) : obj(nullptr, [](T *) {}) {}
        ObjectDelete() :ObjectDelete(nullptr) {}
        ObjectDelete(T * d, FunctionType && f) :obj(d, std::forward<FunctionType>(f)) {}
        ObjectDelete(T * d) :obj(d, [](T * _d) {delete _d; }) {}

        ObjectDelete(ObjectDelete && o) :obj(std::move(o.obj)) {  }
        ObjectDelete & operator=(ObjectDelete && o) {
            if (this==&o) { return *this; }
            std::swap(this->obj, o.obj);
            ObjectDelete null_;
            std::swap(null_.obj, o.obj);
            return *this;
        }

        ObjectDelete(const ObjectDelete &)=delete;
        ObjectDelete& operator=(const ObjectDelete &)=delete;
    };

    template<typename T, typename FunctionType >
    class ObjectDelete<T[], FunctionType > {
        std::unique_ptr<T, FunctionType > obj;
    public://not surport
        ObjectDelete(decltype(nullptr)) : obj(nullptr, [](T *) {}) {}
        ObjectDelete() :ObjectDelete(nullptr) {}
        ObjectDelete(T * d, FunctionType && f) :obj(d, std::forward<FunctionType>(f)) {}
        ObjectDelete(T * d) :obj(d, [](T * _d) {delete[] _d; }) {}

        ObjectDelete(ObjectDelete && o) :obj(std::move(o.obj)) {  }
        ObjectDelete & operator=(ObjectDelete && o) {
            if (this==&o) { return *this; }
            std::swap(this->obj, o.obj);
            ObjectDelete null_;
            std::swap(null_.obj, o.obj);
            return *this;
        }

        ObjectDelete(const ObjectDelete &)=delete;
        ObjectDelete& operator=(const ObjectDelete &)=delete;
    };

    template<typename T, std::size_t N, typename FunctionType >
    class ObjectDelete<T[N], FunctionType > {
        std::unique_ptr<T, FunctionType > obj;
    public://not surport
        ObjectDelete(decltype(nullptr)) : obj(nullptr, [](T *) {}) {}
        ObjectDelete() :ObjectDelete(nullptr) {}
        ObjectDelete(T * d, FunctionType && f) :obj(d, std::forward<FunctionType>(f)) {}
        ObjectDelete(T * d) :obj(d, [](T * _d) {delete[] _d; }) {}

        ObjectDelete(ObjectDelete && o) :obj(std::move(o.obj)) {  }
        ObjectDelete & operator=(ObjectDelete && o) {
            if (this==&o) { return *this; }
            std::swap(this->obj, o.obj);
            ObjectDelete null_;
            std::swap(null_.obj, o.obj);
            return *this;
        }

        ObjectDelete(const ObjectDelete &)=delete;
        ObjectDelete& operator=(const ObjectDelete &)=delete;
    };

}

#endif
