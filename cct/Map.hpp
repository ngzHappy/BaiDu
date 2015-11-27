
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
    
        template<typename ... Ta>
        Map(Ta && ... args):Super(new std::map<T,U>( std::forward<Ta>(args) ... ) ) {}
        Map( decltype(nullptr) ) {}
        Map() :Super(new std::map<T,U> ){}
        Map(const Map &)=default;
        Map(Map &&)=default;
        Map(Super && o):Super( std::move(o) ) {}
        Map(const Super & o):Super( o ) {}

        Map&operator=(const Map&)=default;
        Map&operator=(Map&&)=default;
        
        Map copy() const { return Map( *(*this) ); }
        Map unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif


