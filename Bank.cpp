#include "Bank.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include "Branch.h"
#include "string.h"
#include "config.h"

Bank::Bank(){
    // reading data from file when the contructor is called
    std::ifstream file(ADMIN_DATA_FILE);
    std::string line;
    std::getline(file, line);
    std::vector<std::string> res = split_str(line, ',');
    int branch_id = std::stoi(res[11]);
    int id = std::stoi(res[0]);
    std::string passhash = res[1];
    std::string name = res[2];
    std::string phone = res[3];
    Address address = { res[4], res[5], res[6], res[7], res[8] };
    std::string email = res[9];
    time_t registration_date = std::stoul(res[10]);
    Person p(id, branch_id, passhash, name, phone, address, email, registration_date);
    admin = p;
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

Branch* Bank::findBranch(int id) const {
    Branch b(id);
    std::set<Branch>::const_iterator it = branches.find(b);
    if(it == branches.end()){
        return nullptr;
    }
    return const_cast<Branch*>(&(*it));
}

void Bank::updateBranchData() const {
    std::ofstream file(BRANCH_DATA_FILE);
    if(!file.is_open()){
        throw "could not open file!";
    }
    std::stringstream ss;
    ss << Branch::getNextID() << "\n";
    for (std::set<Branch>::const_iterator it=branches.begin(); it!=branches.end(); ++it) {
        ss << it->toCSV() << "\n";
    }
    file.write(ss.str().c_str(), ss.str().length());
    file.close();
}

void Bank::addBranch(Branch b){
    branches.insert(b);
    /* updateBranchData(); */
}
void Bank::deleteBranch(Branch b){
    branches.erase(b);
}
void Bank::display() const {
    int w[BRANCH_N] = { 5, 12, 30, 15, 15, 15, 15, 15 };
    std::cout << "\n\t"
        << std::left << std::setw(w[0]) << "ID" 
        << std::left << std::setw(w[1]) << "MANAGER ID" 
        << std::left << std::setw(w[2]) << "ADDRESS" 
        << std::left << std::setw(w[3]) << "CITY" 
        << std::left << std::setw(w[4]) << "STATE"
        << std::left << std::setw(w[5]) << "PINCODE"
        << std::left << std::setw(w[6]) << "COUNTRY"
        << std::left << std::setw(w[7]) << "PHONE\n" << std::endl; 
    for (std::set<Branch>::const_iterator it=branches.begin(); it!=branches.end(); ++it) {
        std::cout << "\t";
        it->display(w);
        std::cout << "\n";
    }
}
