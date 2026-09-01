#include <iostream>
using namespace std;

int main() {
    // 'new' allocates memory on the HEAP and returns a pointer to it.
    // This memory does NOT automatically disappear -- it stays until YOU free it.
    int* heapVar = new int;
    *heapVar = 100;

    cout << "Value on heap: " << *heapVar << endl;

    // You are responsible for freeing it with 'delete' when you're done.
    delete heapVar;
    // After delete, heapVar is a "dangling pointer" -- it still holds the old
    // address, but that memory is no longer yours. Using *heapVar now would be
    // undefined behavior. Good practice: set it to nullptr right after deleting.
    heapVar = nullptr;

    cout << "\n--- new with initial value ---\n";
    int* ptr2 = new int(50);  // allocate AND initialize in one line
    cout << "*ptr2 = " << *ptr2 << endl;
    delete ptr2;
    ptr2 = nullptr;

    cout << "\n--- Dynamically sized array on the heap ---\n";
    int size;
    cout << "How many elements? ";
    // simulate user typing 4
    size = 4;
    cout << size << endl;

    int* dynamicArr = new int[size];  // array whose size can be decided AT RUNTIME
    for (int i = 0; i < size; i++) {
        dynamicArr[i] = i * i;
    }
    for (int i = 0; i < size; i++) {
        cout << dynamicArr[i] << " ";
    }
    cout << endl;

    delete[] dynamicArr;  // NOTE: array delete needs [] -- delete alone is wrong for arrays
    dynamicArr = nullptr;

    return 0;
}