#include <iostream>

using namespace std;

int main() {
    char text[5];
    char *pointer = text;
    char search_for = 'e';
    cout << *pointer << " ][ " << pointer << endl;
    cin >> text;
    while (*pointer != search_for) {
        *pointer = search_for;
        cout << *pointer << " | " << pointer << " | " << text << endl;
        pointer++;
    }
    
    cout << text << endl;
}