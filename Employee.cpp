#include "Employee.h"
#include <sstream>

int Employee::ID = 0;

Employee::Employee(
    int id, 
    int branch_id, 
    std::string passhash, 
    std::string name, 
    std::string phone, 
    Address address, 
    std::string email, 
    time_t registration_date,
    std::string position
):
    Person(id, branch_id, passhash, name, phone, address, email, registration_date),
    position(position) 
{}

bool Employee::operator<(const Employee &e) const {
    return (id < e.id);
}

int Employee::getNextID(){
    return Employee::ID;
}
void Employee::setNextID(int id){
    Employee::ID = id;
}
std::string Employee::toCSV() const {
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
        << position << ","
        << branch_id;
    return ss.str();
}
void Employee::print() const {
    std::cout
        << "id : " << id << "\n"
        << "branch_id : " << branch_id << "\n"
        << "passhash: " << passhash << "\n"
        << "name: " << name << "\n"
        << "phone: " << phone << "\n"
        << "address: " << address.address << "\n"
        << "email: " << email << "\n"
        << "registration_date: " << registration_date << "\n"
        << "position: " << position << std::endl;
}

