#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ctime>

class Person {
    protected:
        int id;

        std::string login;
        int passhash;

        std::string name;
        std::string phone;
        std::string address;
        std::string email;

        time_t registrationDate;
};

#endif
