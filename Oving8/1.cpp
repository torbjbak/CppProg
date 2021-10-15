#include <iostream>
#include <iomanip>

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {
    bool equal = a == b;
    cout << "'" << a << "' and '"<< b << "' are equal: " << boolalpha << equal << endl;
    return equal;
}

bool equal(double a, double b) {
    double margin = 0.00001;
    double diff = abs(a - b);
    bool equal = diff < margin;
    cout << "The absolute difference between " << setprecision(7) << fixed << a
    << " and " << b << " = " << diff << " -> equal: " << boolalpha << equal << endl;
    return equal;
}

int main() {
    equal(0.999, 1.0);
    equal(1, 1);
    equal(1.999999, 2.0);
    equal("abc", "cba");
}
