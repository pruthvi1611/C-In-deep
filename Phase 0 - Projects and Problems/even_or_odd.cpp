#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> num = {10,11,12,14,15};
    for(int n : num){
        if(n==0){
            cout << n << " is Zero" << endl;
        } else if(n % 2==0){
            cout << n << " is Even" << endl;
        }else {
            cout << n << " is odd" << endl;
        }
    }
    return 0;
}