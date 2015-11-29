
#if !defined(FORWARD_LIST__HPP__CCT)
#define FORWARD_LIST__HPP__CCT

#include <forward_list>
#include <memory>

namespace cct{

    template<typename T>
    class Forward_list : public std::shared_ptr< std::forward_list<T> > {
    private:
        typedef std::shared_ptr< std::forward_list<T> > Super;
    public:

        Forward_list( decltype(nullptr) ) {}
        Forward_list() :Super(new std::forward_list<T> ){}
        Forward_list(const Forward_list &)=default;
        Forward_list(Forward_list &&)=default;
        Forward_list(Super && o):Super( std::move(o) ) {}
        Forward_list(const Super & o):Super( o ) {}
        Forward_list(const std::forward_list<T> & o):Super( new std::forward_list<T>( o ) ) {}
        Forward_list(std::forward_list<T> && o):Super( new std::forward_list<T>( std::move(o) ) ) {}

        Forward_list&operator=(const Forward_list&)=default;
        Forward_list&operator=(Forward_list&&)=default;

        Forward_list copy() const { return Forward_list( *(*this) ); }
        Forward_list unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif



