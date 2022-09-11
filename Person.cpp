#include "Person.h"
#include <iostream>

Person::Person(
    int id, 
    int branch_id, 
    std::string passhash, 
    std::string name, 
    std::string phone, 
    Address address, 
    std::string email, 
    time_t registration_date
):
    id(id),
    branch_id(branch_id),
    passhash(passhash),
    name(name),
    phone(phone),
    address(address),
    email(email),
    registration_date(registration_date)
{}


void Person::print() const {
    std::cout
        << "id : " << id << "\n"
        << "branch_id : " << branch_id << "\n"
        << "passhash: " << passhash << "\n"
        << "name: " << name << "\n"
        << "phone: " << phone << "\n"
        << "address: " << address.address << "\n"
        << "email: " << email << "\n"
        << "registration_date: " << registration_date << std::endl;
}

bool Person::authenticate(int branch_id, std::string password) const {
    if(branch_id == -1){
        std::cout << "\tBranch ID: ";
        std::cin >> branch_id;
        std::cin.ignore();
    }
    if(password == ""){
        std::cout << "\tPassword: \x1b[8m";
        std::getline(std::cin,password);
        std::cout << "\x1b[0m";
    }
    return (passhash == password);
}
