#include "../headers/headers.h"

#include <iostream>
using namespace std;

int main()
{
    MyInt a(10);

    cout << a.getValue() << endl;
    a.setValue(1);
    cout << a.getValue() << endl;
}