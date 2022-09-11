#include "Person.h"
#include <iostream>
#include <sstream>

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

int Person::getId() const {
    return id;
}
int Person::getBranchId() const {
    return branch_id;
}
std::string Person::getPasshash() const {
    return passhash;
}
std::string Person::getName() const {
    return name;
}
std::string Person::getPhone() const {
    return phone;
}
Address Person::getAddress() const {
    return address;
}
std::string Person::getEmail() const {
    return email;
}
time_t Person::getRegistrationDate() const {
    return registration_date;
}

std::string Person::toCSV() const {
    std::stringstream ss; 
    ss 
        << id << "," 
        << passhash << "," 
        << name << "," 
        << phone << "," 
        << address.address << "," 
        << address.city << ","
        << address.state << ","
        << address.pincode << ","
        << address.country << ","
        << email << ","
        << registration_date << ","
        << branch_id;
    return ss.str();
}

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

bool Person::authenticate(int id, std::string password) const {
    if(id == -1){
        std::cout << "\tID: ";
        std::cin >> id;
        std::cin.ignore();
    }
    if(password == ""){
        std::cout << "\tPassword: \x1b[8m";
        std::getline(std::cin,password);
        std::cout << "\x1b[0m";
    }
    return (this->id == id && passhash == password);
}
