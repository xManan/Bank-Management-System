#include "Bank.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Branch.h"
#include "string.h"
#include "config.h"

Bank::Bank(){
    std::ifstream file(BRANCH_DATA_FILE);
    if(!file.is_open()){
        throw "could not open file!";
    }
    std::string line;
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
    for(std::set<Branch>::const_iterator it = branches.begin(); it != branches.end(); ++it){
        it->print();
    }
}
