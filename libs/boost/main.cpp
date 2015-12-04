#include <iostream>
// bcp "boost/algorithm/string.hpp" ""
using namespace std;

#include <boost/algorithm/string.hpp>
#include <QString>
#include <string>

int main()
{
    cout << "Hello World!" << endl;
    QString temp("aabbccdd");

    // char test[]="aabbccdd   ";

    auto ans = temp.toStdU16String();
    temp.fromStdU16String( boost::trim_right_copy( ans ) );
    return 0;
}

