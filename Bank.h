#ifndef BANK_H
#define BANK_H

#include <set>
#include "Branch.h"

class Bank {
    private:
        Employee admin;
        // using set to make sure only branches with unique ids are present
        std::set<Branch> branches;
    public:
        Bank();
        void print() const;
        bool authenticate() const;
};

#endif
