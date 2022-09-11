#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ctime>
#include "Address.h"

class Person {
    protected:
        int id;
        int branch_id;

        std::string passhash;

        std::string name;
        std::string phone;
        Address address;
        std::string email;

        time_t registration_date;

    public: 
        Person(
            int id=0, 
            int branch_id=0, 
            std::string passhash="", 
            std::string name="", 
            std::string phone="", 
            Address address={"","","","",""}, 
            std::string email="", 
            time_t registration_date=time(0)
        );
        virtual void print() const;
        virtual bool authenticate(int branch_id=-1, std::string password="") const;
};

#endif
