
#if !defined(MULTIMAP__HPP__CCT)
#define MULTIMAP__HPP__CCT

#include <map>
#include <memory>

namespace cct{

    template<typename T,typename U>
    class Multimap : public std::shared_ptr< std::multimap<T,U> > {
    private:
        typedef std::shared_ptr< std::multimap<T,U> > Super;
    public:

        Multimap( decltype(nullptr) ) {}
        Multimap() :Super(new std::multimap<T,U> ){}
        Multimap(const Multimap &)=default;
        Multimap(Multimap &&)=default;
        Multimap(Super && o):Super( std::move(o) ) {}
        Multimap(const Super & o):Super( o ) {}
        Multimap(const std::multimap<T,U> & o):Super( new std::multimap<T,U>( o ) ) {}
        Multimap(std::multimap<T,U> && o):Super( new std::multimap<T,U>( std::move(o) ) ) {}

        Multimap&operator=(const Multimap&)=default;
        Multimap&operator=(Multimap&&)=default;

        Multimap copy() const { return Multimap( *(*this) ); }
        Multimap unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif


