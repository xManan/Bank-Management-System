#include <fstream>
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
    // data is the format:
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
        int id = std::stoi(res[0]);
        std::string login = res[1];
        std::string passhash = res[2];
        std::string name = res[3];
        std::string phone = res[4];
        Address address = { res[5], res[6], res[7], res[8], res[9] };
        std::string email = res[10];
        time_t registration_date = std::stoul(res[11]);
        std::string position = res[12]; 
        int branch_id = std::stoi(res[13]);
        Employee e(id, branch_id, login, passhash, name, phone, address, email, registration_date, position);
        employees.insert(e);
    }
    file.close();

    // data is the format:
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
        int id = std::stoi(res[0]);
        std::string login = res[1];
        std::string passhash = res[2];
        std::string name = res[3];
        std::string phone = res[4];
        Address address = { res[5], res[6], res[7], res[8], res[9] };
        std::string email = res[10];
        time_t registration_date = std::stoul(res[11]);
        int branch_id = std::stoi(res[12]);
        Customer e(id, branch_id, login, passhash, name, phone, address, email, registration_date);
        customers.insert(e);
    }
    file.close();

}

bool Branch::operator<(const Branch &b) const {
    return (id < b.id);
}

void Branch::setNextID(int id){
    Branch::ID = id;
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
