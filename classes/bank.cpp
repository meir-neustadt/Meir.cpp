#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include "bank.h"


int main() {
    // Create BankAccount objects
    BankAccount acc1("John Doe", 1000.0);
    BankAccount acc2("Jane Smith", 500.0);
    SpecialBankAccount sAcc("AAA", 1200.0);

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
    std::cout << "Account 1 and Account 2 are" << (acc1 == acc2 ? " the same" : " different") << '.' << std::endl;

    // Output accountsNumber from both classes
    std::cout << "Total BankAccounts: " << BankAccount::getAccountsNumber() << std::endl;
    std::cout << "Total SpecialBankAccounts: " << SpecialBankAccount::getAccountsNumber() << std::endl;

    // Apply interest to all accounts
    BankAccount::applyInterestToAll();

    // Display account details after applying interest to all
    std::cout << "Account 1 after applying interest to all:" << std::endl;
    std::cout << acc1 << std::endl;

    std::cout << "Account 2 after applying interest to all:" << std::endl;
    std::cout << acc2 << std::endl;

    std::cout << "Special Account after applying interest to all:" << std::endl;
    std::cout << sAcc << std::endl;

    // Apply interest to special accounts
    SpecialBankAccount::applyInterestToAll();
    
    std::cout << "Special Account after applying interest:" << std::endl;
    std::cout << sAcc << std::endl;

    return 0;
}
