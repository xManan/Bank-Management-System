#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ctime>
#include "Address.h"

class Person {
    protected:
        int id;
        int branch_id;

        std::string login;
        std::string passhash;

        std::string name;
        std::string phone;
        Address address;
        std::string email;

        time_t registration_date;

        Person(
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
        public: 
            virtual bool authenticate(int branch_id=-1, std::string login="", std::string password="") const;
};

#endif
