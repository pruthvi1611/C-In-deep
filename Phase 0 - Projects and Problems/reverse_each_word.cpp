#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

int main(){
    string sentence;
    vector<string> words;

    cout << "Enter Sentence : ";
    getline(cin,sentence);

    stringstream input(sentence);
    string word;

    while(input >> word){
        words.push_back(word);
    }

    for(string& word : words){
        reverse(word.begin(),word.end());
    }

    cout << "Result : ";

    for(string word : words){
        cout << word << " ";
    }

    return 0;
}