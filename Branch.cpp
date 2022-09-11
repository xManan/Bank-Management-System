#include <fstream>
#include <limits>
#include <sstream>
#include "config.h"
#include "Branch.h"
#include "string.h"

int Branch::ID = 0;

Branch::Branch(int id, Address address, std::string phone, int manager_id):
    id(id), 
    address(address), 
    phone(phone), 
    manager_id(manager_id)
{
    std::ifstream file(EMPLOYEE_DATA_FILE);
    // data is in the format:
    // next ID
    // comma seperated values for employee 1
    // comma seperated values for employee 2
    // ...
    if(!file.is_open()){
        throw "could not open file!";
    }
    std::string line;
    if(std::getline(file, line)){
        Employee::setNextID(std::stoi(line));
    }
    while(std::getline(file,line)){
        std::vector<std::string> res = split_str(line, ',');
        int branch_id = std::stoi(res[12]);
        if(this->id != branch_id){
            continue;
        }
        int id = std::stoi(res[0]);
        std::string passhash = res[1];
        std::string name = res[2];
        std::string phone = res[3];
        Address address = { res[4], res[5], res[6], res[7], res[8] };
        std::string email = res[9];
        time_t registration_date = std::stoul(res[10]);
        std::string position = res[11]; 
        Employee e(id, branch_id, passhash, name, phone, address, email, registration_date, position);
        employees.insert(e);
    }
    file.close();

    // data is in the format:
    // next ID
    // comma seperated values for customer 1
    // comma seperated values for customer 2
    // ...
    file.open(CUSTOMER_DATA_FILE);
    if(!file.is_open()){
        throw "could not open file!";
    }
    if(std::getline(file, line)){
        Customer::setNextID(std::stoi(line));
    }
    while(std::getline(file,line)){
        std::vector<std::string> res = split_str(line, ',');
        int branch_id = std::stoi(res[12]);
        if(this->id != branch_id){
            continue;
        }
        int id = std::stoi(res[0]);
        std::string passhash = res[1];
        std::string name = res[2];
        std::string phone = res[3];
        Address address = { res[4], res[5], res[6], res[7], res[8] };
        std::string email = res[9];
        time_t registration_date = std::stoul(res[11]);
        Customer c(id, branch_id, passhash, name, phone, address, email, registration_date);
        customers.insert(c);
    }
    file.close();

}

bool Branch::operator<(const Branch &b) const {
    return (id < b.id);
}
int Branch::getId() const {
    return id;
}
void Branch::setNextID(int id){
    Branch::ID = id;
}

bool Branch::authenticateEmployee(int emp_id) const {
    if(emp_id == 0){
        std::cout << "\tEmployee ID: ";
        std::cin >> emp_id;
        std::cin.ignore();
    }
    Employee e(emp_id);
    std::set<Employee>::const_iterator it = employees.find(e);
    if(it == employees.end()){
        std::cout << "\tPassword: \x1b[8m";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\x1b[0m";
        return false;
    }
    return it->authenticate(emp_id);
    

}

bool Branch::authenticateCustomer(int cust_id) const {
    if(cust_id == 0){
        std::cout << "\tEmployee ID: ";
        std::cin >> cust_id;
        std::cin.ignore();
    }
    Customer c(cust_id);
    std::set<Customer>::const_iterator it = customers.find(c);
    if(it == customers.end()){
        std::cout << "\tPassword: \x1b[8m";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\x1b[0m";
        return false;
    }
    return it->authenticate(cust_id);
}

Employee* Branch::findEmployee(int emp_id) const {
    std::set<Employee>::iterator it = employees.find(emp_id);
    if(it == employees.end()){
        return nullptr;
    }
    return const_cast<Employee*>(&(*it));
}

bool Branch::isManager(int emp_id) const {
    return (emp_id == this->manager_id);
}

void Branch::print() const {
    std::cout 
        << "id: " << id << "\n" 
        << "address: " << address.address << "\n" 
        << "phone: " << phone << "\n" 
        << "manager_id: " << manager_id << std::endl;
    std::cout << "EMPLOYEES:" << std::endl;
    for (std::set<Employee>::const_iterator it=employees.begin(); it!=employees.end(); ++it) {
        it->print();
        std::cout << "\n";
    }
    std::cout << "CUSTOMERS:" << std::endl;
    for (std::set<Customer>::const_iterator it=customers.begin(); it!=customers.end(); ++it) {
        it->print();
        std::cout << "\n";
    }
}

void Branch::updateEmpData() const {
    std::ofstream file(EMPLOYEE_DATA_FILE);
    if(!file.is_open()){
        throw "could not open file!";
    }
    std::stringstream ss;
    ss << Employee::getNextID() << "\n";
     for (std::set<Employee>::const_iterator it=employees.begin(); it!=employees.end(); ++it) {
        ss << it->toCSV() << "\n";
    }
    file.write(ss.str().c_str(), ss.str().length());
    file.close();
}

void Branch::addEmployee(Employee e) {
    employees.insert(e);
    updateEmpData();
}
