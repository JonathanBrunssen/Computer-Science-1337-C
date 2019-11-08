//******************************************************************
// Project 5
// Programmer: Jonathan Brunssen
// Completed : October 20, 2019
// Status    : Complete
/*
Description:

*/
//******************************************************************



#include <iostream>				// for cin, cout, endl
#include <iomanip>

using namespace std;

//funtion preprocesser
bool menu(bool);
void texas(int &,float &, int, int &);
void getData(int &, int &, int &, int &, int &);
void outData(float, string,float, string, int, int, int);
float weightCost(int);
void outOfState(int &,float &, int, int &);
void foreign(int &,float &, int, int &);


int main()
{
	//variables
	bool isRunning = true;
	
	
	//run through the menu
	while(isRunning)
	{
		menu(isRunning);
	}
	
	return 0;
}

//start of menu fnc
bool menu(bool isRunning)
{
	//local variable
	char option;
	int numAccepted,numRejcted,packageNumber = 0;
	float totalCost;
	cout << "Menu" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Enter Location -(T)exas; (O)ut of state; (F)oreign; (X)it" << endl <<"Enter package weight and 3 dimensions." << endl;
	cout << "Enter Location -(T)exas; (O)ut of state; (F)oreign; (X)it ";
	while(!(cin >> option))
	{
		cout << "ERROR: Input not a char." << endl;
		cout << "Enter Location -(T)exas; (O)ut of state; (F)oreign; (X)it ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	option = toupper(option);
	switch(option)
	{
		case 'T':
			packageNumber++;
			texas(numAccepted,totalCost,packageNumber,numRejcted);
			break;
		case 'O':
			packageNumber++;
			outOfState(numAccepted,totalCost,packageNumber,numRejcted);
			break;
		case 'F':
			packageNumber++;
			foreign(numAccepted,totalCost,packageNumber,numRejcted);
			packageNumber++;
			break;
		case 'X':
			cout << "Number of Accepted Packages: " << numAccepted << endl;
			cout << "Number of Rejected Packages: " << numRejcted << endl;
			cout << setprecision(2) << fixed;
			cout << "Total cost: $" << totalCost << endl;
			isRunning = false;
			break;
		default:
			cout << "Option not found please try again." << endl;
			break;
	}
	return isRunning;
}//edn of fnc

//start of texas fnc
void texas(int & na ,float & tc, int pn, int & nr)
{
	//local variables
	int weight,l,w,h,largest = 0;
	float wc,tcsw;
	string location = "Texas";
	string msg = "Accepted";
	
	getData(weight,l,w,h,largest);
	
	if((weight < 50) && ((2*(l+w+h-largest)) <= 10))
	{
		wc = weightCost(weight);
		tcsw += wc;
		tc += wc;
		outData(wc,msg,0,location,weight,pn,tcsw);
		na++;
	}
	else
	{
		msg = "Rejected";
		outData(0,msg,0,location,weight,pn,tcsw);
		nr++;
	}
	
}//end of fnc

//start of fnc
void getData(int & weight, int & l , int & w, int & h, int &largest)
{
	cout << "Enter all data in integer form." << endl;
	cout << "Enter the Weight of the package: ";
	while((!(cin >> weight)) || (weight <= 0))
	{
		cout << "ERROR: Invalid data." << endl;
		cout << "Enter the Weight of the package: ";
		cin.clear();
		cin.ignore(100, '\n');	
	}
	
	cout << "Enter the Length of the package: ";
	while((!(cin >> l)) || (l <= 0) || (l >= 6))
	{
		cout << "ERROR: Invalid data." << endl;
		cout << "Enter the Length of the package: ";
		cin.clear();
		cin.ignore(100, '\n');	
	}
	
	largest = l;
	
	cout << "Enter the Width of the package: ";
	while((!(cin >> w)) || (w <= 0) || (w >= 6))
	{
		cout << "ERROR: Invalid data." << endl;
		cout << "Enter the Width of the package: ";
		cin.clear();
		cin.ignore(100, '\n');	
	}
	
	if (w > largest)
	{
		largest = w;
	}
	
	cout << "Enter the Height of the package: ";
	while((!(cin >> h)) || (h <= 0) || (h >= 6))
	{
		cout << "ERROR: Invalid data." << endl;
		cout << "Enter the Height of the package: ";
		cin.clear();
		cin.ignore(100, '\n');	
	}
	
	if(h > largest)
	{
		largest = h;
	}
}//end of fnc

//start of weightcost fnc
float weightCost(int weight)
{
	if(weight == 1)
		return 1.50;
	else if(weight == 2)
		return 2.10;
	else if(weight == 3)
		return 4.00;
	else if(weight <=5)
		return 6.75;
	else if(weight <=7)
		return 9.90;
	else if(weight <=10)
		return 14.95;
	else if(weight <= 13)
		return 19.40;
	else if(weight <= 16)
		return 24.20;
	else if(weight <= 20)
		return 27.30;
	else if(weight <= 25)
		return 31.90;
	else if(weight <= 30)
		return 38.50;
	else if(weight <= 35)
		return 43.50;
	else if(weight <= 40)
		return 44.80;
	else if(weight <= 45)
		return 47.40;
	else if(weight <= 50)
		return 55.20;	
}//end of weight cost fnc

//start of outData fnc 
void outData(float wc, string msg,float sc, string loc, int weight, int pn, int tcsw)
{
	cout << "Package Number: " << pn << endl;
	cout << "Location: " << loc << endl;
	cout << "Status: " << msg << endl;
	cout << "Weight: " << weight << " Pounds" << endl;
	cout << setprecision(2) << fixed;
	if(sc > 0)
	{
		cout << "Service Fee: $" << sc;
	}
	cout << "cost: $" << tcsw <<endl;
	cout << endl;
}// end of fnc

//start of out of state fnc
void outOfState(int & na,float & tc, int pn, int & nr)
{
	//local variables
	int weight,l,w,h,largest = 0;
	float wc,tcsw;
	float sc = 35.00;
	string location = "Out Of State";
	string msg = "Accepted";
	
	getData(weight,l,w,h,largest);
	
	if((weight < 50) && ((2*(l+w+h-largest)) <= 10))
	{
		wc = weightCost(weight);
		tcsw += wc + sc;
		tc += wc;
		outData(wc,msg,sc,location,weight,pn,tcsw);
		na++;
	}
	else
	{
		msg = "Rejected";
		outData(0,msg,0,location,weight,pn,tcsw);
		nr++;
	}
	
} // end of fnc

//start of foreign pkg fnc
void foreign(int & na,float & tc, int pn, int &nr)
{
	//local variables
	int weight,l,w,h,largest = 0;
	float wc,tcsw;
	float sc = 40.00;
	string location = "Foreign";
	string msg = "Accepted";
	
	getData(weight,l,w,h,largest);
	
	if((weight < 50) && ((2*(l+w+h-largest)) <= 10))
	{
		wc = weightCost(weight);
		tcsw += wc + sc;
		tc += wc;
		outData(wc,msg,sc,location,weight,pn,tcsw);
		na++;
	}
	else
	{
		msg = "Rejected";
		outData(0,msg,0,location,weight,pn,tcsw);
		nr++;
	}
	
}//end of foreign fnc






