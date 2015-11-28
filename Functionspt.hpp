           
namespace spt{

    class Function : public std::shared_ptr< class std::Function > {
    private:
        typedef std::shared_ptr< class std::Function > Super;
    public:

        template<typename ... Ta>
        Function(Ta && ... args):Super(new class std::Function( std::forward<Ta>(args) ... ) ) {}
        Function( decltype(nullptr) ) {}
        Function() :Super( new class std::Function ){}
        Function(const Function &)=default;
        Function(Function &&)=default;
        Function(Super && o):Super( std::move(o) ) {}
        Function(const Super & o):Super( o ) {}

        Function&operator=(const Function&)=default;
        Function&operator=(Function&&)=default;
        
        Function copy() const { return Function( *(*this) ); }
        Function unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }
        
    };

}

