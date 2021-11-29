#include <iostream>
#include <map>
#include <cmath>

using namespace std;

template <typename AngleType>
class Angle {
public:
    AngleType angle_value;

    explicit Angle(int angle_value) : angle_value(angle_value % 360) {}
    explicit Angle(double angle_value) : angle_value(fmod(angle_value, M_PI)) {}

    friend ostream &operator<<(ostream &out, const Angle<AngleType> &angle) {
        return out << angle.angle_value;
    }
};

int main() {
    Angle<int> angle1(30);
    cout << angle1 << endl;
    Angle<int> angle2(390);
    cout << angle2 << endl;
    Angle<double> angle3(3.14159265359 / 2);
    cout << angle3 << endl;
    Angle<double> angle4(3.14159265359 * 1.5);
    cout << angle4 << endl;

    return 0;
}

