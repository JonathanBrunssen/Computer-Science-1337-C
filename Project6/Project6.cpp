//******************************************************************
// Project 6
// Programmer: Jonathan Brunssen
// Completed : November, 2019
// Status    : Complete
/*
Description: 
In this assignment you must create and use a struct to hold the general employee information for one employee

*/
//******************************************************************

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>

using namespace std;

//structs
struct Employee
{
	int ID;
	string Name;
	float PayRate;
	int EmployeeType;
};

//funtion preprocesser
void getInfo(Employee []);
void timeCard(Employee [],float []);
void report(Employee [], float []);

//start of main
int main()
{
	// Variable Decleration
	Employee employees[4];
	float pay[4];
	
	getInfo(employees);
	
	timeCard(employees,pay);
	
	report(employees, pay);
	
	return 0;
}//end of main

//start of get info function
void getInfo(Employee arr[])
{
	for(int i = 0; i < 4; i++)
	{
		cout << "Enter Employee ID: ";
		cin >> arr[i].ID;
		cin.ignore();
		do
		{
			cout << "Enter Employee Name: ";
			getline(cin,arr[i].Name);
		}while(arr[i].Name.length() > 20);
		cout << "Enter Employee Pay Rate: ";
		cin >> arr[i].PayRate;
		cout << "Enter Employee Type (0 for union and 1 for managment): ";
		cin >> arr[i].EmployeeType;
	}
}//end of get info function

//start f time card function
void timeCard(Employee arr[], float pay[])
{
	//local variable
	float hours = 0.0;
	
	cout << "Enter Time Card Info:" << endl;
	for(int i = 0; i < 4; i++)
	{
		cout << "Hours worked for " << arr[i].Name << ": ";
		cin >> hours;
		if(hours > 40 && arr[i].EmployeeType == 0)
		{
			pay[i] = (arr[i].PayRate * 1.5) * hours;
		}
		else
		{
			pay[i] = arr[i].PayRate * hours;
		}
	}
}

//start of report function
void report(Employee arr[], float pay[])
{
	//local variables
	float tax = 0.15;
	float net, totalgross, totalnet = 0.0;
	
	cout << setprecision(2) << fixed;
	cout << "Report" << endl << endl;
	cout << "ID  Name                       Gross Pay      Tax  Net Pay" << endl;
	for(int i = 0; i < 4; i++)
	{
		net = pay[i] - (pay[i] * tax);
		totalgross += pay[i];
		totalnet += net;
		cout << arr[i].ID  << "   "<< arr[i].Name << "                 " << pay[i] << "      " << pay[i] * tax << " " << net << endl;
	}
	cout << "Total Gross Pay: $" << totalgross << endl;
	cout << "Total Net Pay: $" << totalnet << endl;
}
