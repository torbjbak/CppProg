#include <iostream>
#include "Covering.hpp"
#include "Material.hpp"

using namespace std;

int main() {
  Covering covering("Super Duper Dux", 433.50, 4);
  // get_name() og get_price() arves til subklassene:
  cout << "Navn: " << covering.get_name() << ", pris: "
                   << covering.get_price() << endl;
  // Objektet bruker sin egen print()-funksjon (og ikke den som er arvet)
  covering.print();
}