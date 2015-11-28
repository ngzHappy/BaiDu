#ifndef pQCOMPRESSOR_Hgzip
#define pQCOMPRESSOR_Hgzip


#include <QByteArray>
#include <memory>


namespace gzip {

class QCompressor
{
public:

    static bool gzipCompress(QByteArray input, QByteArray &output, int level = -1);
    static bool gzipDecompress(QByteArray input, QByteArray &output);

    template<typename T>
    static QByteArray gzipDecompress(T && input){
        QByteArray ans ;
        if( gzipDecompress( std::forward<T>(input) ,ans ) ){
            return std::move(ans);
        }
        ans.clear();
        return ans ;
    }

};

}


#endif // QCOMPRESSOR_H

/*
 * endl of the file
*/
