#ifndef TIEBAFORMATDATA_HPP
#define TIEBAFORMATDATA_HPP

#include <list>
#include <QString>
#include <map>
#include "ngzbaidu_global.hpp"

/*
<:/title> 标题名
<:/data>  表示一个新的记录
<:/text>  文本
<:/image> 图片相对路径
*/

class NGZBAIDUSHARED_EXPORT TieBaTextImageType : 
    public QString {
    static QString temp_null_data_;
public:
    using QString::QString;
    QString width         ;
    QString height        ;
    QString type          ;// jpeg ="1";
    bool isImage=false;
    TieBaTextImageType & operator=(const QString & v) {
        QString::operator=(v);
        return *this;
    }
    TieBaTextImageType();
    TieBaTextImageType(const QString & v):QString(v) {}
    TieBaTextImageType(const QString & v,bool i):QString(v),isImage(i) {}
    TieBaTextImageType( decltype(nullptr) ):TieBaTextImageType(){}
    TieBaTextImageType & operator=(const TieBaTextImageType &)=default;
    TieBaTextImageType & operator=(TieBaTextImageType &&)=default;
    TieBaTextImageType(const TieBaTextImageType &)=default;
    TieBaTextImageType(TieBaTextImageType &&)=default;

}; 

class NGZBAIDUSHARED_EXPORT TieBaFormatData 
    :public std::list< TieBaTextImageType >
{
public:     

    TieBaFormatData(  );
    TieBaFormatData( decltype(nullptr) ) {}

    TieBaFormatData(const TieBaFormatData &) = default;
    TieBaFormatData(TieBaFormatData &&) = default;

    TieBaFormatData&operator=(const TieBaFormatData &) = default;
    TieBaFormatData&operator=(TieBaFormatData &&) = default;
    
    static std::shared_ptr<TieBaFormatData> instance();
    
    std::map<QString,TieBaTextImageType> localPath2HtmlPath;

protected:
    ~TieBaFormatData();
private:
};

class NGZBAIDUSHARED_EXPORT BaiDuTieBaFormatDatas
    :public std::list< std::shared_ptr<TieBaFormatData>  >
{
public:

    QString title;   /*帖子的标题*/
    QString fileDir; /*读取图片时的根目录*/

    void read( const QString & );
    void write( const QString & );

    BaiDuTieBaFormatDatas &operator=( decltype(nullptr) ){
        this->clear(); title.clear(); fileDir.clear();
        return *this;
    }

    BaiDuTieBaFormatDatas(  ) {}
    BaiDuTieBaFormatDatas( decltype(nullptr) ) {}

    BaiDuTieBaFormatDatas(const BaiDuTieBaFormatDatas &) = default;
    BaiDuTieBaFormatDatas(BaiDuTieBaFormatDatas &&) = default;

    BaiDuTieBaFormatDatas& operator=(const BaiDuTieBaFormatDatas &) = default;
    BaiDuTieBaFormatDatas& operator=(BaiDuTieBaFormatDatas &&) = default;

    static std::shared_ptr< BaiDuTieBaFormatDatas > instance();

protected:
    ~BaiDuTieBaFormatDatas() {}

};

#endif // TIEBAFORMATDATA_HPP
