#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#ifndef AAA
#include "bank.h"
#endif
#define MIN_ACCOUNT_NUMBER 10000
#define MAX_ACCOUNT_NUMBER 99999


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