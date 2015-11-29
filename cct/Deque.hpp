
#if !defined(DEQUE__HPP__CCT)
#define DEQUE__HPP__CCT

#include <deque>
#include <memory>

namespace cct{

    template<typename T>
    class Deque : public std::shared_ptr< std::deque<T> > {
    private:
        typedef std::shared_ptr< std::deque<T> > Super;
    public:

        Deque( decltype(nullptr) ) {}
        Deque() :Super(new std::deque<T> ){}
        Deque(const Deque &)=default;
        Deque(Deque &&)=default;
        Deque(Super && o):Super( std::move(o) ) {}
        Deque(const Super & o):Super( o ) {}
        Deque(const std::deque<T> & o):Super( new std::deque<T>( o ) ) {}
        Deque(std::deque<T> && o):Super( new std::deque<T>( std::move(o) ) ) {}

        Deque&operator=(const Deque&)=default;
        Deque&operator=(Deque&&)=default;

        Deque copy() const { return Deque( *(*this) ); }
        Deque unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif



