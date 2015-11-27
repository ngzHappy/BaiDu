
#if !defined(STACK__HPP__CCT)
#define STACK__HPP__CCT

#include <stack>
#include <memory>

namespace cct{

    template<typename T>
    class Stack : public std::shared_ptr< std::stack<T> > {
    private:
        typedef std::shared_ptr< std::stack<T> > Super;
    public:

        template<typename ... Ta>
        Stack(Ta && ... args):Super(new std::stack<T>( std::forward<Ta>(args) ... ) ) {}
        Stack( decltype(nullptr) ) {}
        Stack() :Super(new std::stack<T> ){}
        Stack(const Stack &)=default;
        Stack(Stack &&)=default;
        Stack(Super && o):Super( std::move(o) ) {}
        Stack(const Super & o):Super( o ) {}
        
        Stack&operator=(const Stack&)=default;
        Stack&operator=(Stack&&)=default;

        Stack copy() const { return Stack( *(*this) ); }
        Stack unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }
        
    };

}

#endif



