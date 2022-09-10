#ifndef BANK_H
#define BANK_H

#include <set>
#include "Branch.h"

class Bank {
    private:
        std::set<Branch> branches;
    public:
        Bank();
        void print() const;
};

#endif
