#include "Bank.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "Branch.h"
#include "string.h"
#include "config.h"

Bank::Bank(){
    // reading data from file when the contructor is called
    std::ifstream file(EMPLOYEE_DATA_FILE);
    std::string line;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(file, line);
    std::vector<std::string> res = split_str(line, ',');
    int branch_id = std::stoi(res[13]);
    int id = std::stoi(res[0]);
    std::string login = res[1];
    std::string passhash = res[2];
    std::string name = res[3];
    std::string phone = res[4];
    Address address = { res[5], res[6], res[7], res[8], res[9] };
    std::string email = res[10];
    time_t registration_date = std::stoul(res[11]);
    std::string position = res[12]; 
    Employee e(id, branch_id, login, passhash, name, phone, address, email, registration_date, position);
    admin = e;
    file.close();

    file.open(BRANCH_DATA_FILE);
    if(!file.is_open()){
        throw "could not open file!";
    }
    // data is in the format:
    // next ID
    // comma seperated values for branch 1
    // comma seperated values for branch 2
    // ...
    if(std::getline(file, line)){
        Branch::setNextID(std::stoi(line));
    }
    while(std::getline(file, line)){
        std::vector<std::string> res = split_str(line, ',');
        int branch_id = std::stoi(res[0]);
        Address address = { res[1], res[2], res[3], res[4], res[5] };
        std::string phone = res[6];
        int manager_id = std::stoi(res[7]);
        Branch b(branch_id, address, phone, manager_id);
        branches.insert(b);
    }
    file.close();
}

void Bank::print() const {
    admin.print();
    std::cout << std::endl;
    for(std::set<Branch>::const_iterator it = branches.begin(); it != branches.end(); ++it){
        it->print();
    }
}

bool Bank::authenticate() const {
    return admin.authenticate(0);
}
