#include "Account.h"
#include <iostream>

int Account::ID = 0;

Account::Account(
    int id, 
    int cust_id, 
    int teller_id, 
    int branch_id, 
    time_t opening_date, 
    double current_balance, 
    double interest_rate
):
    id(id),
    cust_id(cust_id),
    teller_id(teller_id),
    branch_id(branch_id),
    opening_date(opening_date),
    current_balance(current_balance),
    interest_rate(interest_rate)
{}

bool Account::operator<(const Account &a) const {
    return (id < a.id);
}

void Account::setNextID(int id){
    Account::ID = id;
}

void Account::print() const {
    std::cout 
        << "id: " << id << "\n"
        << "cust_id: " << cust_id << "\n"
        << "teller_id: " << teller_id << "\n"
        << "branch_id: " << branch_id << "\n"
        << "opening_date: " << opening_date << "\n"
        << "current_balance: " << current_balance << "\n"
        << "interest_rate: " << interest_rate << std::endl;
}
