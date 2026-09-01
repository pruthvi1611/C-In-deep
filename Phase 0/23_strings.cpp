#include <iostream>
#include <string>
using namespace std;

int main() {
    // std::string is what you'll use 99% of the time in DSA -- much easier
    // than old-school C-style char arrays.

    string s = "Pruthvi";

    cout << "String: " << s << endl;
    cout << "Length: " << s.length() << endl;   // or s.size(), same thing
    cout << "First char: " << s[0] << endl;      // strings support [] just like arrays
    cout << "Last char: " << s[s.length() - 1] << endl;

    // Concatenation
    string greeting = "Hello, " + s + "!";
    cout << greeting << endl;

    // Substring: substr(startIndex, length)
    cout << "Substring (0,4): " << s.substr(0, 4) << endl;  // "Prut"

    // Comparison
    string a = "apple", b = "banana";
    cout << "a == b? " << (a == b) << endl;
    cout << "a < b (alphabetically)? " << (a < b) << endl;

    // Modifying a string (strings are mutable, unlike some languages)
    string mutableStr = "hello";
    mutableStr[0] = 'H';
    cout << "After modification: " << mutableStr << endl;

    // Looping through a string character by character
    cout << "Characters: ";
    for (int i = 0; i < s.length(); i++) {
        cout << s[i] << "-";
    }
    cout << endl;

    // Reversed string using a loop (common DSA warm-up)
    string reversed = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        reversed += s[i];
    }
    cout << "Reversed: " << reversed << endl;

    return 0;
}