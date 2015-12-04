#ifndef FUNCTION_HPP__CCT
#define FUNCTION_HPP__CCT

#include <functional>
#include <memory>

namespace cct {

template<typename T>
class Function : public std::shared_ptr< std::function<T> > {
private:
    const std::function<T> * _get_const() const { return this->get(); }
    std::function<T> * _get(){ return this->get(); }
    typedef std::shared_ptr<  std::function<T> > Super;
public:
    template<typename ... Ta>
    Function(Ta && ... args):Super(new class std::function<T>( std::forward<Ta>(args) ... ) ) {}
    Function( decltype(nullptr) ) {}
    Function() :Super( new std::function<T> ){}
    Function(const Function &)=default;
    Function(Function &&)=default;
    Function(Super && o):Super( std::move(o) ) {}
    Function(const Super & o):Super( o ) {}

    Function&operator=(const Function&)=default;
    Function&operator=(Function&&)=default;

    Function copy() const { return Function( *(*this) ); }
    Function unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    template<typename ... Args >
    auto operator()( Args&& ... args ) ->decltype( this->_get()->operator()( std::forward<Args>(args) ...) ) {
        return this->_get()->operator()( std::forward<Args>(args) ...) ;
    }

    template<typename ... Args >
    auto operator()( Args&& ... args )const ->decltype( this->_get_const()->operator()( std::forward<Args>(args) ...) ) {
        return this->_get_const()->operator()( std::forward<Args>(args) ...) ;
    }

    explicit operator bool()const {
        auto * fun_=this->get();
        if (fun_) { if (*fun_) { return true; } }
        return false;
    }

};

}


#endif // FUNCTION_HPP


