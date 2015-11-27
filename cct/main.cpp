#include <iostream>

//test
#include "Containers.hpp"
#include "CheckArgs.hpp"
#include "TemplateString.hpp"
#include "Map.hpp"
#include "Function.hpp"
#include <Vector.hpp>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
 
    const cct::Function<int(void)> fun([]() {return 12; });
    if (fun) {
        auto xxx=fun();
        std::cout << xxx << std::endl;
    }

    cct::Map<int, double > a;
    cct::Map<int, double>b;
    cct::Vector<int> m;
    m->resize(32);
    m[0]=12;
    a=std::move( b );

    return 0;
}

