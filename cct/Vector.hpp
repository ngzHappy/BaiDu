
#if !defined(VECTOR__HPP__CCT)
#define VECTOR__HPP__CCT

#include <vector>
#include <memory>

namespace cct{

    template<typename T>
    class Vector : public std::shared_ptr< std::vector<T> > {
    private:
        const std::vector<T> * _get_const()const { return this->get(); }
        typedef typename std::vector<T>::size_type size_type;
        typedef std::shared_ptr< std::vector<T> > Super;
    public:

        template<typename ... Ta>
        Vector(Ta && ... args):Super(new std::vector<T>( std::forward<Ta>(args) ... ) ) {}
        Vector( decltype(nullptr) ) {}
        Vector() :Super(new std::vector<T> ){}
        Vector(const Vector &)=default;
        Vector(Vector &&)=default;
        Vector(Super && o):Super( std::move(o) ) {}
        Vector(const Super & o):Super( o ) {}
        
        Vector&operator=(const Vector&)=default;
        Vector&operator=(Vector&&)=default;

        Vector copy() const { return Vector( *(*this) ); }
        Vector unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }
        
        auto operator[]( size_type n )->decltype( this->get()->operator[](n)  ) {
            return this->get()->operator[](n);
        }

        auto operator[]( size_type n )const ->decltype( this->_get_const()->operator[](n)  ) {
            return this->_get_const()->operator[](n);
        }

    };

}

#endif



