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

        // keeping track of id for next account
        static int ID;

    public:
        Customer(
            int id=0, 
            int branch_id=0, 
            std::string passhash=0, 
            std::string name="", 
            std::string phone="", 
            Address address={"","","","",""}, 
            std::string email="", 
            time_t registration_date=time(0)
        );
        // to insert it into a set<T>
        bool operator<(const Customer &c) const;

        static void setNextID(int id);

        void print() const;

};

#endif
