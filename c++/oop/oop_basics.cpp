#include <iostream>
#include <string>

class BankAccount {
private:
    // Private data members, only accessible within the class
    std::string m_accountHolder;
    double m_balance;

protected:
    // Protected data member, accessible in derived classes
    int accountNumber;

public:
    // Default constructor
    BankAccount() : m_accountHolder("Unknown"), m_balance(0.0), accountNumber(0) {
        std::cout << "Default constructor called for " << m_accountHolder << std::endl;
    }

    // Parameterized constructor with an initializer list
    BankAccount(const std::string& name, double initialBalance, int accNum)
        : m_accountHolder(name), m_balance(initialBalance), accountNumber(accNum) {
        std::cout << "Parameterized constructor called for " << m_accountHolder << std::endl;
    }

    // Copy constructor
    BankAccount(const BankAccount& other)
        : m_accountHolder(other.m_accountHolder), m_balance(other.m_balance), accountNumber(other.accountNumber) {
        std::cout << "Copy constructor called for " << m_accountHolder << std::endl;
    }

    // Destructor
    ~BankAccount() {
        std::cout << "Destructor called for " << m_accountHolder << std::endl;
    }

    // Public method defined inside the class
    BankAccount& deposit(double amount) {
        if (amount > 0) {
            m_balance += amount;
            std::cout << m_accountHolder << " deposited " << amount << ". New balance: " << m_balance << std::endl;
        }
        return *this;  // Returning *this to allow chaining
    }

    // Public method declaration - definition is outside the class
    BankAccount& withdraw(double amount);

    // Method to display account information
    BankAccount& displayInfo() {
        // Use of the implicit 'this' pointer to access member data
        std::cout << "Account Holder: " << this->m_accountHolder << std::endl;
        std::cout << "Account Number: " << this->accountNumber << std::endl;
        std::cout << "Balance: " << this->m_balance << std::endl;
        return *this;  // Returning *this to allow chaining
    }
};

// Method defined outside the class
BankAccount& BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= m_balance) {
        m_balance -= amount;
        std::cout << m_accountHolder << " withdrew " << amount << ". New balance: " << m_balance << std::endl;
    } else {
        std::cout << "Withdrawal amount exceeds balance." << std::endl;
    }
    return *this;  // Returning *this to allow chaining
}

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "OOP BASICS" << std::endl;
    std::cout << "==========================" << std::endl;

    // Using the default constructor
    BankAccount account1;
    account1.deposit(100);
    account1.displayInfo();

    // Using the parameterized constructor
    BankAccount account2("Alice", 500.0, 12345);
    account2.deposit(200).withdraw(100).displayInfo();

    // Using the copy constructor
    BankAccount account3 = account2;
    account3.displayInfo();

    // Example on heap (above were all on stack)
    BankAccount* account4 = new BankAccount("Alice", 500.0, 12345);
    account4->withdraw(200).displayInfo();

    std::cout << "--------------------------" << std::endl;
    return 0;
}
