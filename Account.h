#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <ctime>

class Account {
    private:
        int id;
        int cust_id;
        int teller_id;
        int branch_id;
        time_t openingDate;
        double currentBalance;
        double interestRate;

        static int ID;
};

#endif
