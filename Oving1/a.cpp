#include <iostream>

using namespace std;

int main() {
    const int length = 5;
    double temp;

    int underTen = 0;
    int tenToTwenty = 0;
    int overTwenty = 0;

    std::cout << "Skriv inn dine 5 temperaturmålinger:\n";

    for (int i = 1; i <= length; i++) {
        cout << "Temperatur nr " << i << ": ";
        cin >> temp;
        cin.get();

        if (temp < 10) {
            underTen++;
        } else if (temp <= 20) {
            tenToTwenty++;
        } else {
            overTwenty++;
        }
    }

    cout << "Antall under 10: " << underTen << endl
         << "Antall mellom 10 og 20: " << tenToTwenty << endl
         << "Antall over 20: " << overTwenty << endl;
}
