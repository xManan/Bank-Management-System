#include "Employee.h"
#include <iomanip>
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

void Employee::display(int w[EMPLOYEE_N]) const {
    char buffer[12];
    strftime(buffer,11,"%d-%m-%Y", localtime(&registration_date));
    std::cout
        << std::left << std::setw(w[0]) << id 
        << std::left << std::setw(w[1]) << branch_id 
        << std::left << std::setw(w[2]) << name 
        << std::left << std::setw(w[3]) << phone 
        << std::left << std::setw(w[4]) << email 
        << std::left << std::setw(w[5]) << buffer
        << std::left << std::setw(w[6]) << position; 
}
