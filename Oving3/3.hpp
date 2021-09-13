#include <iostream>

using namespace std;

const double sales_tax = 0.25;

class Commodity {
    public:
        Commodity(const string &name, int id, double price);
        const string &get_name() const;
        int get_id() const;
        double get_price() const;
        double get_price(double quantity) const;
        void set_price(double newPrice);
        double get_price_with_sales_tax() const;
        double get_price_with_sales_tax(double quantity) const;
    private:
        string name;
        int id;
        double price;
};

Commodity::Commodity(const string &name, int id, double price) : name(name), id(id), price(price) {}

const string &Commodity::get_name() const {
    return name;
}

int Commodity::get_id() const {
    return id;
}

double Commodity::get_price() const {
    return price;
}

double Commodity::get_price(double quantity) const {
    return price * quantity;
}

void Commodity::set_price(double newPrice) {
    price = newPrice;
}

double Commodity::get_price_with_sales_tax() const {
    return price * (1 + sales_tax);
}

double Commodity::get_price_with_sales_tax(double quantity) const {
    return price * (1 + sales_tax) * quantity;
}