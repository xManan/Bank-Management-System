#include <iostream>
#include <limits>
#include "Bank.h"
#include "Menu.h"
#include "string.h"

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
                    // TODO: check empty string
                        "Add Branch", 
                        [&]()->bool{
                            int id = Branch::getNextID();
                            Branch::setNextID(id+1);
                            Address address;
                            string phone;
                            cout << "\tPhone: ";
                            getline(cin, phone);
                            if(trim_str(phone).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tAddress: ";
                            getline(cin, address.address);
                            if(trim_str(address.address).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tCity: ";
                            getline(cin, address.city);
                            if(trim_str(address.city).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tState: ";
                            getline(cin, address.state);
                            if(trim_str(address.state).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tPincode: ";
                            getline(cin, address.pincode);
                            if(trim_str(address.pincode).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tCountry: ";
                            getline(cin, address.country);
                            if(trim_str(address.country).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            Branch b(id, address, phone);
                            bank.addBranch(b);
                            bank.updateBranchData();
                            return false;
                        }
                    },
                    {
                    // TODO: check empty string
                        "Modify Branch", 
                        [&]()->bool{
                            int branch_id;
                            cout << "\tBranch ID: ";
                            cin >> branch_id;
                            cin.ignore();
                            Branch *b = bank.findBranch(branch_id);
                            if(b == nullptr){
                                cout << "\t\nBranch Not found!\n";
                                return true;
                            }
                            cout << "\n\tPress ENTER to skip" << endl;
                            Address address;
                            string phone;
                            cout << "\tPhone (" << b->getPhone() << "): ";
                            getline(cin, phone);
                            cout << "\tAddress (" << b->getAddress().address << "): ";
                            getline(cin, address.address);
                            cout << "\tCity (" << b->getAddress().city << "): ";
                            getline(cin, address.city);
                            cout << "\tState (" << b->getAddress().state << "): ";
                            getline(cin, address.state);
                            cout << "\tPincode (" << b->getAddress().pincode << "): ";
                            getline(cin, address.pincode);
                            cout << "\tCountry (" << b->getAddress().country << "): ";
                            getline(cin, address.country);
                            b->update(address, phone);
                            return false;
                        }
                    },
                    {
                        "Change Branch Manager",
                        [&]()->bool{
                            int branch_id;
                            cout << "\tBranch ID: ";
                            cin >> branch_id;
                            cin.ignore();
                            Branch *b = bank.findBranch(branch_id);
                            if(b == nullptr){
                                cout << "\t\nBranch Not found!\n";
                                return true;
                            }
                            int mng_id;
                            cout << "\tEmployee Id: ";
                            cin >> mng_id;
                            cin.ignore();
                            Employee *e = b->findEmployee(mng_id);
                            if(e == nullptr){
                                cout << "\n\tEmployee Not found!\n";
                                return false;
                            }
                            cout << e->getId() << endl;
                            b->setManagerId(mng_id);
                            return true;
                        }
                    },
                    {
                        "Delete Branch", 
                        [&]()->bool{
                            int branch_id;
                            cout << "\tBranch ID: ";
                            cin >> branch_id;
                            cin.ignore();
                            Branch *b = bank.findBranch(branch_id);
                            if(b == nullptr){
                                cout << "\t\nBranch Not found!\n";
                                return true;
                            }
                            bank.deleteBranch(*b);
                            return false;
                        }
                    },
                    {
                        "List Branches", 
                        [&]()->bool{
                            bank.display();
                            return false;
                        }
                    },
                    {
                        "List Branch Employees", 
                        [&]()->bool{
                            int branch_id;
                            cout << "\tBranch ID: ";
                            cin >> branch_id;
                            cin.ignore();
                            Branch *b = bank.findBranch(branch_id);
                            if(b == nullptr){
                                cout << "\t\nBranch Not found!\n";
                                return true;
                            }
                            b->displayEmployees();
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
                            int id = Customer::getNextID();
                            Customer::setNextID(id+1);
                            int branch_id = res->getId();
                            std::string passhash;
                            std::string name;
                            std::string phone;
                            Address address;
                            std::string email;
                            time_t registration_date = time(0);
                            cout << "\n\tName: ";
                            getline(cin,name);
                            if(trim_str(name).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tPhone No: ";
                            getline(cin,phone);
                            if(trim_str(phone).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tEmail: ";
                            getline(cin,email);
                            if(trim_str(email).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tAddress: ";
                            getline(cin,address.address);
                            if(trim_str(address.address).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tCity: ";
                            getline(cin,address.city);
                            if(trim_str(address.city).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tState: ";
                            getline(cin,address.state);
                            if(trim_str(address.state).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tPincode: ";
                            getline(cin,address.pincode);
                            if(trim_str(address.pincode).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tCountry: ";
                            getline(cin,address.country);
                            if(trim_str(address.country).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            cout << "\tCreate Password: ";
                            getline(cin,passhash);
                            if(trim_str(passhash).length() == 0){
                                cout << "\n\tField cannot be empty!\n"; 
                                return false;
                            }
                            Customer c(id,branch_id,passhash,name,phone,address,email,registration_date);
                            res->addCustomer(c);
                            res->updateCustData();
                            cout << "\n\tCustomer with cust_id : " << id <<  " Succesfully Added\n";
                            return false;
                        }
                    },
                    {
                        "Modify Customer",
                        [&]()->bool{
                            int id;
                            cout << "\tCustomer ID: ";
                            cin >> id;
                            cin.ignore();
                            Customer *c = res->findCustomer(id);
                            if(c == nullptr){
                                cout << "\t\nCustomer Not found!\n";
                                return true;
                            }
                            cout << "\n\tPress ENTER to skip" << endl;
                            string branch_id;
                            string phone;
                            Address address;
                            string email;
                            cout << "\tBranch ID (" << c->getBranchId() << "): ";
                            getline(cin, phone);
                            cout << "\tPhone (" << c->getPhone() << "): ";
                            getline(cin, phone);
                            cout << "\tAddress (" << c->getAddress().address << "): ";
                            getline(cin, address.address);
                            cout << "\tCity (" << c->getAddress().city << "): ";
                            getline(cin, address.city);
                            cout << "\tState (" << c->getAddress().state << "): ";
                            getline(cin, address.state);
                            cout << "\tPincode (" << c->getAddress().pincode << "): ";
                            getline(cin, address.pincode);
                            cout << "\tCountry (" << c->getAddress().country << "): ";
                            getline(cin, address.country);
                            c->update(branch_id, address, phone, email);
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
                            res->displayCustomers();
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
                                if(trim_str(name).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                cout << "\tPhone No: ";
                                getline(cin,phone);
                                if(trim_str(phone).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                cout << "\tEmail: ";
                                getline(cin,email);
                                if(trim_str(email).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                cout << "\tAddress: ";
                                getline(cin,address.address);
                                if(trim_str(address.address).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                cout << "\tCity: ";
                                getline(cin,address.city);
                                if(trim_str(address.city).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                cout << "\tState: ";
                                getline(cin,address.state);
                                if(trim_str(address.state).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                cout << "\tPincode: ";
                                getline(cin,address.pincode);
                                if(trim_str(address.pincode).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                cout << "\tCountry: ";
                                getline(cin,address.country);
                                if(trim_str(address.country).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                cout << "\tPosition: ";
                                getline(cin,position);
                                if(trim_str(position).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                cout << "\tCreate Password: ";
                                getline(cin,passhash);
                                if(trim_str(passhash).length() == 0){
                                    cout << "\n\tField cannot be empty!\n"; 
                                    return false;
                                }
                                Employee e(id,branch_id,passhash,name,phone,address,email,registration_date,position);
                                res->addEmployee(e);
                                res->updateEmpData();
                                cout << "\n\tEmployee with emp_id : " << id <<  " Succesfully Added\n";
                                return false;
                            }
                        },
                        {
                            "Modify Employee",
                            [&]()->bool{
                                int id;
                                cout << "\tEmployee ID: ";
                                cin >> id;
                                cin.ignore();
                                Employee *e = res->findEmployee(id);
                                if(e == nullptr){
                                    cout << "\t\nEmployee Not found!\n";
                                    return true;
                                }
                                cout << "\n\tPress ENTER to skip" << endl;
                                string branch_id;
                                string phone;
                                Address address;
                                string email;
                                string position;
                                cout << "\tBranch ID (" << e->getBranchId() << "): ";
                                getline(cin, phone);
                                cout << "\tPhone (" << e->getPhone() << "): ";
                                getline(cin, phone);
                                cout << "\tAddress (" << e->getAddress().address << "): ";
                                getline(cin, address.address);
                                cout << "\tCity (" << e->getAddress().city << "): ";
                                getline(cin, address.city);
                                cout << "\tState (" << e->getAddress().state << "): ";
                                getline(cin, address.state);
                                cout << "\tPincode (" << e->getAddress().pincode << "): ";
                                getline(cin, address.pincode);
                                cout << "\tCountry (" << e->getAddress().country << "): ";
                                getline(cin, address.country);
                                e->update(branch_id, address, phone, email, position);
                                return false;
                            }
                        },
                        {
                            "List Employees",
                            [&]()->bool{
                                res->displayEmployees();
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

