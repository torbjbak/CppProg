#include <iostream>
#include "Material.hpp"

using namespace std;

Material::Material(const string &name_, double price_) : name(name_), price(price_) {}

void Material::print() const {
  cout << endl
       << "Navn:          " << name << endl
       << "Pris pr enhet  " << price << endl;
}
