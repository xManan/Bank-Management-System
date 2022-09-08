#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <set>
#include "Person.h"
#include "Account.h"
#include "Loan.h"

class Customer: public Person {
    private:
        std::set<Account> accounts;
        std::set<Loan> loans;

        static int ID;
};

#endif
