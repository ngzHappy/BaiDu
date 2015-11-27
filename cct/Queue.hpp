
#if !defined(QUEUE__HPP__CCT)
#define QUEUE__HPP__CCT

#include <queue>
#include <memory>

namespace cct{

    template<typename T>
    class Queue : public std::shared_ptr< std::queue<T> > {
    private:
        typedef std::shared_ptr< std::queue<T> > Super;
    public:

        template<typename ... Ta>
        Queue(Ta && ... args):Super(new std::queue<T>( std::forward<Ta>(args) ... ) ) {}
        Queue( decltype(nullptr) ) {}
        Queue() :Super(new std::queue<T> ){}
        Queue(const Queue &)=default;
        Queue(Queue &&)=default;
        Queue(Super && o):Super( std::move(o) ) {}
        Queue(const Super & o):Super( o ) {}
        
        Queue&operator=(const Queue&)=default;
        Queue&operator=(Queue&&)=default;

        Queue copy() const { return Queue( *(*this) ); }
        Queue unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }
        
    };

}

#endif



