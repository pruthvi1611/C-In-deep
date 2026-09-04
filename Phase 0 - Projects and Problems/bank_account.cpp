#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;

string formatAmount(double amount){
    ostringstream out;
    out << fixed << setprecision(2) << amount;
    return out.str();
}   

class BankAccount{
private: 
    string accountHolder;
    string accountNumber;
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount(string holder,string accNum, double initialBalance)
    : accountHolder(holder),accountNumber(accNum){
        balance = (initialBalance >= 0) ? initialBalance : 0;

        transactionHistory.push_back("Account opened with balance : " + formatAmount(balance));
    }

    void deposit(double amount){
        if(amount <= 0){
            cout << "Deposit amount must be positive." << endl;
            return;
        }
        balance += amount;
        transactionHistory.push_back("Deposited : " + formatAmount(amount) + " | New Balance : " + formatAmount(balance));
        cout << "Deposited : " << amount << " successfully." << endl;
    }

    void withdraw(double amount){
        if(amount <= 0){
            cout << "Withdrawal amount must be positive." << endl;
            return;
        }
        if(amount > balance){
            cout << "Insufficient funds. Current Balance : " << balance << endl;
            transactionHistory.push_back("Failed Withdrawal attempt : " + formatAmount(amount));
            return;
        }
        balance -= amount;
        transactionHistory.push_back("Withdraw : " + formatAmount(amount) + " | New Balance : " + formatAmount(balance));
        cout << "Withdrew : " << amount << " successfully." << endl;
    }

    double getBalance(){
        return balance;
    }

    void displayBalance(){
        cout << accountHolder << "'s balance: " << balance << endl;
    }

    void displayAccountInfo(){
        cout << "\n--- Account Info ---\n";
        cout << "Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance : "<< balance << endl;
    }

    void printTranscationHistory(){
        cout << "\n----- Transaction History -----\n";
        for(string num : transactionHistory){
            cout << num << endl;
        }
    }
};

int main(){
    BankAccount acc("Pruthvi","ACC101", 1000);

    acc.displayAccountInfo();
    acc.deposit(500);
    acc.withdraw(1000);
    acc.withdraw(5000);
    acc.displayBalance();
    acc.printTranscationHistory();
    return 0;
}