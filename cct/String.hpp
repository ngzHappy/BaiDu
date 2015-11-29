#if !defined(STRING__HPP__CPP)
#define STRING__HPP__CPP

#include <string>
#include <memory>

namespace cct{
    
    class string : public std::shared_ptr< std::string > {
    private:
        typedef std::shared_ptr< std::string > Super;
    public:
                
        string( decltype(nullptr) ) {}
        string() :Super( new std::string ){}
        string(const string &)=default;
        string(string &&)=default;
        string(Super && o):Super( std::move(o) ) {}
        string(const Super & o):Super( o ) {}
        string(const std::string & o):Super( new std::string(o) ) {}
        string(std::string && o):Super( new std::string( std::move(o) ) ) {}

        string&operator=(const string&)=default;
        string&operator=(string&&)=default;

        string copy() const { return string( *(*this) ); }
        string unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

    class wstring : public std::shared_ptr< std::wstring > {
    private:
        typedef std::shared_ptr< std::wstring > Super;
    public:

        wstring( decltype(nullptr) ) {}
        wstring() :Super( new std::wstring ){}
        wstring(const wstring &)=default;
        wstring(wstring &&)=default;
        wstring(Super && o):Super( std::move(o) ) {}
        wstring(const Super & o):Super( o ) {}
        wstring(const std::wstring & o):Super( new std::wstring(o) ) {}
        wstring(std::wstring && o):Super( new std::wstring( std::move(o) ) ) {}

        wstring&operator=(const wstring&)=default;
        wstring&operator=(wstring&&)=default;

        wstring copy() const { return wstring( *(*this) ); }
        wstring unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

    class u16string : public std::shared_ptr< std::u16string > {
    private:
        typedef std::shared_ptr< std::u16string > Super;
    public:

        u16string( decltype(nullptr) ) {}
        u16string() :Super( new std::u16string ){}
        u16string(const u16string &)=default;
        u16string(u16string &&)=default;
        u16string(Super && o):Super( std::move(o) ) {}
        u16string(const Super & o):Super( o ) {}
        u16string(const std::u16string & o):Super( new std::u16string(o) ) {}
        u16string(std::u16string && o):Super( new std::u16string( std::move(o) ) ) {}

        u16string&operator=(const  u16string&)=default;
        u16string&operator=( u16string&&)=default;

        u16string copy() const { return u16string( *(*this) ); }
        u16string unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

    class u32string : public std::shared_ptr< std::u32string > {
    private:
        typedef std::shared_ptr< std::u32string > Super;
    public:

        u32string( decltype(nullptr) ) {}
        u32string() :Super( new std::u32string ){}
        u32string(const u32string &)=default;
        u32string(u32string &&)=default;
        u32string(Super && o):Super( std::move(o) ) {}
        u32string(const Super & o):Super( o ) {}
        u32string(const std::u32string & o):Super( new std::u32string(o) ) {}
        u32string(std::u32string && o):Super( new std::u32string( std::move(o) ) ) {}

        u32string&operator=(const  u32string&)=default;
        u32string&operator=( u32string&&)=default;

        u32string copy() const { return u32string( *(*this) ); }
        u32string unique_copy() const { if (this->use_count()<2) { return *this; }return copy(); }

    };

    typedef string String;
    typedef wstring WString;
    typedef u32string U32String;
    typedef u16string U16String;
}

#endif // !


