#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Type>
ostream &operator<<(ostream &out, const vector<Type> &vector) {
    string print = "{";
    for(auto &e : vector) {
        if(e == vector.front())
            print += " " + to_string(e) + ", ";
        else if(e == vector.back())
            print += to_string(e) + " ";
        else
            print += to_string(e) + ", ";
    }
    print += "}";
    return out << print;
}

template <typename Type>
vector<Type> operator*(vector<Type> vec, int integer)  {
    for(size_t i = 0; i < vec.size(); i++)
        vec[i] = vec[i] * integer;

    return vec;
}

template <typename Type1, typename Type2>
vector<Type1> operator*(vector<Type1> vec, vector<Type2> other)  {
    int v_size = vec.size();
    int o_size = other.size();

    if(v_size >= o_size) {
        for(size_t i = 0; i < v_size; i++) {
            if (i < o_size)
                vec[i] = vec[i] * other[i];
            else
                vec[i] = vec[i];
        }
        return vec;
    } else {
        for(size_t i = 0; i < o_size; i++) {
            if (i < v_size)
                other[i] = vec[i] * other[i];
            else
                other[i] = other[i];
        }
        vector<Type1> ret(other.begin(), other.end());
        return ret;
    }
}

int main() {
    cout << vector<int>() << endl;
    cout << vector<float>({1.5, 2.5}) << endl;
    vector<int> vec = {1, 2, 3};
    cout << vec << endl;
    cout << vec * 3 << endl;
    cout << vec * vec << endl;
    vector<double> vec2 = {1.2, 4.2, 2.3, 3.14};
    cout << vec * vec2 << endl;
    cout << vec2 * vec << endl;

    return 0;
}

