#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    string sentence;
    vector<string> words;
    vector<int> count;

    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    for (char& ch : sentence) {
        if (isalpha(ch)) {
            ch = tolower(ch);
        } else {
            ch = ' ';
        }
    }

    stringstream input(sentence);
    string word;

    while (input >> word) {
        words.push_back(word);
    }

    for (int i = 0; i < words.size(); i++) {
        int wordCount = 0;

        for (int j = 0; j < words.size(); j++) {
            if (words[i] == words[j]) {
                wordCount++;
            }
        }

        count.push_back(wordCount);
    }

    cout << "\nDuplicate words:\n";

    bool foundDuplicate = false;

    for (int i = 0; i < words.size(); i++) {
        bool alreadyPrinted = false;

        for (int j = 0; j < i; j++) {
            if (words[i] == words[j]) {
                alreadyPrinted = true;
                break;
            }
        }

        if (count[i] > 1 && !alreadyPrinted) {
            cout << words[i] << " appears " << count[i] << " times\n";
            foundDuplicate = true;
        }
    }

    if (!foundDuplicate) {
        cout << "No duplicate words found.\n";
    }

    return 0;
}