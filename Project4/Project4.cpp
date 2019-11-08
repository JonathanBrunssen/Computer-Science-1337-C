//******************************************************************
// Project 1
// Programmer: Jonathan Brunssen
// Completed : October 20, 2019
// Status    : Complete
/*
Description:
A nicely-formatted table with a row for each monkey and a column for each day of the week showing the amount of food eaten by that monkey on that day.
Be sure to include row and column labels. 
Format all the food amounts so that they print with the same number of decimal places. 
This makes the decimal points line up nicely. 
Note: you should write a separate function to print this table.
The average amount of food eaten per day by the whole group of monkeys. 
This is the total food eaten by all monkeys during the week divided by seven.
Note: you should write a separate value-returning function to calculate this average.
The least amount of food eaten on any day during the week by any one monkey.
Note: you should write a separate value-returning function to find the smallest amount of food.
The greatest amount of food eaten on any day duringthe week by any one monkey. 
Note: you should write a separate value-returning function to find the largest amount of food. 
*/
//******************************************************************



#include <iostream>				// for cin, cout, endl
#include <iomanip>

using namespace std;

//gloabal constants
const int r = 3;
const int c = 8;

//funtion preprocesser
float getData(float list[r][c]);
void outData(float list[r][c], float, float, float);
float average(float list[r][c]);
float minimum(float list[r][c]);
float maximum(float list[r][c]);

int main()
{
	float monkeyData[r][c] = {1,0,0,0,0,0,0,0,
							  2,0,0,0,0,0,0,0,
							  3,0,0,0,0,0,0,0};
	float avg,min,max;						  
	
	
	//get the data
	getData(monkeyData);
	
	//find the average
	avg = average(monkeyData);
	
	//get the minimum
	min = minimum(monkeyData);
	
	//get the maximum
	max = maximum(monkeyData);
	
	//print the data
	outData(monkeyData,avg,min,max);
	
	
	
	return 0;
}

//start of get data function
float getData(float list[r][c])
{
	//creat a list of days
	string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	
	for(int foo = 0; foo < r; foo++)
	{
		for(int bar = 1; bar < c; bar++)
		{
			cout << "How mant pounds of food did monkey " << list[foo][0] << " Eat on " << days[bar-1] << ": ";
			
			//input validation
			while((!(cin >> list[foo][bar])) || (list[foo][bar] < 0))
			{
				cout << "ERROR: Input is either not a number or is less than 0. Please try again." << endl;
				cout << "How mant pounds of food did monkey " << list[foo][0] << "Eat on " << days[bar-1];
				cin.clear();
				cin.ignore(100, '\n');
			}
		}
		cout << endl;
	}
	return list[r][c];
}// end of get data function

//start of out data function
void outData(float list[r][c], float avg, float min, float max)
{
	cout << "Pounds of Food Eaten by Monkey and Day of Week" <<endl;
	cout << endl;
	cout << "Monkey Sun    Mon    Tue    Wed    Thu    Fri    Sat" << endl;
	cout << setprecision(2) << fixed;
	for(int foo = 0; foo < r; foo++)
	{
		for(int bar = 0; bar < c; bar++)
		{
			cout << list[foo][bar] << "   ";
		}
		cout <<endl;
	}
	cout << "The average food eaten per day by all monkeys: " << avg << " pounds" <<endl;
	cout << "The least amount of food eaten by any monkey: " << min << " pounds" <<endl;
	cout << "The largest amount of food eaten per by any monkey: " << max << " pounds" <<endl;
}//end of out data function

//start of average function
float average(float list[r][c])
{
	//local variables
	float sum;
	for(int foo = 0; foo < r; foo++)
	{
		for(int bar = 1; bar < c; bar++)
		{
			sum += list[foo][bar];
		}
	}
	
	return sum/7;
}//end of average function

//start of minimum function
float minimum(float list[r][c])
{
	//local variable
	float min = list[0][1];
	
	for(int foo = 0;foo<r;foo++)
	{
		for(int bar = 1; bar<c;bar++)
		{
			if(list[foo][bar] < min)
			{
				min = list[foo][bar];
			}
		}
	}
	return min;	
}//end of minimum function

//start of maximum function
float maximum(float list[r][c])
{
	//local variable
	float max = list[0][1];
	
	for(int foo = 0;foo<r;foo++)
	{
		for(int bar = 1; bar<c;bar++)
		{
			if(list[foo][bar] >max)
			{
				max = list[foo][bar];
			}
		}
	}
	return max;	
}//end of maximum function

