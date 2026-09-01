#include <iostream>
using namespace std;

int main() {
    int age = 21;                  // whole numbers
    float height = 5.9f;           // decimal, less precise, less memory
    double gpa = 8.75;             // decimal, more precise (use this by default)
    char grade = 'A';              // single character, single quotes
    bool isPlaced = false;         // true or false only
    string name = "Pruthvi";       // text, needs #include <string> (iostream usually pulls it in, but include it explicitly)

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Grade: " << grade << endl;
    cout << "Placed: " << isPlaced << endl;  // prints 0 or 1, not true/false, by default

    return 0;
}