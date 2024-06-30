#include <iostream>
#include <string>
#include <ctime>

#define MIN_ACCOUNT_NUMBER 10000
#define MAX_ACCOUNT_NUMBER 99999

class BankAccount {
private:
    std::string ownerName;
    long accountNumber;
    double balance;
    static constexpr double interestRate = 0.05;  // Annual interest rate (5%)
    static int accountsNumber;  // Static variable to store number of accounts

public:
    // Constructor
    BankAccount(const std::string& name, double initialBalance)
        : ownerName(name), balance(initialBalance) {
            accountNumber = generateAccountNumber(); // Assign unique account number
            accountsNumber++;
        }

    // destructor
    ~BankAccount() {--accountsNumber;};

    // Methods

    // Static method to generate random account numbers
    static long generateAccountNumber() {
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation
        return MIN_ACCOUNT_NUMBER + std::rand() % (MAX_ACCOUNT_NUMBER - MIN_ACCOUNT_NUMBER + 1);
    }

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


int BankAccount::accountsNumber = 0;



int main() {
    // Create BankAccount objects
    BankAccount acc1("John Doe", 1000.0);
    BankAccount acc2("Jane Smith", 500.0);

    // Perform operations
    acc1.deposit(200.0);
    acc2.withdraw(100.0);

    // Display account details
    std::cout << "Account 1 details:" << std::endl;
    std::cout << acc1 << std::endl;

    std::cout << "Account 2 details:" << std::endl;
    std::cout << acc2 << std::endl;

    // Transfer funds between accounts
    acc1.transferTo(acc2, 300.0);

    // Apply interest to an account
    acc1.applyInterest();

    // Display account details after applying interest
    std::cout << "Account 1 after applying interest:" << std::endl;
    std::cout << acc1 << std::endl;

    // Perform operator overloading
    BankAccount acc3 = acc1 + acc2;
    std::cout << "Combined account details:" << std::endl;
    std::cout << acc3 << std::endl;

    // Equality comparison
    std::cout << "Account 1 and Account 2 have are" << (acc1 == acc2 ? " the same"
: " different") << '.';
    return 0;
}
