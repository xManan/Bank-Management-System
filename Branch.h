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
        Branch(int id=0, Address address={"","","","",""}, std::string phone="", int manager_id=0);

        // to insert it into a set<T>
        bool operator<(const Branch &b) const ;

        int getId() const;
        static void setNextID(int id);

        bool authenticateEmployee(int emp_id=0) const;
        bool authenticateCustomer(int cust_id=0) const;

        Employee* findEmployee(int emp_id) const;
        void addEmployee(Employee e);
        void updateEmpData() const;
        bool isManager(int emp_id) const;

        void print() const;
};

#endif
