#include <iostream>
#include <limits>
#include "Bank.h"
#include "Menu.h"

using namespace std;

int main(int argc, char **argv){
    Bank bank;
    
    Menu main_menu("Main Menu", {
        {
            "Admin", 
            [&]()->bool{
                if(!bank.authenticate()){
                    cout << "\n\tInvalid Credentials!\n";
                    return false;
                }
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
                admin_menu.draw();
                return true;
            }
        },
        {
            "Employee", 
            [&]()->bool{
                int id;
                cout << "\tBranch ID: ";
                cin >> id;
                cin.ignore();
                Branch* res = bank.findBranch(id);
                if(res == nullptr){
                    cout << "\n\tBranch not found!\n";
                    return false;
                }
                int emp_id;
                cout << "\tEmployee ID: ";
                cin >> emp_id;
                cin.ignore();
                if(!res->authenticateEmployee(emp_id)){
                    cout << "\n\tInvalid Credentials!\n";
                    return false;
                }
                const Employee *emp = res->findEmployee(emp_id);
                vector<choice> emp_c = {
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
                        "Create Account",
                        [&]()->bool{
                            return false;
                        }
                    },
                    {
                        "Modify Account",
                        [&]()->bool{
                            return false;
                        }
                    },
                    {
                        "Delete Account",
                        [&]()->bool{
                            return false;
                        }
                    },
                };
                if(res->isManager(emp_id)){
                    vector<choice> mng_c(emp_c);
                    mng_c.insert(mng_c.end(), {
                        {
                            "Add Employee",
                            [&]()->bool{
                                int id = Employee::getNextID();
                                Employee::setNextID(Employee::getNextID()+1);
                                int branch_id = res->getId();
                                std::string passhash;
                                std::string name;
                                std::string phone;
                                Address address;
                                std::string email;
                                time_t registration_date = time(0);
                                std::string position;
                                cout << "\n\tName: ";
                                getline(cin,name);
                                cout << "\tPhone No: ";
                                getline(cin,phone);
                                cout << "\tEmail: ";
                                getline(cin,email);
                                cout << "\tAddress: ";
                                getline(cin,address.address);
                                cout << "\tCity: ";
                                getline(cin,address.city);
                                cout << "\tState: ";
                                getline(cin,address.state);
                                cout << "\tPincode: ";
                                getline(cin,address.pincode);
                                cout << "\tCountry: ";
                                getline(cin,address.country);
                                cout << "\tPosition: ";
                                getline(cin,position);
                                cout << "\tCreate Password: ";
                                getline(cin,passhash);
                                Employee e(id,branch_id,passhash,name,phone,address,email,registration_date,position);
                                res->addEmployee(e);
                                cout << "\n\tEmployee with emp_id : " << id <<  " Succesfully Added\n";
                                return false;
                            }
                        },
                        {
                            "List Employees",
                            [&]()->bool{
                                return false;
                            }
                        }
                    });
                    Menu manager_menu("Manager Menu", mng_c);
                    manager_menu.draw();
                    return true;

                } 
                Menu employee_menu("Employee Menu", emp_c);
                employee_menu.draw();
                return true;
            }
        },
        {
            "Customer", 
            [&]()->bool{
                int id;
                cout << "\tBranch ID: ";
                cin >> id;
                cin.ignore();
                const Branch* res = bank.findBranch(id);
                if(res == nullptr){
                    cout << "\n\tBranch not found!\n";
                    return false;
                }
                if(!res->authenticateCustomer()){
                    cout << "\n\tInvalid Credentials!\n";
                    return false;
                }
                return true;
            }
        },
    });

    main_menu.draw();
}

