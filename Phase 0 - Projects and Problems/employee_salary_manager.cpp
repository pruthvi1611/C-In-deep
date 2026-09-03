#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<iomanip>
using namespace std;

class Employee{
private:
    string name;
    int id;
    double salary;
public:
    Employee(const string& empName, int empId, double empSalary)
        : name(empName), id(empId), salary(empSalary) {}
        
    int getId() const{
        return id;
    }

    double getSalary()const{
        return salary;
    }

    void increaseSalary(double percent){
        salary += salary * (percent / 100.0);
        cout << "Salary updated successfully.\n";
    }

    void displayEmployee() const{
        cout << "\nID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Salary : " << salary << endl;
    }
};

bool readInt(int& value){
    cin >> value;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool readDouble(double& value){
    cin >> value;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool idExists(const vector<Employee>& employee, int id){
    for(const Employee& emp : employee){
        if(emp.getId() == id){
            return true;
        }
        return false;
    }
}
int main(){
    vector<Employee> employees;
    int choice;

    do{
        cout << "\n--- Employee Salary Manager ---\n";
        cout << "1. Add Employee\n";
        cout << "2. View All Employee\n";
        cout << "3. Increase Salary\n";
        cout << "4. EXIT\n";
        cout << "Enter your Choice : ";

        if(!readInt(choice)){
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if(choice == 1){
            string name;
            int id;
            double salary;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Employee Name : ";
            getline(cin,name);

            cout << "Enter ID : ";
            if(!readInt(id)){
                cout << "Invalid ID. Employee not added.\n";
                continue;
            }
            if(idExists(employees,id)){
                cout << "An Employee with this ID already exists. Employee not added.\n";
                continue;
            }
            cout << "Enter Salary : ";
            if(!readDouble(salary) || salary < 0){
                cout << "Invalid Salary. Employee Not added.\n";
                continue;
            }

            employees.emplace_back(name,id,salary);
            cout << "Employee addded successfully.\n";
        }
        
        else if(choice == 2){
            if(employees.empty()){
                cout << "No Employees Found.\n";
            }else{
                for(const Employee& emp : employees){
                    emp.displayEmployee();
                }
            }
        }

        else if(choice == 3){
            int searchId;
            bool found = false;

            cout << "Enter Employee ID : ";
            if(!readInt(searchId)){
                cout << "Invalid ID.\n";
                continue;
            }

            for(Employee& emp : employees){
                if(emp.getId() == searchId){
                    found = true;

                    double percent;

                    cout << "Enter Percentage increase : ";
                    if(!readDouble(percent) || percent < 0){
                        cout << "Invalid percentage.\n";
                        break;
                    }

                    emp.increaseSalary(percent);
                    emp.displayEmployee();
                    break;
                }
            }
            if(!found){
                cout << "Employee not found.\n";
            }
        }

        else if(choice == 4){
            cout << "Exiting.... \n";
        }

        else {
            cout << "Invallid Choice. Try Again.\n";
        }

    }while(choice != 4);
    
    return 0;
}