#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;


int main(){
    string sentence;
    vector<int> num(5,0);

    cout << "Enter a sentence : ";
    getline(cin, sentence);

    for(char ch : sentence){
        if(isalpha(ch)){
            char lower = tolower(ch);
            if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
                num[0]++;
            }else{
                num[1]++;
            }
        }
        else if(isspace(ch)){
            num[3]++;
        }
        else if(isdigit(ch)){
            num[4]++;
        }
        else{
            num[5]++;
        }
    }

    cout << "Vowels : " << num[0] << endl;
    cout << "Consonants : " << num[1] << endl;
    cout << "Spaces : " << num[2] << endl;
    cout << "Numbers : " << num[3] << endl;
    cout << "Special Characters : " << num[4] << endl;
}