#include <iostream>

//test
#include "Containers.hpp"
#include "CheckArgs.hpp"
#include "TemplateString.hpp"
#include "Map.hpp"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    cct::Map<int, double > a;
    cct::Map<int, double>b;
    a=std::move( b );

    return 0;
}

