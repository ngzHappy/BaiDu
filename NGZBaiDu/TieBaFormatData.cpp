#include "TieBaFormatData.hpp"
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QDir>
#include <QTextCodec>
#include <set>
#include <QList>
#include <QDebug>

QString TieBaTextImageType::temp_null_data_;

namespace
{
// '\t', '\n', '\v', '\f', '\r', and ' '.
QString trimAfter(QString data) {
    if (data.isEmpty()) { return QString(); }
    auto end_ = data.cend();
    const auto begin_=data.cbegin();
    auto pos_=end_;
    QString ans;
    const static std::set<QChar> set_{ '\t', '\n', '\v', '\f', '\r',  ' '};
    for (;begin_!=end_;--end_) {
        pos_=end_-1;
        QChar char_ = *pos_;
        if (set_.count(char_)>0) { continue; }
        break;
    }

    if (pos_==begin_) { return QString(); }
    if (pos_==(data.cend()-1)) { return data; }

    return data.left( ( pos_- begin_ ) + 1 );

}

}

TieBaFormatData::TieBaFormatData(){

}

TieBaFormatData::~TieBaFormatData(){

}

TieBaTextImageType::TieBaTextImageType()
    :QString( temp_null_data_ ),
    width(temp_null_data_),
    height(temp_null_data_),
    type(temp_null_data_){

}

void TieBaFormatData::read(QTextStream & stream ){
    bool isDataRead=false;
    while ( stream.atEnd()==false ) {
        QString line=stream.readLine();

        if ( line.startsWith("<:/image>") ) {
            TieBaTextImageType item = line.mid(9).trimmed() ;
            item.isImage=true;
            if ( item.startsWith("http://") ) {
                auto a=item.split("!!!");
                if (a.size()!=4) { return; }
                auto i_=a.cbegin();
                item=*i_++; item.width=*i_++; item.height=*i_++; item.type=*i_++;
            }
            isDataRead=true;
            push_back( item );
            continue;
        }

        if (line.startsWith("<:/text>")) {
            TieBaTextImageType item = line.mid(8)+"\n" ;
            item.isImage=false;
            isDataRead=true;
            push_back(item);
            continue;
        }

        if (isDataRead) {
            if (empty()) { return; }
            auto & i = *(this->rbegin());
            i.push_back( line+"\n" );
            continue;
        }

    }

    for (auto & i:*this) {
        if ( i.isImage ) { continue; }
        i=trimAfter(i)+"\n";
    }
}

void TieBaFormatData::write(QTextStream & stream ) const {

    for (const auto & i:*this) {
        if (i.isImage) {
            if (i.startsWith("http://")) {
                stream<<"<:/image>"<<i<<"!!!"<<i.width<<"!!!"<<i.height<<"!!!"<<i.type;
                stream<<'\n';
            }
            else {
                stream<<i<<'\n';
            }
        }
        else {
            stream<<"<:/text>"<<i;
        }
    }

}

void TieBaFormatData::read(const QString & fileName) {

    QFile file( fileName );
    if (file.exists()==false) { return; }
    this->clear();
    if (false==file.open(QIODevice::ReadOnly|QIODevice::Text)) {
        return;
    }
    QTextStream stream( &file );
    stream.setCodec( QTextCodec::codecForName("UTF-8") );
    read(stream);

}

void TieBaFormatData::write(const QString & fileName) const {

    QFile file( fileName );
    if (false==file.open(QIODevice::WriteOnly)) { return; }
    if (empty()) { return; }
    QTextStream stream( &file );
    stream.setCodec( QTextCodec::codecForName("UTF-8") );
    write(stream);
}

std::shared_ptr<TieBaFormatData > TieBaFormatData::instance() {
    auto * d=new TieBaFormatData;
    return std::shared_ptr<TieBaFormatData >(d,[](auto *p) {delete p; });
}

namespace {
class TieBaFormatDataReadError {
    QString what_;
public:
    const QString & what() const { return what_; }
    TieBaFormatDataReadError(const QString &v) { what_=v; }
};
}

void BaiDuTieBaFormatDatas::read(const QString & filename) try{
    *this = nullptr ;
    const static TieBaFormatDataReadError error_("error");

    QFile file( filename );
    if (file.exists()==false) {
        throw TieBaFormatDataReadError("can not find file");
    }

    if (file.open(QIODevice::ReadOnly|QIODevice::Text)==false) {
        throw TieBaFormatDataReadError("can not open file");
    }

    QTextStream stream( &file );
    stream.setCodec( QTextCodec::codecForName("UTF-8") );
    {
        QFileInfo info( filename );
        fileDir = info.absoluteDir().absolutePath() ;
    }

    bool isTitleRead=false;
    bool isDataRead=false;

    while (stream.atEnd()==false) {

        QString line=stream.readLine();

        if ( (isTitleRead==false) || (isDataRead==false) ) {
            //忽略title之前的空行
            //忽略第一个data之前的空行
            if (line.trimmed().isEmpty()) { continue; }
        }

        if ( line.startsWith(u8R"(<:/title>)") ) {
            if (isTitleRead) {
                throw TieBaFormatDataReadError("multi title");/*只能有一个title*/
            }
            title=line.mid( 9 ).trimmed();
            isTitleRead=true;
            continue;
        }

        if ( line.startsWith(u8R"(<:/data>)") ) {
            isDataRead=true;
            push_back( TieBaFormatData::instance() ); /*插入新记录*/
            continue;
        }

        if (line.startsWith(u8R"(<:/text>)")) {
            if (empty()) { throw error_; }
            auto & item_ =  *rbegin() ;
            item_->emplace_back( line.mid(8) );
            continue;
        }

        if ( line.startsWith(u8R"(<:/image>)") )  {
            if (empty()) { throw error_; }
            auto & item_ =  *rbegin() ;
            item_->emplace_back( line.mid(9).trimmed(),true );
            continue;
        }

        //追加文本
        if ( empty() ) { throw error_; }
        auto & item_ =  *rbegin() ;
        if ( item_->empty() ) { throw error_; }
        auto & item_data_text_ = * item_->rbegin();
        item_data_text_.push_back("\n");
        item_data_text_.push_back(line);

    }

    {//删除多余空白
        for ( auto & i:(*this) ) {
            for ( auto & j : *i  ) {
                if (j.isImage /*图片*/ ) {
                    auto temp=j.trimmed();
                    if ( j.startsWith("http://") ) {
                        auto a = j.split("!!!");
                        if (a.size()!=4) { throw TieBaFormatDataReadError("http image formate error"); }
                        auto f=a.begin();
                        j=*f++; j.width=*f++; j.height=*f++; j.type=*f++;
                    }
                    else {
                        j  = temp ;
                    }
                    continue;
                }
                /*文本*/
                QString temp = trimAfter( j ) ;
                j  = temp ;
                j.append('\n');
            }
        }
    }

}catch ( const TieBaFormatDataReadError & e ) {
    qDebug()<<e.what();
    *this = nullptr ;
}

void BaiDuTieBaFormatDatas::write(const QString & filename ) try{

    QFile file( filename );
    QTextStream stream( &file );
    if (file.open(QIODevice::WriteOnly|QIODevice::Text)==false) {
        throw TieBaFormatDataReadError("can not open file");
    }

    stream.setCodec( QTextCodec::codecForName("UTF-8") );

    int data_index=0;
    stream<<"<:/title>"<<title<<'\n';
    for ( auto & i:(*this) ) {
        stream<<"<:/data>"<< (data_index++) <<'\n';
        for ( auto & j : *i  ) {
            if (j.isImage /*图片*/ ) {
                stream<<"<:/image>";
                if ( j.startsWith("http://") ) {
                    stream<<j<<"!!!"<<j.width<<"!!!"<<j.height<<"!!!"<<j.type<<'\n' ;
                }
                else {
                    stream<<j<<'\n';
                }
                continue;
            }
            /*文本*/
            stream<<"<:/text>";
            stream<<j;
        }
    }

}catch ( const TieBaFormatDataReadError & e ) {
    qDebug()<<e.what();
}

std::shared_ptr<BaiDuTieBaFormatDatas > BaiDuTieBaFormatDatas::instance() {
    auto * d=new BaiDuTieBaFormatDatas;
    return std::shared_ptr<BaiDuTieBaFormatDatas >(d,[](auto *p) {delete p; });
}

/*
*/
