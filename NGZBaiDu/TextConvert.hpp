#if  !defined(TEXTCONVERT_HPP)
#define TEXTCONVERT_HPP

#include<vector>

//Traditional Chinese character <==> tc
class TextConvert
{
public:
    TextConvert();
    static std::vector<char16_t> c2tc( char16_t );
    static std::vector<char16_t> tc2c( char16_t );

};

#endif // TEXTCONVERT_HPP
