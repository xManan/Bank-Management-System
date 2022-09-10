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

        // keeping track of id for next account
        static int ID;

    public:
        Loan(
            int id, 
            int cust_id, 
            int teller_id, 
            int branch_id, 
            time_t starting_date, 
            time_t due_date, 
            double amount, 
            double interest_rate
        );
        // to insert it into a set<T>
        bool operator<(const Loan &a) const;

        static void setNextID(int id);

        void print() const;
};

#endif
