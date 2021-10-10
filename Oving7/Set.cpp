#include "Set.hpp"

using namespace std;

Set::Set() : numbers({}) {}

// Union
Set::Set(Set &one, Set &two) {
    numbers = one.numbers;

    for(int number : two.numbers) {
        *this += number;
    }
}

Set Set::operator+(int number) const {
    Set set = *this;
    set += number;
    return set;
}

Set &Set::operator=(const Set &other) {
    numbers = other.numbers;
    return *this;
}

Set &Set::operator+=(int number) {
    for(int it : numbers) {
        if(it == number)
            return *this;
    }
    numbers.push_back(number);
    return *this;
}

ostream &operator<<(ostream &out, const Set &set) {
    string print = "{";
    vector<int> v = set.numbers;
    int size = v.size();

    for(int i = 0; i < size; i++) {
        print += to_string(v.at(i));
        if(i < size - 1)
            print += ", ";
        else
            print += "}";
    }

    out << print;
    return out;
}