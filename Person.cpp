#include "Person.h"
#include <iostream>

Person::Person(
    int id, 
    int branch_id, 
    std::string login, 
    std::string passhash, 
    std::string name, 
    std::string phone, 
    Address address, 
    std::string email, 
    time_t registration_date
):
    id(id),
    branch_id(branch_id),
    login(login),
    passhash(passhash),
    name(name),
    phone(phone),
    address(address),
    email(email),
    registration_date(registration_date)
{}

bool Person::authenticate(int branch_id, std::string login, std::string password) const {
    if(branch_id == -1){
        std::cout << "\tBranch ID: ";
        std::cin >> branch_id;
        std::cin.ignore();
    }
    if(login == ""){
        std::cout << "\tUsername: ";
        std::getline(std::cin,login);
    }
    if(password == ""){
        std::cout << "\tPassword: \x1b[8m";
        std::getline(std::cin,password);
        std::cout << "\x1b[0m";
    }
    return (this->login == login && passhash == password);
}
