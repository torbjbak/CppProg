#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
    const int length = 5;
    double temperatures[length];

    int underTen = 0;
    int tenToTwenty = 0;
    int overTwenty = 0;

    read_temperatures(temperatures, length);

    for (int i = 0; i < length; i++) {
        if (temperatures[i] < 10) {
            underTen++;
        } else if (temperatures[i] <= 20) {
            tenToTwenty++;
        } else {
            overTwenty++;
        }
    }

    cout << "Antall under 10: " << underTen << endl
         << "Antall mellom 10 og 20: " << tenToTwenty << endl
         << "Antall over 20: " << overTwenty << endl;
}

void read_temperatures(double temperatures[], int length) {
    const char filename[] = "temperatures.dat";
    ifstream file;
    file.open(filename);

    if (!file) {
        cout << "Feil ved åpning av innfil." << endl;
        exit(EXIT_FAILURE);
    }

    int i = 0;
    double number;
    while (file >> number && i < length) {
        temperatures[i] = number;
        i++;
    }

    file.close();
}