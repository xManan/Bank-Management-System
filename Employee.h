#ifndef EMPLOYEE_H
#define EMPLOYEE_H
    
#include "Person.h"
#include <iostream>

class Employee: public Person {
    private:
        std::string position;

        // keeping track of id for next account
        static int ID;

    public:
        Employee(
            int id=0, 
            int branch_id=0, 
            std::string login="", 
            std::string passhash="", 
            std::string name="", 
            std::string phone="", 
            Address address={"","","","",""}, 
            std::string email="", 
            time_t registration_date=time(0),
            std::string position=""
        );
        // to insert it into a set<T>
        bool operator<(const Employee &e) const;

        static void setNextID(int id);

        void print() const;

};

#endif
