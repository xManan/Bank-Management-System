#ifndef LOAN_H
#define LOAN_H

#include <ctime>

class Loan {
    private:
        int id;
        int cust_id;
        int teller_id;
        int branch_id;
        time_t startingDate;
        time_t dueDate;
        double amount;
        double interestRate;

        static int ID;
};

#endif
