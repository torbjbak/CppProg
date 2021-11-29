#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using namespace std;

class Animal {
public:
    string name;

    explicit Animal(string name_) : name(std::move(name_)){}
    virtual ~Animal()= default;

    virtual string type() const = 0;

    friend ostream &operator<<(ostream &out, const Animal &animal) {
        out << animal.type() + " named " + animal.name;
        return out;
    }
};

class Cat : public Animal {
public:
    explicit Cat(const string &name_) : Animal(name_){}

    string type() const override {
        return "Cat";
    }
};

class Dog : public Animal {
public:
    explicit Dog(const string &name_) : Animal(name_){}

    string type() const override {
        return "Dog";
    }
};

int main() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Oreo"));
    animals.emplace_back(new Dog("Buddy"));
    animals.emplace_back(new Dog("Charlie"));
    // animals.emplace_back(new Animal()); // Should cause compilation error
    // animals.emplace_back(new Animal("Max")); // Should cause compilation error
    for (auto &animal : animals)
        cout << *animal << endl;

}
