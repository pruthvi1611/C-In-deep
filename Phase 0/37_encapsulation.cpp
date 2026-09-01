#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    // PRIVATE: only accessible from INSIDE the class. This is ENCAPSULATION --
    // hiding internal data so it can't be messed with directly from outside.
    double balance;
    string accountHolder;

public:
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        // Basic validation -- this is exactly WHY we hide balance as private.
        // If it were public, anyone could set it to a negative number directly.
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    // Public "getter" -- controlled READ access to private data
    double getBalance() {
        return balance;
    }

    // Public "setter"-like function -- controlled WRITE access, with validation
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else if (amount > 0) {
            balance -= amount;
        }
    }
};

int main() {
    BankAccount acc("Pruthvi", 1000);

    cout << "Initial balance: " << acc.getBalance() << endl;

    acc.deposit(500);
    cout << "After deposit: " << acc.getBalance() << endl;

    acc.withdraw(2000);  // will be rejected -- insufficient funds
    cout << "After failed withdraw: " << acc.getBalance() << endl;

    // acc.balance = -9999;  // <-- THIS WOULD FAIL TO COMPILE if uncommented!
    // 'balance' is private, so it cannot be accessed directly from outside the class.
    // This is the whole point of encapsulation -- forcing all changes through
    // controlled functions (deposit/withdraw) that can validate the data.

    return 0;
}