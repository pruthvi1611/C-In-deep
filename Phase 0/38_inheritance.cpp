#include <iostream>
#include <string>
using namespace std;

// BASE class (a.k.a. parent class)
class Person {
public:
    string name;
    int age;

    void introduce() {
        cout << "Hi, I'm " << name << ", age " << age << endl;
    }
};

// DERIVED class (a.k.a. child class) -- inherits everything public from Person
class Student : public Person {
public:
    string college;
    double cgpa;

    void showStudentInfo() {
        // Student automatically HAS name and age from Person, no need to redeclare them
        cout << name << " studies at " << college << " with CGPA " << cgpa << endl;
    }
};

int main() {
    Student s;
    s.name = "Pruthvi";     // inherited from Person
    s.age = 21;              // inherited from Person
    s.college = "XYZ Institute of Technology";  // Student's own member
    s.cgpa = 8.5;             // Student's own member

    s.introduce();          // this method comes from Person, but Student can use it directly
    s.showStudentInfo();

    return 0;
}