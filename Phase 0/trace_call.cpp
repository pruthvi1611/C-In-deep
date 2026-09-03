#include<iostream>
#include<limits>
using namespace std;

bool readInt(int& value){
    cout << "[inside readInt] about to read from cin...\n";
    cin >> value;

    if(cin.fail()){
        cout << "[inside readInt] cin FAILED, cleaning up and returning false\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    cout << "[inside readInt] successfully read value = " << value << ", returning true\n";
    return true;
}

int main(){
    int choice;   // <-- step 1: an ordinary int variable, currently garbage/uninitialized

    cout << "[in main] calling readInt(choice)...\n";

    // step 2: we call readInt, and pass `choice` -- NOT a copy of choice,
    // but a REFERENCE to it (that's what "int& value" in the function
    // signature means). This means `value` inside readInt and `choice`
    // inside main are literally the SAME memory location, just with
    // two different names.
    bool ok = readInt(choice);

    // step 3: back in main. If readInt wrote 42 into `value`,
    // then `choice` is ALSO 42 right now, because they were
    // never two separate variables in the first place.
    cout << "[in main] back from readInt. ok = " << boolalpha << ok
         << ", choice = " << choice << endl;

    return 0;
}