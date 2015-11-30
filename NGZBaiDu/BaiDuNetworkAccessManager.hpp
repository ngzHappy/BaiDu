#if !defined( BAIDUNETWORKACCESSMANAGER_HPP )
#define BAIDUNETWORKACCESSMANAGER_HPP

#include <mutex>
#include <QNetworkAccessManager>
#include "ngzbaidu_global.hpp"
#include <Set.hpp>

class NGZBAIDUSHARED_EXPORT BaiDuNetworkAccessManager :
        public QNetworkAccessManager{
    Q_OBJECT
private:
    std::recursive_mutex reply_mutex;
    cct::Set< std::shared_ptr<QNetworkReply> > replys;
public:
    BaiDuNetworkAccessManager( QObject * o) :QNetworkAccessManager(o){}

    void addReply( std::shared_ptr<QNetworkReply> r ) {
        {
            std::unique_lock<std::recursive_mutex> __lock(reply_mutex);
            if (replys) { replys->insert(r); }
        }

    }

    template< typename Tp >
    void removeReply( Tp r ) {
        {
            std::unique_lock<std::recursive_mutex> __lock(reply_mutex);
            if (replys) {  replys->erase( r );  }
        }
    }

    ~BaiDuNetworkAccessManager() {
        {
            std::unique_lock<std::recursive_mutex> __lock;
            if (replys) { replys.reset();/*/close all replys*/ }
        }

    }
};


#endif // BAIDUNETWORKACCESSMANAGER_HPP
