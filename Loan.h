#ifndef LOAN_H
#define LOAN_H

#include <ctime>

class Loan {
    private:
        int id;
        int cust_id;
        int teller_id;
        int branch_id;
        time_t starting_date;
        time_t due_date;
        double amount;
        double interest_rate;

        static int ID;

    public:
        Loan(
            int id, 
            int cust_id, 
            int teller_id, 
            int branch_id, 
            time_t starting_date, 
            time_t due_date, 
            double current_balance, 
            double interest_rate
        );
        bool operator<(const Loan &a) const;
        static void setNextID(int id);

        void print() const;
};

#endif
