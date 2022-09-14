#ifndef EMPLOYEE_H
#define EMPLOYEE_H
    
#include "Person.h"
#include <iostream>

#define EMPLOYEE_N 7

class Employee: public Person {
    private:
        std::string position;

        // keeping track of id for next account
        static int ID;

    public:
        Employee(
            int id=0, 
            int branch_id=0, 
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
        static int getNextID();

        std::string toCSV() const; 

        void print() const;
        void display(int w[EMPLOYEE_N]) const;
        void update(std::string branch_id, Address address, std::string phone, std::string email, std::string position);

};

#endif
