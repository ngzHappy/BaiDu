#if !defined(UNIQUE_SHAERED_PTR_CCT)
#define UNIQUE_SHAERED_PTR_CCT

#include <memory>
namespace cct
{

template<typename T>
class unique_shared_ptr :
    public std::shared_ptr<T> {
public:
    unique_shared_ptr() {}
    unique_shared_ptr( decltype(nullptr) ) {}
    unique_shared_ptr(const std::shared_ptr<T> &)=delete;
    unique_shared_ptr(const unique_shared_ptr &)=delete;
    unique_shared_ptr(std::shared_ptr<T> && o):std::shared_ptr<T>(std::move(o)){}
    unique_shared_ptr(unique_shared_ptr &&)=default;

    unique_shared_ptr & operator=( decltype(nullptr) ) {
        this->reset();return *this;
    }
    unique_shared_ptr & operator=(const unique_shared_ptr &)=delete ;
    unique_shared_ptr & operator=(unique_shared_ptr &&)=default;
    unique_shared_ptr & operator=(const std::shared_ptr<T> &)=delete ;
    unique_shared_ptr & operator=(std::shared_ptr<T> && o) {
        std::shared_ptr<T>::operator=( std::move(o) );return *this;
    }
};

template<typename T,typename ... Args>
unique_shared_ptr<T> make_unique_shared_ptr( Args && ... args ) {
    return unique_shared_ptr<T>( std::make_shared<T>( std::forward<Args>(args)... ) );
}



}



#endif

