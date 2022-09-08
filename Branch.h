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

        std::set<Employee> employees;
        std::set<Customer> customers;
        std::set<Transaction> transactions;

        static int ID;

    public:
        Branch(int id, Address address, std::string phone, int manager_id);
        
        bool operator<(const Branch &b) const ;

        static void setNextID(int id);

        void print() const;

        void printEmployees () const;
};

#endif
