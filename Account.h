#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <ctime>

class Account {
    private:
        int id;
        int cust_id;
        int teller_id;
        int branch_id;
        time_t opening_date;
        double current_balance;
        double interest_rate;

        // keeping track of id for next account
        static int ID;
    
    public:
        Account(
            int id, 
            int cust_id, 
            int teller_id, 
            int branch_id, 
            time_t opening_date, 
            double current_balance, 
            // interest rate can be either 0 or >0 i.e. current or savings
            double interest_rate
        );
        // to insert it into a set<T>
        bool operator<(const Account &a) const;

        static void setNextID(int id);

        void print() const;
};

#endif
