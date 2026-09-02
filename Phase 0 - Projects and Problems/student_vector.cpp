#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;

class Student{
private: 
    string name;
    int roll_no;
    vector<int> marks;
public:
    void getInput(){
        cout << "Enter Name : ";
        cin >> name;

        cout << "Enter Roll No. : ";
        cin >> roll_no;

        int subjectCount;
        cout << "Enter No. of Subjects : ";
        cin >> subjectCount;
        
        for(int i=0; i < subjectCount; i++){
            int mark;
            cout << "Subject " << i+1 << " value : ";
            cin >> mark;

            marks.push_back(mark);
        }
    }

    int CalculateTotal(){   
        int total = 0 ;
        for(int x : marks){
            total += x;
        }
        return total;
    }

    double CalculateAvg(){
        if(marks.empty()){
            return 0;
        }

        return static_cast<double>(CalculateTotal() / marks.size());
    }

    int HighestMarks(){
        if(marks.empty()){
            return 0;
        }
        int high;
        for(int x : marks){
            high = x;
        }
        return high;
    }

    string CalculateGrade(){
        double average = CalculateAvg();

        if(average >= 90){
            return "A+";
        }else if(average >= 80){
            return "A";
        }else if(average >= 70){
            return "B";
        }else if(average >= 60){
            return "C";
        }else if(average >= 40){
            return "D";
        }

        return "F";
    }

    void displayDetails(){
        cout << "\n--- Student Report ---\n";
        cout << "Name : " << name << endl;
        cout << "Roll No. : " << roll_no << endl;

        cout << "Marks : ";
        for(int mark : marks){
            cout << mark << " ";
        }
        
        cout << "\nTotal Marks : " << CalculateTotal() << endl;
        cout << "Average Marks : " << CalculateAvg() << endl;
        cout << "Highest Marks : " << HighestMarks() << endl;
        cout << "Grade : " << CalculateGrade() <<endl;
    }
};

int main(){
    Student s1;
    Student s2;

    s1.getInput();
    s1.displayDetails();

    s2.getInput();
    s2.displayDetails();
    return 0;
}