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

    // Let's TRY putting idExists as a method of Employee.
    // Immediately there's a question: idExists needs to check
    // a WHOLE LIST of employees. But a single Employee object
    // only knows about ITSELF -- it has no idea the vector
    // even exists, let alone what's inside it.
    //
    // So to write this as a member function, we'd have to pass
    // the vector in anyway:
    bool idExistsIn(const vector<Employee>& employees) const{
        for(const Employee& emp : employees){
            if(emp.id == id){   // comparing THIS employee's id to each one
                return true;
            }
        }
        return false;
    }
    // ...but this only answers "does an employee with MY id already
    // exist in this list" -- which means you need an Employee OBJECT
    // to already exist before you can even ask the question. That's
    // backwards from what we actually want: we want to check a
    // candidate ID BEFORE constructing an Employee at all (so we can
    // reject bad input without ever building the object).
};

int main(){
    vector<Employee> staff;
    staff.push_back(Employee("Alice", 101));

    // Awkward: to check if ID 101 is taken, we must first build
    // a throwaway Employee just to ask the question.
    Employee probe("", 101);
    cout << boolalpha << probe.idExistsIn(staff) << endl;

    return 0;
}