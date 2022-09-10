#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
#include <string>
#include "config.h"
#include "Employee.h"
#include "Customer.h"
#include "Account.h"
#include "Loan.h"
#include "Transaction.h"
#include "Address.h"

class Branch {
    private:
        int id;
        Address address;
        std::string phone;
        int manager_id;

        // using set to make sure only branches with unique ids are present
        std::set<Employee> employees;
        std::set<Customer> customers;
        std::set<Transaction> transactions;
        
        // keeping track of id for next branch
        static int ID;

    public:
        Branch(int id, Address address, std::string phone, int manager_id);

        // to insert it into a set<T>
        bool operator<(const Branch &b) const ;

        static void setNextID(int id);

        void print() const;
};

#endif
