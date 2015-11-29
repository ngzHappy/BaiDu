
#if !defined(UNORDERED_MULTISET__HPP__CCT)
#define UNORDERED_MULTISET__HPP__CCT

#include <unordered_set>
#include <memory>

namespace cct{

    template<typename T>
    class Unordered_multiset : public std::shared_ptr< std::unordered_multiset<T> > {
    private:
        typedef std::shared_ptr< std::unordered_multiset<T> > Super;
    public:

        Unordered_multiset( decltype(nullptr) ) {}
        Unordered_multiset() :Super(new std::unordered_multiset<T> ){}
        Unordered_multiset(const Unordered_multiset &)=default;
        Unordered_multiset(Unordered_multiset &&)=default;
        Unordered_multiset(Super && o):Super( std::move(o) ) {}
        Unordered_multiset(const Super & o):Super( o ) {}
        Unordered_multiset(const std::unordered_multiset<T> & o):Super( new std::unordered_multiset<T>( o ) ) {}
        Unordered_multiset(std::unordered_multiset<T> && o):Super( new std::unordered_multiset<T>( std::move(o) ) ) {}

        Unordered_multiset&operator=(const Unordered_multiset&)=default;
        Unordered_multiset&operator=(Unordered_multiset&&)=default;

        Unordered_multiset copy() const { return Unordered_multiset( *(*this) ); }
        Unordered_multiset unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif



