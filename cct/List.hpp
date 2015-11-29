
#if !defined(LIST__HPP__CCT)
#define LIST__HPP__CCT

#include <list>
#include <memory>

namespace cct{

    template<typename T>
    class List : public std::shared_ptr< std::list<T> > {
    private:
        typedef std::shared_ptr< std::list<T> > Super;
    public:

        List( decltype(nullptr) ) {}
        List() :Super(new std::list<T> ){}
        List(const List &)=default;
        List(List &&)=default;
        List(Super && o):Super( std::move(o) ) {}
        List(const Super & o):Super( o ) {}
        List(const std::list<T> & o):Super( new std::list<T>( o ) ) {}
        List(std::list<T> && o):Super( new std::list<T>( std::move(o) ) ) {}

        List&operator=(const List&)=default;
        List&operator=(List&&)=default;

        List copy() const { return List( *(*this) ); }
        List unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif



