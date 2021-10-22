#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

bool bigger_than_15(int i){
    return i > 15;
}

bool somewhat_equal(int a, int b) {
    return abs(b - a) <= 2;
}

bool is_odd(int i) {
    return i % 2 == 1;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    // a)
    auto pos = find_if(v1.begin(), v1.end(), bigger_than_15);
    if (pos != v1.end()) {
        cout << "v1 har minst én verdi over 15, første på indeks " << (pos - v1.begin()) << endl;
    } else
        cout << "v1 har ingen verdier over 15" << endl;

    // b)
    cout << "[v1.begin(), v1.begin() + 5> og v2 er omtrent like: " << boolalpha
        << equal(v1.begin(), v1.begin() + 5, v2.begin(), somewhat_equal) << endl;

    cout << "[v1.begin(), v1.begin() + 4> og v2 er omtrent like: "
        << equal(v1.begin(), v1.begin() + 4, v2.begin(), somewhat_equal) << endl;

    // c)
    vector<int> result;
    result.resize(v1.size());
    replace_copy_if(v1.begin(), v1.end(), result.begin(), is_odd, 100);
    cout << "result: " << result << endl;
}