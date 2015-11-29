
#if !defined(MAP__HPP__CCT)
#define MAP__HPP__CCT

#include <map>
#include <memory>

namespace cct{

    template<typename T,typename U>
    class Map : public std::shared_ptr< std::map<T,U> > {
    private:
        typedef std::shared_ptr< std::map<T,U> > Super;
    public:

        Map( decltype(nullptr) ) {}
        Map() :Super(new std::map<T,U> ){}
        Map(const Map &)=default;
        Map(Map &&)=default;
        Map(Super && o):Super( std::move(o) ) {}
        Map(const Super & o):Super( o ) {}
        Map(const std::map<T,U> & o):Super( new std::map<T,U>( o ) ) {}
        Map(std::map<T,U> && o):Super( new std::map<T,U>( std::move(o) ) ) {}

        Map&operator=(const Map&)=default;
        Map&operator=(Map&&)=default;

        Map copy() const { return Map( *(*this) ); }
        Map unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif


