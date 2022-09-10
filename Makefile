main: main.o Bank.o Branch.o Employee.o Customer.o Account.o Loan.o Menu.o string.o
	g++ main.o Bank.o Branch.o Employee.o Customer.o Account.o Loan.o Menu.o string.o -o main

main.o: main.cpp CSV.h
	g++ -c main.cpp

Bank.o: Bank.cpp Bank.h config.h
	g++ -c Bank.cpp

Branch.o: Branch.cpp Branch.h config.h
	g++ -c Branch.cpp

Employee.o: Employee.cpp Employee.h config.h
	g++ -c Employee.cpp

Customer.o: Customer.cpp Customer.h config.h
	g++ -c Customer.cpp

Account.o: Account.cpp Account.h 
	g++ -c Account.cpp

Loan.o: Loan.cpp Loan.h 
	g++ -c Loan.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp

string.o: string.cpp string.h
	g++ -c string.cpp

clean:
	rm *.o main
