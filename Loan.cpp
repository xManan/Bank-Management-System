#include "Loan.h"
#include <iostream>

int Loan::ID = 0;

Loan::Loan(
    int id, 
    int cust_id, 
    int teller_id, 
    int branch_id, 
    time_t starting_date, 
    time_t due_date, 
    double current_balance, 
    double interest_rate
):
    id(id),
    cust_id(cust_id),
    teller_id(teller_id),
    branch_id(branch_id),
    starting_date(starting_date), 
    due_date(due_date),
    interest_rate(interest_rate)
{}

bool Loan::operator<(const Loan &a) const {
    return (id < a.id);
}
void Loan::setNextID(int id){
    Loan::ID = id;
}

void Loan::print() const {
    std::cout 
        << "id: " << id << "\n"
        << "cust_id: " << cust_id << "\n"
        << "teller_id: " << teller_id << "\n"
        << "branch_id: " << branch_id << "\n"
        << "starting_date: " << starting_date << "\n"
        << "due_date: " << due_date << "\n"
        << "amount: " << amount << "\n"
        << "interest_rate: " << interest_rate << std::endl;
}
