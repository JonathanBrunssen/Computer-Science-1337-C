//******************************************************************
// Project 7
// Programmer: Jonathan Brunssen
// Completed : November, 2019
// Status    : Complete
/*
Description: 

*/
//******************************************************************

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//structs
struct Student
{
	string Name;
	int Test1;
	int Test2;
	int Test3;
};

//funtion preprocesser
void getStudentData(Student [], int);
void sortStudents(Student [],int);
int outData(Student[], int, int);

//start of main
int main()
{
	// Variable Decleration
	int classsize;
	
	//get the class size and create the list of students
	cout << "Enter the number of students in the class: ";
	cin >> classsize;
	Student students[classsize];
	
	getStudentData(students,classsize);
	
	sortStudents(students,classsize);
	
	return 0;
}//end of main

void getStudentData(Student arr[],int arraysize)
{
	for(int i = 0; i < arraysize; i++)
	{
		do
		{
			cout << "Enter student " << i+1 << "'s name: ";
			cin.ignore();
			getline(cin, arr[i].Name);	
		}while(arr[i].Name.length() > 30);
		
		do
		{
			cout << "Enter " << arr[i].Name << "'s Test 1 grade: ";
			cin >> arr[i].Test1;
		}while(arr[i].Test1 > 105 || arr[i].Test1 < 0);
		
		do
		{
			cout << "Enter " << arr[i].Name << "'s Test 2 grade: ";
			cin >> arr[i].Test2;
		}while(arr[i].Test2 > 105 || arr[i].Test2 < 0);
		
		do
		{
			cout << "Enter " << arr[i].Name << "'s Test 3 grade: ";
			cin >> arr[i].Test3;
		}while(arr[i].Test3 > 105 || arr[i].Test3 < 0);
	}
	
}


void sortStudents(Student arr[],int arrsize)
{
	bool sorting;
	int sorted;
	int totalavg = 0;
	for(int i = 0; i < 3; i++)
	{
		sorting = true;
		while(sorting)
		{
			sorted = 1;
			for(int j = 0; j < arrsize; j++)
			{
				//sort test 1
				if(i == 0)
				{
					if(arr[j].Test1 > arr[j+1].Test1)
					{
						sorted = 0;
						Student temp = arr[j+1];
						arr[j+1] = arr[j];
						arr[j] = temp;
					}
					else
					{
						sorted = 1;
					}
				}
				//sort test 2
				if(i == 1)
				{
					if(arr[j].Test2 > arr[j+1].Test2)
					{
						sorted = 0;
						Student temp = arr[j+1];
						arr[j+1] = arr[j];
						arr[j] = temp;
					}
					else
					{
						sorted = 1;
					}
				}
				//sort test 3
				if(i == 2)
				{
					if(arr[j].Test3 > arr[j+1].Test3)
					{
						sorted = 0;
						Student temp = arr[j+1];
						arr[j+1] = arr[j];
						arr[j] = temp;
					}
					else
					{
						sorted = 1;
					}
				}
			}
			if(sorted == 1)
			{
				sorting = false;
			}
		}
		//print test results
		totalavg += outData(arr,arrsize,i);
	}
	ofstream outdata;
	outdata.open("outdata.txt", ios_base::app);
	outdata << endl << "Total test average: " << totalavg/3;
	outdata.close();
}

int outData(Student arr[], int arrsize,int testnum)
{
	ofstream outdata;
	int totalscore,test1avg,test2avg,test3avg = 0;
	outdata.open("outdata.txt", ios_base::app);	
	outdata << "Test " << testnum+1 << " Results" <<endl;
	cout << "printing test " << testnum+1 << endl;
	for(int i =0; i < arrsize; i++)
	{		
		if(testnum == 0)
		{ 
			totalscore += arr[i].Test1;
			outdata << arr[i].Name << " Test " << testnum+1 << " score: " << arr[i].Test1 << endl;
		} 
		if(testnum ==1)
		{
			totalscore += arr[i].Test2;
			outdata << arr[i].Name << " Test " << testnum+1 << " score: " << arr[i].Test2 << endl;
		} 
		if(testnum == 2)
		{
			totalscore += arr[i].Test3;
			outdata << arr[i].Name << " Test " << testnum+1 << " score: " << arr[i].Test3 << endl;
		}
	}
	
	if(testnum == 0)
	{ 
		test1avg = totalscore/arrsize;
		outdata << "Test 1 average: " << test1avg << endl << endl;
		outdata.close();
		return test1avg;
	} 
	else if(testnum ==1)
	{
		test2avg = totalscore/arrsize;
		outdata << "Test 2 average: " << test2avg << endl << endl;
		outdata.close();
		return test2avg;
	} 
	else if(testnum == 2)
	{
		test3avg = totalscore/arrsize;
		outdata << "Test 3 average: " << test3avg << endl << endl;
		outdata.close();
		return test3avg;
	}
}


