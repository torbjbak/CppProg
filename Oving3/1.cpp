#include <iostream>

using namespace std;

const double pi = 3.141592;

class Circle {
    public:
        Circle(double radius_);
        int get_area() const;
        double get_circumference() const;
    private: 
        double radius_;
};

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius_(radius_) {}

int Circle::get_area() const {
  return pi * radius_ * radius_;
}

double Circle::get_circumference() const {
  int circumference = 2.0 * pi * radius_;
  return circumference;
}

int main() {
    cout << Circle::get_area(3) << Circle::get_circumference(3) << endl;
}