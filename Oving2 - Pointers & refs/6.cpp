#include <iostream>

using namespace std;

int find_sum(const int *table, int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += table[i];
    }
    return sum;
}

int main() {
    const int length = 20;
    int table[length];

    for(int i = 0; i < length; i++) {
        table[i] = i + 1;
    }

    const int a = 10;
    const int b = 5;
    const int c = 5;

    cout << "Sum first 10: " << find_sum(table, a) << endl;
    cout << "Sum next 5: " << find_sum(&table[a], b) << endl;
    cout << "Sum last 5: " << find_sum(&table[a + b], c) << endl;
    
}