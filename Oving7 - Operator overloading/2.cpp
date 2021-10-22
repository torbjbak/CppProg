#include "Set.hpp"
#include <iostream>

using namespace std;

int main() {
    Set a;
    Set b;

    a += 4;
    cout << "a += 4, a = " << a << endl;
    b = a + 2;
    cout << "b = a + 2, b = " << b << endl;
    a += 5;
    cout << "a += 5, a = " << a << endl;
    a += 5;
    cout << "a += 5, a = " << a << endl;
    b += 7;
    cout << "b += 7, b = " << b << endl;

    Set c(a, b);
    cout << "c(a, b), c = " << c << endl;
}