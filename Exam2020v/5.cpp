#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;



int main() {
    vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
    for (auto &e : vec)
        cout << e << " ";

    cout << "\n\na)" << endl;
    reverse(vec.begin(), vec.end());
    for (auto &e : vec)
        cout << e << " ";

    vec = {2, 5, 2, 5, 1, 5, 1};
    cout << "\n\nb)" << endl;
    rotate(vec.begin(), vec.begin()+1, vec.end());
    for (auto &e : vec)
        cout << e << " ";

    vec = {2, 5, 2, 5, 1, 5, 1};
    cout << "\n\nb)" << endl;
    transform(vec.begin(), vec.end(), vec.begin(),[](int e) { return e * 2; });
    for (auto &e : vec)
        cout << e << " ";

}

