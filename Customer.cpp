#include "config.h"
#include "string.h"
#include "Customer.h"
#include <fstream>
#include <iostream>

int Customer::ID = 0;

Customer::Customer(
    int id, 
    int branch_id, 
    std::string passhash, 
    std::string name, 
    std::string phone, 
    Address address, 
    std::string email, 
    time_t registration_date
):
    Person(id, branch_id, passhash, name, phone, address, email, registration_date)
{
    std::ifstream file(ACCOUNT_DATA_FILE);
    // data is in the format:
    // next ID
    // comma seperated values for account 1
    // comma seperated values for account 2
    // ...
    if(!file.is_open()){
        throw "could not open file!";
    }
    std::string line;
    if(std::getline(file, line)){
        Account::setNextID(std::stoi(line));
    }
    while(std::getline(file,line)){
        std::vector<std::string> res = split_str(line,',');
        int cust_id = std::stoi(res[1]);
        if(this->id != cust_id){
            continue;
        }
        int id = std::stoi(res[0]);
        int teller_id = std::stoi(res[2]);
        int branch_id = std::stoi(res[3]);
        time_t opening_date = std::stoul(res[4]);
        double current_balance = std::stod(res[5]);
        double interest_rate = std::stod(res[6]);
        Account a(id, cust_id, teller_id, branch_id, opening_date, current_balance, interest_rate);
        accounts.insert(a);
    }
    file.close();

    // data is in the format:
    // next ID
    // comma seperated values for loan 1
    // comma seperated values for loan 2
    // ...
    file.open(LOAN_DATA_FILE);
    if(!file.is_open()){
        throw "could not open file!";
    }
    if(std::getline(file, line)){
        Loan::setNextID(std::stoi(line));
    }
    while(std::getline(file,line)){
        std::vector<std::string> res = split_str(line,',');
        int cust_id = std::stoi(res[1]);
        if(this->id != cust_id){
            continue;
        }
        int id = std::stoi(res[0]);
        int teller_id = std::stoi(res[2]);
        int branch_id = std::stoi(res[3]);
        time_t starting_date = std::stoul(res[4]);
        time_t due_date = std::stoul(res[5]);
        double current_balance = std::stod(res[6]);
        double interest_rate = std::stod(res[7]);
        Loan a(id, cust_id, teller_id, branch_id, starting_date, due_date, current_balance, interest_rate);
        loans.insert(a);
    }
    file.close();
}

bool Customer::operator<(const Customer &c) const {
    return (id < c.id);
}

void Customer::setNextID(int id){
    Customer::ID = id;
}

void Customer::print() const {
    std::cout
        << "id : " << id << "\n"
        << "branch_id : " << branch_id << "\n"
        << "passhash: " << passhash << "\n"
        << "name: " << name << "\n"
        << "phone: " << phone << "\n"
        << "address: " << address.address << "\n"
        << "email: " << email << "\n"
        << "registration_date: " << registration_date << std::endl;
    std::cout << "ACCOUNTS:" << std::endl;
    for (std::set<Account>::const_iterator it=accounts.begin(); it!=accounts.end(); ++it) {
        it->print();
        std::cout << "\n";
    }
    std::cout << "LOANS:" << std::endl;
    for (std::set<Loan>::const_iterator it=loans.begin(); it!=loans.end(); ++it) {
        it->print();
        std::cout << "\n";
    }
}

