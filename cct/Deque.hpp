
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

        template<typename ... Ta>
        Deque(Ta && ... args):Super(new std::deque<T>( std::forward<Ta>(args) ... ) ) {}
        Deque( decltype(nullptr) ) {}
        Deque() :Super(new std::deque<T> ){}
        Deque(const Deque &)=default;
        Deque(Deque &&)=default;
        Deque(Super && o):Super( std::move(o) ) {}
        Deque(const Super & o):Super( o ) {}
        
        Deque copy() const { return Deque( *(*this) ); }
        Deque unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }
        
    };

}

#endif



