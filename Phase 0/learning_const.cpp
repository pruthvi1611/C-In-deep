#include<iostream>
using namespace std;

class Box{
private:
    int value;
public:
    Box(int v) : value(v) {}

    // NOTICE: no "const" here
    int getValue() const{
        return value;
    }
};

// This function promises: "I will not modify the Box you give me."
// That promise is written in the parameter type: const Box&
void printBox(const Box& b){
    cout << "Value is: " << b.getValue() << endl;
    //                      ^^^^^^^^^^^
    // b is a CONST Box. Calling a non-const method on a const object
    // is forbidden by the compiler, because getValue() COULD (in
    // principle) modify the object -- the compiler has no way to know
    // it doesn't, unless you tell it with "const" on the method itself.
}

int main(){
    Box myBox(42);
    printBox(myBox);
    return 0;
}