#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#define MIN_ACCOUNT_NUMBER 10000
#define MAX_ACCOUNT_NUMBER 99999

class BankAccount {
private:
    std::string ownerName;
    long accountNumber;
    double balance;
    static constexpr double interestRate = 0.05;  // Annual interest rate (5%)
    static int accountsNumber;  // Number of accounts
    static std::vector<BankAccount*> users; // Pointers to BankAccount objects

public:
    // Constructor
    BankAccount(const std::string& name, double initialBalance)
        : ownerName(name), balance(initialBalance) {
            accountNumber = generateAccountNumber(); // Assign unique account number
            accountsNumber++;
            users.push_back(this);
        }

    // Destructor
    virtual ~BankAccount() { 
        --accountsNumber;
        // Remove this object's pointer from users vector
        auto it = std::find(users.begin(), users.end(), this);
        if (it != users.end()) {
            users.erase(it);
        }
    }

    // Static methods

    static long generateAccountNumber() {
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation
        return MIN_ACCOUNT_NUMBER + std::rand() % (MAX_ACCOUNT_NUMBER - MIN_ACCOUNT_NUMBER + 1);
    }

    static int getAccountsNumber() {
        return accountsNumber;
    }

    static void applyInterestToAll() {
        for (auto user : users) {
            user->applyInterest();
        }
    }
    
    // object methods

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        } else {
            std::cout << "Insufficient funds. Withdrawal canceled." << std::endl;
            return false;
        }
    }

    void display() const {
        std::cout << "Account Owner: " << ownerName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    void applyInterest() {
        balance *= (1 + interestRate);
    }

    bool transferTo(BankAccount& destination, double amount) {
        if (withdraw(amount)) {
            destination.deposit(amount);
            return true;
        } else {
            std::cout << "Transfer canceled due to insufficient funds." << std::endl;
            return false;
        }
    }

    // Operator overloading
    BankAccount operator+(const BankAccount& other) const {
        BankAccount result = *this;
        result.balance += other.balance;
        return result;
    }

    BankAccount operator-(const BankAccount& other) const {
        BankAccount result = *this;
        if (result.balance >= other.balance) {
            result.balance -= other.balance;
        } else {
            std::cout << "Cannot subtract. Insufficient funds." << std::endl;
        }
        return result;
    }

    bool operator==(const BankAccount& other) const {
        return (ownerName == other.ownerName && accountNumber == other.accountNumber);
    }

    // Friend function to overload <<
    friend std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
        os << "Account Owner: " << account.ownerName << std::endl;
        os << "Account Number: " << account.accountNumber << std::endl;
        os << "Balance: $" << account.balance << std::endl;
        return os;
    }
};

// Definition of static members outside the class
int BankAccount::accountsNumber = 0;
std::vector<BankAccount*> BankAccount::users;



// Derived class SpecialBankAccount
class SpecialBankAccount : public BankAccount {
private:
    static constexpr double interestRate = 0.12;
    static int accountsNumber;
    static std::vector<SpecialBankAccount*> users;  // Static vector to store pointers to SpecialBankAccount objects

public:
    SpecialBankAccount(const std::string& name, double initialBalance)
        : BankAccount(name, initialBalance) {
        ++accountsNumber;
        users.push_back(this);  // Push pointer to current object into users vector
    }

    virtual ~SpecialBankAccount() {
        --accountsNumber;
        // Remove this object's pointer from users vector
        auto it = std::find(users.begin(), users.end(), this);
        if (it != users.end()) {
            users.erase(it);
        }
    }

    // Static member function to access accountsNumber
    static int getAccountsNumber() {
        return accountsNumber;
    }

    static void applyInterestToAll() {
        for (auto user : users) {
            user->applyInterest();
        }
    }
};

// Definition of static members outside the class
int SpecialBankAccount::accountsNumber = 0;
std::vector<SpecialBankAccount*> SpecialBankAccount::users;