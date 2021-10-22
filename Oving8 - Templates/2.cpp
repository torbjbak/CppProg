#include <iostream>

using namespace std;

template <typename Type1, typename  Type2>
class Pair {
public:
    Type1 first;
    Type2 second;

    Pair(Type1 first, Type2 second) : first(first), second(second) {}

    Pair operator+(const Pair &other) {
        Pair pair = *this;
        pair.first += other.first;
        pair.second += other.second;
        return pair;
    }

    Pair operator-(const Pair &other) {
        Pair pair = *this;
        pair.first -= other.first;
        pair.second -= other.second;
        return pair;
    }

    bool operator<(const Pair &other) const {
        return compare(other) < 0;
    }

    bool operator>(const Pair &other) const {
        return compare(other) > 0;
    }

    bool operator<=(const Pair &other) const {
        return compare(other) <= 0;
    }

    bool operator>=(const Pair &other) const {
        return compare(other) >= 0;
    }

    bool operator==(const Pair &other) const {
        return compare(other) == 0;
    }

    double sum() const {
        return static_cast<double>(this->first) + static_cast<double>(this->second);
    }

    int compare(const Pair &other) const {
        double diff  = this->sum() - other.sum();
        if (diff > 0)
            return 1;
        else if (diff == 0)
            return 0;
        else
            return -1;
    }

    friend ostream &operator<<(ostream &out, const Pair<Type1, Type2> &pair) {
        out << "(" << pair.first << ", " << pair.second << ")";
        return out;
    }
};

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1 << " sum: " << p1.sum() << endl;
    cout << "p2: " <<  p2 << " sum: " << p2.sum() << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum << endl;

    auto diff = p1 - p2;
    cout << "Diff: " << diff << endl;
}