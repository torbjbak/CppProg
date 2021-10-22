#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Set {
public:
    vector<int> numbers;

    Set();
    Set(Set &one, Set &two);

    Set operator+(int number) const;
    Set &operator=(const Set &other);
    Set &operator+=(int number);

    friend ostream &operator<<(ostream &out, const Set &set);
private:

};