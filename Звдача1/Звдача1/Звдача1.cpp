#include <iostream>
#include "DynamicArrayOfIntegers.h"

using namespace std;

int main()
{
    DynamicArrayOfIntegers x(4, 1);
    cout << x << endl;
    DynamicArrayOfIntegers y(x);
    cout << y << endl;
    cout << x.getSize() << endl;
    x.resize(5);
    cout << x[4] << endl;
    DynamicArrayOfIntegers z;
    z = y;
    cout << z << endl;
    DynamicArrayOfIntegers c(4, 2);
    if (z == y) cout << "True" << endl;
    else cout << "False" << endl;
    if (z != c) cout << "True" << endl;
    else cout << "False" << endl;
    if (y < x) cout << "True" << endl;
    else cout << "False" << endl;
    if (y <= z) cout << "True" << endl;
    else cout << "False" << endl;
    z = z + c;
    cout << z << endl;  
    cin >> y;
    cout << y << endl;
}