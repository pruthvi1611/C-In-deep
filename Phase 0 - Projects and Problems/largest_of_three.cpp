#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> num = {12 ,23, 11};
    int largest = num[0];
    for(int n  : num){
        if( n > largest){
            largest = n;
        }
    }
    cout << "Largest number is : " << largest << endl;
    return 0;
}