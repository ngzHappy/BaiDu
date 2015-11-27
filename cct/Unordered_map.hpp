
#if !defined(UNORDERED_MAP__HPP__CCT)
#define UNORDERED_MAP__HPP__CCT

#include <unordered_map>
#include <memory>

namespace cct{

    template<typename T,typename U>
    class Unordered_map : public std::shared_ptr< std::unordered_map<T,U> > {
    private:
        typedef std::shared_ptr< std::unordered_map<T,U> > Super;
    public:
    
        template<typename ... Ta>
        Unordered_map(Ta && ... args):Super(new std::unordered_map<T,U>( std::forward<Ta>(args) ... ) ) {}
        Unordered_map( decltype(nullptr) ) {}
        Unordered_map() :Super(new std::unordered_map<T,U> ){}
        Unordered_map(const Unordered_map &)=default;
        Unordered_map(Unordered_map &&)=default;
        Unordered_map(Super && o):Super( std::move(o) ) {}
        Unordered_map(const Super & o):Super( o ) {}

        Unordered_map&operator=(const Unordered_map&)=default;
        Unordered_map&operator=(Unordered_map&&)=default;
        
        Unordered_map copy() const { return Unordered_map( *(*this) ); }
        Unordered_map unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif


