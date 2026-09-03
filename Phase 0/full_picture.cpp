#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;

class Employee{
private:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}

    // CONST: promises not to modify the Employee. This lets us call
    // getId() through a "const Employee&", which idExists() below needs.
    int getId() const{
        return id;
    }
};

// FREE FUNCTION #1: general input helper, nothing to do with Employee.
// REFERENCE PARAMETER: "int& value" so it can hand the parsed number
// back to whoever called it, by writing directly into their variable.
bool readInt(int& value){
    cin >> value;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

// FREE FUNCTION #2: operates on the COLLECTION, not on one Employee.
// CONST REFERENCE PARAMETER: "const vector<Employee>&" so we can look
// at the list without copying the whole vector, and without being
// ALLOWED to accidentally modify it (the compiler enforces this).
bool idExists(const vector<Employee>& employees, int searchId){
    for(const Employee& emp : employees){
        if(emp.getId() == searchId){   // works because getId() is const
            return true;
        }
    }
    return false;
}

int main(){
    vector<Employee> staff;
    staff.push_back(Employee("Alice", 101));

    int newId;
    cout << "Enter a new employee ID to check: ";

    // CALLING readInt: notice there's no object, no dot -- just the
    // name and parentheses, like square(5) earlier. We pass `newId`
    // itself (not newId's value) because readInt takes it by reference.
    if(!readInt(newId)){
        cout << "That wasn't a valid number.\n";
        return 1;
    }

    // CALLING idExists: again, just name + parentheses. We pass our
    // `staff` vector directly -- idExists promises (via const) not
    // to change it, so we don't need to worry about it being altered.
    if(idExists(staff, newId)){
        cout << "ID " << newId << " is already taken.\n";
    } else {
        cout << "ID " << newId << " is available.\n";
    }

    return 0;
}