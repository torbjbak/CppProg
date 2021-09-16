#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

double get_random(double min, double max) {
    return ((double) rand() * (max - min) / (double) RAND_MAX - min);
}

int main() {
    double min = 0;
    double max = 10;
    vector<double> numbers;
    srand (time(NULL));

    cout <<"Vector: [ "; 
    for(int i = 0; i < 5; i++) {
        numbers.emplace_back(
            get_random(min, max)
        );
        cout << numbers[i] << " ";
    }


    cout << "]" << endl 
        << "Front: " << numbers.front() << endl
        << "Back: " << numbers.back() << endl;


    numbers.emplace(numbers.begin() + 1, 3.14);
    cout <<"Vector: [ "; 
    for(auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << "]" << endl
        << "Front: " << numbers.front() << endl;

    double target = 0.34;
    auto it = find(numbers.begin(), numbers.end(), target);
    if(it != numbers.end())
        cout << "Element found: " << *it << endl;
    else
       cout << "Element not found" << endl;  
}