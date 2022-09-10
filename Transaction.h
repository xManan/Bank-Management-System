#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>

class Transaction {
    private:
        int id;
        time_t timestamp;
        double amount;
        int sender_id;
        int reciever_id;
        int emp_id;
};

#endif
