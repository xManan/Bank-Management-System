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

        static int ID;
    
    public:
        Account(
            int id, 
            int cust_id, 
            int teller_id, 
            int branch_id, 
            time_t opening_date, 
            double current_balance, 
            double interest_rate
        );
        bool operator<(const Account &a) const;

        static void setNextID(int id);

        void print() const;
};

#endif
