#include <iostream>
#include <string>
using namespace std;

// Base Class
class Account {
protected:   // Encapsulation
    int accountNumber;
    string name;
    double balance;

public:
    // Constructor
    Account(int accNo, string accName, double bal) {
        accountNumber = accNo;
        name = accName;
        balance = bal;
    }

    // Member Function: Deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    // Member Function: Withdraw
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    // Member Function: Display Details
    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Derived Class (Inheritance)
class SavingsAccount : public Account {
public:
    SavingsAccount(int accNo, string accName, double bal)
        : Account(accNo, accName, bal) {}

    void showAccountType() {
        cout << "Account Type: Savings Account\n";
    }
};

int main() {
    int accNo;
    string name;
    double initialBalance;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    SavingsAccount user(accNo, name, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n===== Bank Menu =====\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            user.deposit(amount);
            break;

        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            user.withdraw(amount);
            break;

        case 3:
            user.showAccountType();
            user.display();
            break;

        case 4:
            cout << "Thank you for using the Bank System!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}