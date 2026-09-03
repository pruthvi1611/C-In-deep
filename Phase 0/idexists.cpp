#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Employee{
private:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}

    // Try removing "const" below and re-compiling to see it break.
    int getId() const{
        return id;
    }
};

// idExists takes a CONST REFERENCE to the vector.
// "const vector<Employee>&" means: "give me access to your vector,
// but I PROMISE not to add, remove, or modify anything in it."
bool idExists(const vector<Employee>& employees, int searchId){
    for(const Employee& emp : employees){
        //   ^^^^^ each emp we pull out is ALSO const, because we're
        //   iterating over a const vector. You cannot get a
        //   non-const reference out of a const container.

        if(emp.getId() == searchId){
            //  ^^^^^^^^ this call ONLY compiles because getId() is const.
            // If getId() were not const, this line would fail with
            // the exact same error as step1_broken.cpp.
            return true;
        }
    }
    return false;
}

int main(){
    vector<Employee> staff;
    staff.push_back(Employee("Alice", 101));
    staff.push_back(Employee("Bob", 102));

    cout << boolalpha;
    cout << "Does 101 exist? " << idExists(staff, 101) << endl;
    cout << "Does 999 exist? " << idExists(staff, 999) << endl;
    return 0;
}