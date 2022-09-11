#include <iostream>
#include <limits>
#include "Bank.h"
#include "Menu.h"

using namespace std;

int main(int argc, char **argv){
    Bank bank;
    /* bank.print(); */
    Menu admin_menu("Admin Menu", {
        {
            "Add Branch", 
            [&]()->bool{
                return false;
            }
        },
        {
            "Modify Branch", 
            [&]()->bool{
                return false;
            }
        },
        {
            "Delete Branch", 
            [&]()->bool{
                return false;
            }
        },
        {
            "List Branches", 
            [&]()->bool{
                return false;
            }
        },
        {
            "Add Employee", 
            [&]()->bool{
                return false;
            }
        },
        {
            "Modify Employee", 
            [&]()->bool{
                return false;
            }
        },
        {
            "Delete Employee", 
            [&]()->bool{
                return false;
            }
        },
        {
            "List Employees", 
            [&]()->bool{
                return false;
            }
        },
        {
            "Add Customer", 
            [&]()->bool{
                return false;
            }
        },
        {
            "Modify Customer", 
            [&]()->bool{
                return false;
            }
        },
        {
            "Delete Customer", 
            [&]()->bool{
                return false;
            }
        },
        {
            "List Customers", 
            [&]()->bool{
                return false;
            }
        },
    });

    Menu main_menu("Main Menu", {
        {
            "Admin", 
            [&]()->bool{
                if(!bank.authenticate()){
                    cout << "\n\tInvalid Credentials!\n";
                    return false;
                }
                admin_menu.draw();
                return true;
            }
        },
        {
            "Employee", 
            [&]()->bool{
                return false;
            }
        },
        {
            "Customer", 
            [&]()->bool{
                return false;
            }
        },
    });

    main_menu.draw();
}

