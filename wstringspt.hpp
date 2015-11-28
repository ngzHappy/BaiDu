           
namespace spt{

    class wstring : public std::shared_ptr< class std::wstring > {
    private:
        typedef std::shared_ptr< class std::wstring > Super;
    public:

        template<typename ... Ta>
        wstring(Ta && ... args):Super(new class std::wstring( std::forward<Ta>(args) ... ) ) {}
        wstring( decltype(nullptr) ) {}
        wstring() :Super( new class std::wstring ){}
        wstring(const wstring &)=default;
        wstring(wstring &&)=default;
        wstring(Super && o):Super( std::move(o) ) {}
        wstring(const Super & o):Super( o ) {}

        wstring&operator=(const wstring&)=default;
        wstring&operator=(wstring&&)=default;
        
        wstring copy() const { return wstring( *(*this) ); }
        wstring unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }
        
    };

}

