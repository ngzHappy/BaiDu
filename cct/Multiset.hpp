
#if !defined(MULTISET__HPP__CCT)
#define MULTISET__HPP__CCT

#include <set>
#include <memory>

namespace cct{

    template<typename T>
    class Multiset : public std::shared_ptr< std::multiset<T> > {
    private:
        typedef std::shared_ptr< std::multiset<T> > Super;
    public:

        Multiset( decltype(nullptr) ) {}
        Multiset() :Super(new std::multiset<T> ){}
        Multiset(const Multiset &)=default;
        Multiset(Multiset &&)=default;
        Multiset(Super && o):Super( std::move(o) ) {}
        Multiset(const Super & o):Super( o ) {}
        Multiset(const std::multiset<T> & o):Super( new std::multiset<T>( o ) ) {}
        Multiset(std::multiset<T> && o):Super( new std::multiset<T>( std::move(o) ) ) {}

        Multiset&operator=(const Multiset&)=default;
        Multiset&operator=(Multiset&&)=default;

        Multiset copy() const { return Multiset( *(*this) ); }
        Multiset unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif



