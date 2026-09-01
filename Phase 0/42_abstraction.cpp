#include <iostream>
using namespace std;

// An ABSTRACT class -- it has at least one PURE virtual function (the "= 0" part).
// This means Shape is INCOMPLETE on its own -- it defines WHAT every shape must
// be able to do (calculateArea), but not HOW, since that differs per shape.
class Shape {
public:
    virtual double calculateArea() = 0;  // PURE virtual -- no body, must be overridden

    void printArea() {
        cout << "Area: " << calculateArea() << endl;
        // Notice: printArea() is NOT pure -- it's a normal function that
        // USES the pure virtual one. Every derived class gets this for free.
    }
};

class Circle : public Shape {
public:
    double radius;
    Circle(double r) { radius = r; }

    double calculateArea() override {  // MUST provide this, or Circle can't be created
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
public:
    double width, height;
    Rectangle(double w, double h) { width = w; height = h; }

    double calculateArea() override {
        return width * height;
    }
};

int main() {
    // Shape s;  // <-- THIS WOULD FAIL TO COMPILE -- can't create an object of
    //              an abstract class directly, since calculateArea() has no body

    Circle circ(5);
    Rectangle rect(4, 6);

    circ.printArea();   // uses Circle's calculateArea() -- 78.5398
    rect.printArea();   // uses Rectangle's calculateArea() -- 24

    return 0;
}