#ifndef EMPLOYEE_H
#define EMPLOYEE_H
    
#include "Person.h"
#include <iostream>

class Employee: public Person {
    private:
        std::string position;
        static int ID;
    public:
        Employee(
            int id, 
            int branch_id, 
            std::string login, 
            std::string passhash, 
            std::string name, 
            std::string phone, 
            Address address, 
            std::string email, 
            time_t registration_date,
            std::string position
        );
        bool operator<(const Employee &e) const;

        static void setNextID(int id);

        void print() const;

};

#endif
