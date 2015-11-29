
#if !defined(PRIORITY_QUEUE__HPP__CCT)
#define PRIORITY_QUEUE__HPP__CCT

#include <queue>
#include <memory>

namespace cct{

    template<typename T>
    class Priority_queue : public std::shared_ptr< std::priority_queue<T> > {
    private:
        typedef std::shared_ptr< std::priority_queue<T> > Super;
    public:

        Priority_queue( decltype(nullptr) ) {}
        Priority_queue() :Super(new std::priority_queue<T> ){}
        Priority_queue(const Priority_queue &)=default;
        Priority_queue(Priority_queue &&)=default;
        Priority_queue(Super && o):Super( std::move(o) ) {}
        Priority_queue(const Super & o):Super( o ) {}
        Priority_queue(const std::priority_queue<T> & o):Super( new std::priority_queue<T>( o ) ) {}
        Priority_queue(std::priority_queue<T> && o):Super( new std::priority_queue<T>( std::move(o) ) ) {}

        Priority_queue&operator=(const Priority_queue&)=default;
        Priority_queue&operator=(Priority_queue&&)=default;

        Priority_queue copy() const { return Priority_queue( *(*this) ); }
        Priority_queue unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif



