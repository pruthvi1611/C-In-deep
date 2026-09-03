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
    int getId() const{ return id; }
};

// A FREE function -- not attached to any class. It takes the two
// pieces of information it actually needs as plain parameters:
// the list to search, and the id to look for.
bool idExists(const vector<Employee>& employees, int searchId){
    for(const Employee& emp : employees){
        if(emp.getId() == searchId){
            return true;
        }
    }
    return false;
}

int main(){
    vector<Employee> staff;
    staff.push_back(Employee("Alice", 101));

    // No dummy Employee needed. We just ask directly:
    // "is 101 in this list?"
    cout << boolalpha << idExists(staff, 101) << endl;   // true
    cout << boolalpha << idExists(staff, 999) << endl;   // false

    return 0;
}