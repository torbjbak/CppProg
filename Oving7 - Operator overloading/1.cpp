#include "Fraction.hpp"
#include <iostream>

using namespace std;

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout <<  "a + 2 = " << a + 2 << endl;
    cout << "1 + b = " << 1 + b << endl;

    cout << "a - 3 = " << a - 3 << endl;
    cout << "4 - b = " << 4 - b << endl;

    cout << "b)" << endl << "5 - 3 - a - 7 - b = "
        << 5 - 3 - a - 7 - b << endl;

    //  Operatoren - er venstreassosiativ, som vil
    //  si at uttrykket blir regnet ut som følgende:
    //  ((((5 - 3) - a) - 7) - b)
    //
    //  Den første uttrykket er bare (int - int),
    //  og bruker dermed ikke noen overloaded operator.
    //
    //  Det neste er (int - Fraction), og bruker dermed
    //  Fraction operator-(int integer, const Fraction &other)
    //
    //  Etter der kommer (Fraction - int) som bruker
    //  Fraction Fraction::operator-(int integer) const
    //
    //  Til sist kommer en (Fraction - Fraction) som bruker
    //  Fraction Fraction::operator-(const Fraction &other) const
}
