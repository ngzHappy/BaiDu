
#if !defined(VECTOR__HPP__CCT)
#define VECTOR__HPP__CCT

#include <vector>
#include <memory>

namespace cct{

    template<typename T>
    class Vector : public std::shared_ptr< std::vector<T> > {
    private:
        typedef typename std::vector<T>::size_type size_type ;
        typedef std::shared_ptr< std::vector<T> > Super;
        const std::vector<T> * _get_const()const{return this->get();}
    public:

        Vector( decltype(nullptr) ) {}
        Vector() :Super(new std::vector<T> ){}
        Vector(const Vector &)=default;
        Vector(Vector &&)=default;
        Vector(Super && o):Super( std::move(o) ) {}
        Vector(const Super & o):Super( o ) {}
        Vector(const std::vector<T> & o):Super( new std::vector<T>( o ) ) {}
        Vector(std::vector<T> && o):Super( new std::vector<T>( std::move(o) ) ) {}

        Vector&operator=(const Vector&)=default;
        Vector&operator=(Vector&&)=default;

        auto operator[]( size_type n )->decltype( this->get()->operator[](n)  ) {
            return this->get()->operator[](n);
        }

        auto operator[]( size_type n )const ->decltype( this->_get_const()->operator[](n)  ) {
            return this->_get_const()->operator[](n);
        }

        Vector copy() const { return Vector( *(*this) ); }
        Vector unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

}

#endif



