#include <iostream>
using namespace std;

class Animal {
public:
    void makeSound() {   // NOT virtual yet -- watch what goes wrong
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {   // Dog provides its OWN version -- this is called "overriding"
        cout << "Woof!" << endl;
    }
};

int main() {
    Dog d;
    d.makeSound();  // "Woof!" -- works fine when called directly on a Dog object

    cout << "\n--- Now through a base class pointer ---\n";
    Animal* ptr = &d;  // a base class pointer POINTING AT a derived object -- very common pattern
    ptr->makeSound();  // PROBLEM: without 'virtual', this calls Animal's version, NOT Dog's!

    return 0;
}