#include <iostream>

using namespace std;

int main() {
    double number = 2.3;
    double *p = &number;
    double &r = number;

    cout << number << endl;
    cout << *p << endl;
    cout << r << endl;
}