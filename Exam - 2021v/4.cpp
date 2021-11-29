#include <iostream>
#include <map>
#include <vector>
#include <thread>
#include <functional>

using namespace std;

void parallell_transform(vector<int> &vec, size_t n_threads, const function<int(int)> &func) {
    vector<thread> threads;
    threads.reserve(n_threads);
    for(size_t i = 0; i < n_threads; i++) {
        threads.emplace_back([i, n_threads, &vec, &func] {
            for(size_t j = i; j < vec.size(); j += n_threads) {
                vec[j] = func(vec[j]);
            }
        });
    }
    for (auto &thread : threads)
        thread.join();
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    parallell_transform(vec, 4, [](int e) {
        return e * 2;
    });
    for (auto &e : vec)
        cout << e << " ";

    return 0;
}

