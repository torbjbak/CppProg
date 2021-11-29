#include <iostream>
#include <map>
#include <vector>
#include <thread>

using namespace std;

long f(long x) {
    if (x <= 1)
        return 1;
    else
        return f(x - 2) + f(x - 1);
}

int main() {
    map<long, long> results;
    vector<thread> threads;
    for(long x = 3; x < 7; ++x) {
        threads.emplace_back([&results, x] {
            auto result = f(x); // Time-consuming task
            results.emplace(x, result);
        });
    }
    for(auto &thread : threads)
        thread.join();
    for(auto &pair : results)
        cout << "f(" << pair.first << ") = " << pair.second << endl;

}

