#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "Innhold i: " << i << " Adresse &i: "<< &i << endl;
    cout << "Innhold j: " << j << " Adresse &j: "<< &j << endl;
    cout << "Innhold *p: " << *p << " Adresse &*p: "<< &*p << endl;
    cout << "Innhold *q: " << *q << " Adresse &*p: "<< &*q << endl;

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << *p << " " << *q << endl;
}