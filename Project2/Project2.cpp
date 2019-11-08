//******************************************************************
// Project 1
// Programmer: Jonathan Brunssen
// Completed : September 5, 2019
// Status    : Complete
/*
Description:
Write a C++ program to help you balance your checkbook at the end of the month.
The program should have the user enter the initial balancefollowed by a series of transactions.
For each transaction, first have the user enter a transaction type.
The valid transaction types are:
   C -process a check.
   D -process a deposit. 
   E -do end of month processing and exit the program.
*/
//******************************************************************



#include <iostream>				// for cin, cout, endl
#include <iomanip>

using namespace std;

//preprocess of funtions
void getBalance(double &);
void processCheck(double &, double &);
void depositCheck(double &, double);
void endOfMonthProcess(double &, double);

//start of main
int main()
{
	//initialize data
	bool flag = true;
	char option;
	double initbal,totalservice;
	
	cout << "Checkbook Balancing Program\n" << endl;
	getBalance(initbal);
	
	while(flag)
	{
		cout << "Commands:\n" << "C -process a check\n" << "D -process a deposit\n" << "E -end the program\n";
		
		//select from menu
		cout << "Enter transaction type: ";
		//input validation loop
		while(!(cin >> option) || ((option != 'C') && (option != 'D') && (option != 'E')))
		{
			cout << "ERROR: Input is either not a char or is not capatalized." << endl;
			cout << "Enter transaction type: ";
			cin.clear();
			cin.ignore(100, '\n');
		}//end of input validation loop
		cout << endl;
		
		switch(option)
		{
			//process a check
			case 'C':
				processCheck(initbal, totalservice);
				break;
				
			//process a deposit
			case 'D':
				depositCheck(initbal, totalservice);
				break;
				
			//do end of month processing and exit the program
			case 'E':
				endOfMonthProcess(initbal, totalservice);
				flag = false;
				break;
		}
	}

	return 0;	
}//end of main

//start of get balance function wit get the initial balance
void getBalance(double & x)
{	
	cout << "Enter the beginning balance: ";
	
	//input validation loop
	while(!(cin >> x) || (x < 0))
	{
		cout << "ERROR: Input is either not a number or is less than 0. Please try again." << endl;
		cout << "Enter the beginning balance: ";
		cin.clear();
		cin.ignore(100, '\n');
	}//end of input validation loop
	
	
} // end of get balance function

//start of process check function
void processCheck(double & bankval, double & totalservice)
{
	//local variable decleration
	double checkval;
	double servicecharge = 0.35; 
	
	cout << "Enter the amount of the check: ";
	
	//input validation loop
	while(!(cin >> checkval) || (checkval < 0))
	{
		cout << "ERROR: Input is either not a number or is less than 0. Please try again." << endl;
		cout << "Enter the amount of the check: ";
		cin.clear();
		cin.ignore(100, '\n');
	}//end of input validation loop
	cout << endl;
	
	//calculate bank
	bankval -= checkval;
	
	//calculate service fee
	totalservice += servicecharge;
	
	//print output
	cout << setprecision(2) << fixed;
	cout << "Balance : $" << bankval << endl;
	cout << "Service charge for check: $" << servicecharge << endl;
	cout << "Total service charges: $" << totalservice << endl;
	cout << endl;
	
}//end if process check function

//start of deposit check function
void depositCheck(double & bankval, double totalservice)
{
	//local variable decleration
	double checkval;
	
	cout << "Enter the amount of the check you are depositing: ";
	
	//input validation loop
	while(!(cin >> checkval) || (checkval < 0))
	{
		cout << "ERROR: Input is either not a number or is less than 0. Please try again." << endl;
		cout << "Enter the amount of the check: ";
		cin.clear();
		cin.ignore(100, '\n');
	}//end of input validation loop
	cout << endl;
	
	//calculate bank
	bankval += checkval;
	
	//print output
	cout << setprecision(2) << fixed;
	cout << "Balance : $" << bankval << endl;
	cout << "Total service charges: $" << totalservice << endl;
	cout << endl;
	
}

//start of end of month processing function
void endOfMonthProcess(double & bankval, double totalservice)
{
	cout << "Processing end of month..." << endl;
	bankval -= totalservice;
	cout << setprecision(2) << fixed;
	cout << "Balance : $" << bankval << endl;
}//end of end of month processing funtion


