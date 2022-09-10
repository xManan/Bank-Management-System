#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <set>
#include "Person.h"
#include "Account.h"
#include "Loan.h"

class Customer: public Person {
    private:
        std::set<Account> accounts;
        std::set<Loan> loans;

        static int ID;
    public:
        Customer(
            int id, 
            int branch_id, 
            std::string login, 
            std::string passhash, 
            std::string name, 
            std::string phone, 
            Address address, 
            std::string email, 
            time_t registration_date
        );
        bool operator<(const Customer &c) const;

        static void setNextID(int id);

        void print() const;

};

#endif
