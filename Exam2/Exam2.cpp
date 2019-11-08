//******************************************************************
// Exam 2
// Programmer: Jonathan Brunssen
// Completed : November, 2019
// Status    : Complete
/*
Description: 
Write a program that will be Point of Sale system at a food stall. 
The store sells a maximum of 25 items.   
The list of items and it price will be loaded from a text file.
Also, the sales tax will be loaded from a text file.

*/
//******************************************************************

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

//global constants
const int maxItems = 25;

//structs
struct ItemStats
{
	int numsold;
	int numSoldInTotal;
	int totalcostsold;
};

struct Menu
{
	string name;
	char handle;
	double cost;
	ItemStats stats;
};

//funtion preprocesser
void getItems(Menu[], double &);
void pointOfSale(Menu[], double);
void display(Menu[]);
void receipt(Menu[], double, double, double,int);
void salesReport(Menu[], double, int, double);

//start of main
int main()
{
	// Variable Decleration
	Menu *pMenu;
	double taxrate;
	ofstream clearfile;
	
	//clear the receipt file
	clearfile.open("Receipt.txt");
	if(clearfile.is_open())
	{
		clearfile.clear();
	}
	else
	{
		cout << "ERROR: File not found..." << endl;
	}
	clearfile.close();
	pMenu = new Menu[maxItems];
	
	//get the menu items
	getItems(pMenu,taxrate);
	
	//run the pos
	pointOfSale(pMenu,taxrate);
	
	return 0;
}//end of main

//start of getItems
void getItems(Menu *arr, double &taxrate)
{
	//local variables
	ifstream dataFile;
	ifstream taxFile;
	int i,n = 0;
	string temp,str1,str2;
	
	//open the data file
	dataFile.open("Data.dat");
	
	if(dataFile.is_open())//if the data file exists
	{
		while(!dataFile.eof() && i < maxItems)//read the data and check to make sure we dont reach eof or the end of our list
		{
			getline(dataFile,temp);
			n = temp.find(" ");//find where the data splices
			arr[i].name = temp.substr(0,n);
			str2 = temp.substr(n+1,1);
			arr[i].handle =str2[0];
			str1 = temp.substr(n+2,(temp.length() - n+2));
			arr[i].cost = stod(str1);
			i++;		
		}
	}
	else//data file does not exist
	{
		cout << "ERROR: File not found";
	}
	
	taxFile.open("TaxFile.dat");
	if(taxFile.is_open())
	{
		taxFile >> taxrate;
	}
	else
	{
		cout << "ERROR: could not find TaxFile.dat" << endl;
	}
	//close the file
	dataFile.close();
	taxFile.close();
}//end of getItems

//start of receipt function
void receipt(Menu arr[],double aftertax,double currentsale, double taxrate, int salenum)
{
	time_t tt;
	struct  tm * ti;
	
	time(&tt);
	
	ti = localtime(&tt);
	
	ofstream customerReceipt;
	
	customerReceipt.open("Receipt.txt", std::ios::app);
	
	if(customerReceipt.is_open())
	{
	
		customerReceipt << setprecision(2) << fixed;
		customerReceipt << "Sale number: " << salenum << endl;
		customerReceipt << "Date: " << asctime(ti) << endl; 
		for(int i = 0; i < maxItems; i++)
		{
			if(arr[i].stats.numsold > 0)
			{
				customerReceipt << arr[i].stats.numsold << " - " << arr[i].name << ": $" << arr[i].stats.numsold * arr[i].cost << endl;
			}
		}
		customerReceipt << "Sub total: $" << currentsale << endl;
		customerReceipt << "Sales tax: " << (taxrate * 100) - 100<< "%" << endl;
		customerReceipt << "Sales tax cost: $" << aftertax - currentsale << endl;
		customerReceipt << "Final total: $" << aftertax << endl;
		customerReceipt << endl;
	}
	else
	{
		cout << "ERROR: File not found...";
	}
	cout << endl;
	cout << "Receipt Generated..." << endl;
	customerReceipt.close();
}//end of receipt function

//start of pointOfSale
void pointOfSale(Menu arr[],double taxrate)
{
	//local varriables
	char option;
	double aftertax, currentsale,totalsales;
	int numOfSales = 0;
	
	display(arr);
	cin >> option;
	cin.ignore(1000,'\n');
	option = toupper(option);
	while(option != 'E')
	{
		if(option == 'T')//total the sale
		{
			aftertax = taxrate * currentsale;//get the after tax value
			for(int i = 0; i < maxItems; i ++)//update the total number sold
			{
				if(arr[i].cost > 0.00)
				{
					arr[i].stats.numSoldInTotal += arr[i].stats.numsold;
				}
			}
			numOfSales ++;
			receipt(arr,aftertax,currentsale,taxrate,numOfSales);
			totalsales += currentsale;

			for(int i = 0; i < maxItems; i ++)//clear the number sold
			{
				if(arr[i].stats.numsold > 0)
				{
					arr[i].stats.numsold = 0;
				}
			}
			currentsale = 0;//clear the current sale
		}
		else if(option == 'X')//exit the sale
		{
			currentsale = 0;
			for(int i = 0; i < maxItems; i ++)//clear the number sold
			{
				if(arr[i].cost > 0.00)
				{
					arr[i].stats.numsold = 0;
				}
			}
			cout << "Sale clear" << endl;
		}
		else
		{
			bool isThere = false;
			for(int i = 0; i <=maxItems; i++)//loop to find the item
			{
				if(option == arr[i].handle)//found the item
				{
					isThere = true;
					arr[i].stats.numsold++;//increment the number sold of the item
					currentsale += arr[i].cost;//add the cost to the current sale
					cout << "Added " << arr[i].name << " to the sale." << endl;
				}
			}
			if(!isThere)//item was not found
			{
				cout << "Invalid input could not find item..." << endl << "Try Again..." << endl;
			}
		}
		cout << endl;
		display(arr);
		cin >> option;
		option = toupper(option);
	}
	salesReport(arr,taxrate,numOfSales, totalsales);
	cout << "Report generated..." << endl;
	
}//end of pointOfSale

//start of sales report function
void salesReport(Menu arr[], double taxrate, int numOfSales, double totalsales)
{
	//local variables
	ofstream report;
	time_t tt;
	struct  tm * ti;
	
	time(&tt);
	
	ti = localtime(&tt);
	
	report.open("Report.txt");
	
	if(report.is_open())//if the report file exists
	{
		report << setprecision(2) << fixed;
		report << "Date: " << asctime(ti) << endl;
		report << "Number of sales: " << numOfSales << endl;
		report << "Number of Items sold:" << endl;
		for(int i = 0; i < maxItems; i++)
		{
			if(arr[i].stats.numSoldInTotal > 0)
			{
				report << "		" << arr[i].stats.numSoldInTotal << " - " << arr[i].name << " $" << arr[i].cost * arr[i].stats.numSoldInTotal << endl;
			}
		}
		report << "Subtotal: $" << totalsales << endl;
		report << "Tax: " << (taxrate*100) - 100 << endl;
		report << "Tax cost: $" << (taxrate*totalsales) - totalsales << endl;
		report << "Final total: $" << taxrate*totalsales << endl;
		
	}
	
	else//report file does not exist
	{
		cout << "ERROR: File not found" << endl;
	}
	
}//end of sales report function

//start of display function
void display(Menu arr[])
{
	cout << setprecision (2) << fixed;
	for(int i = 0; i < maxItems; i++)
	{
		if(arr[i].cost > 0.00)
		{
			cout << arr[i].handle << " - " << arr[i].name << " $" << arr[i].cost << "." << endl;
		}
	}
	cout << "X - Cancel the sale and start over." << endl;
	cout << "T - Total the sale." << endl;
	cout << "E - Close shift." << endl;
}




