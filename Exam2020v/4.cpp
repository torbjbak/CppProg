#include <iostream>
#include <map>
#include <vector>
#include <thread>

using namespace std;

class NorwegianKrone {
public:
    static double rate;
};
double NorwegianKrone::rate = 0.1;

class Euro {
public:
    static double rate;
};
double Euro::rate = 1.0;

template <typename CurrencyType>
class Currency {
public:
    double amount;

    explicit Currency(double amount) : amount(amount * CurrencyType::rate) {}

    template<class CurrencyType2>
    Currency operator+(const CurrencyType2 &other) {
        auto result = *this;
        result.amount += other.amount;
        return result;
    }

    friend ostream &operator<<(ostream &out, const Currency<CurrencyType> &currency) {
        out << "€" << currency.amount;
        return out;
    }
};

int main() {
    cout << Currency<NorwegianKrone>(1) << endl;
    cout << Currency<Euro>(1) << endl;
    cout << (Currency<NorwegianKrone>(10) +
             Currency<Euro>(10) +
             Currency<NorwegianKrone>(10)) << endl;
}

