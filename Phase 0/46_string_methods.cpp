#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello World";

    // find -- returns the index where a substring starts, or string::npos if not found
    int pos = s.find("World");
    cout << "'World' found at index: " << pos << endl;

    int notFound = s.find("xyz");
    if (notFound == string::npos) {
        cout << "'xyz' not found (string::npos returned)" << endl;
    }

    // Converting individual characters -- common in DSA character manipulation
    char c = 'a';
    cout << "\n'a' as int (ASCII): " << (int)c << endl;         // 97
    cout << "'a' + 1 as char: " << (char)('a' + 1) << endl;      // 'b' -- useful for cyclic shifts

    // Checking character types (needs #include <cctype>, commonly used together with string)
    cout << "\nisalpha('5'): " << isalpha('5') << endl;
    cout << "isdigit('5'): " << isdigit('5') << endl;
    cout << "isupper('A'): " << isupper('A') << endl;
    cout << "tolower('A'): " << (char)tolower('A') << endl;
    cout << "toupper('a'): " << (char)toupper('a') << endl;

    // Appending and comparing
    string a = "abc";
    a.append("def");  // same as a += "def"
    cout << "\nAfter append: " << a << endl;

    // to_string -- convert numbers to strings (very handy)
    int num = 42;
    string numStr = to_string(num);
    cout << "Number as string: " << numStr << ", length: " << numStr.length() << endl;

    // stoi -- convert string to int (opposite direction)
    string numericString = "123";
    int converted = stoi(numericString);
    cout << "String to int: " << converted + 7 << endl;  // proves it's a real int now

    return 0;
}