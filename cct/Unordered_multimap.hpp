
#if !defined(UNORDERED_MULTIMAP__HPP__CCT)
#define UNORDERED_MULTIMAP__HPP__CCT

#include <unordered_map>
#include <memory>

namespace cct{

    template<typename T,typename U>
    class Unordered_multimap : public std::shared_ptr< std::unordered_multimap<T,U> > {
    private:
        typedef std::shared_ptr< std::unordered_multimap<T,U> > Super;
    public:

        Unordered_multimap( decltype(nullptr) ) {}
        Unordered_multimap() :Super(new std::unordered_multimap<T,U> ){}
        Unordered_multimap(const Unordered_multimap &)=default;
        Unordered_multimap(Unordered_multimap &&)=default;
        Unordered_multimap(Super && o):Super( std::move(o) ) {}
        Unordered_multimap(const Super & o):Super( o ) {}
        Unordered_multimap(const std::unordered_multimap<T,U> & o):Super( new std::unordered_multimap<T,U>( o ) ) {}
        Unordered_multimap(std::unordered_multimap<T,U> && o):Super( new std::unordered_multimap<T,U>( std::move(o) ) ) {}

        Unordered_multimap&operator=(const Unordered_multimap&)=default;
        Unordered_multimap&operator=(Unordered_multimap&&)=default;

        Unordered_multimap copy() const { return Unordered_multimap( *(*this) ); }
        Unordered_multimap unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif


