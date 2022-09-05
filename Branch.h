#ifndef BRANCH_H
#define BRANCH_H

#include <string>
#include "Employee.h"
#include "Customer.h"

class Branch {
    private:
        int id;
        std::string address;
        std::string phone;
        int manager_id;

        std::set<Employee> employees;
        std::set<Customer> customers;
        static int ID;
};

#endif
