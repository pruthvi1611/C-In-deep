#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {  // 'virtual' tells C++: "figure out the REAL type at runtime"
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {  // 'override' is optional but good practice -- catches typos
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Dog d;
    Cat c;

    Animal* ptr1 = &d;
    Animal* ptr2 = &c;

    ptr1->makeSound();  // now correctly prints "Woof!"
    ptr2->makeSound();  // now correctly prints "Meow!"

    cout << "\n--- The real power: an array of base pointers to DIFFERENT derived types ---\n";
    Animal* animals[2];
    animals[0] = &d;
    animals[1] = &c;

    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();  // each one calls the RIGHT version automatically
    }
    // This is POLYMORPHISM -- "many forms." One line of code (animals[i]->makeSound())
    // behaves differently depending on the actual object type at runtime.

    return 0;
}