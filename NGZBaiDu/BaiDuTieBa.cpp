#include "private/PBaiduTieBa.hpp"
#include "BaiDuTieBa.hpp"

BaiDuTieBa::BaiDuTieBa(QObject *parent) :
    QObject(parent){

    /*create thisp*/
    thisp = cct::make_unique_shared_ptr< BaiDuTieBaPrivate >();
    thisp->thisp = thisp;

    /*connect signals ans slot*/

}

std::shared_ptr<BaiDuUser> BaiDuTieBa::getBaiDuUser()const {
    return thisp->baiDuUser;
}

void BaiDuTieBa::setBaiDuUser(std::shared_ptr<BaiDuUser> u) {
    if (u) { if ( u->isLogin() ) { thisp->baiDuUser=u; } }
    else { thisp->baiDuUser.reset(); }
}

BaiDuTieBa::~BaiDuTieBa(){

    if (thisp) {
        disconnect(this,nullptr,thisp.get(),nullptr);
        disconnect(thisp.get(),nullptr,this,nullptr);
        thisp.reset();
    }

}


BaiDuTieBaPrivate::BaiDuTieBaPrivate(){

}

BaiDuTieBaPrivate::~BaiDuTieBaPrivate(){

}

SendTieBaDataPack::SendTieBaDataPack() {
}

SendTieBaDataPack::~SendTieBaDataPack() {
}

/*
 * endl of the file
*/
