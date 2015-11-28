           
namespace spt{

    class abc : public std::shared_ptr< class xx::abc > {
    private:
        typedef std::shared_ptr< class xx::abc > Super;
    public:

        template<typename ... Ta>
        abc(Ta && ... args):Super(new class xx::abc( std::forward<Ta>(args) ... ) ) {}
        abc( decltype(nullptr) ) {}
        abc() :Super( new class xx::abc ){}
        abc(const abc &)=default;
        abc(abc &&)=default;
        abc(Super && o):Super( std::move(o) ) {}
        abc(const Super & o):Super( o ) {}
        
        abc copy() const { return abc( *(*this) ); }
        abc unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }
        
    };

}

