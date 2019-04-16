// Task3Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Scheduler.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Task 3
	Scheduler schedule;
	
	cout << "Initial Schedule with: " << schedule.numConflicts << " conflicts."<< endl;
	schedule.Print();
	schedule.Solver();
	schedule.Print();
	cout << "\nNumber of conflicts: "<< schedule.numConflicts << endl;
	char p;
	cin >> p;
	
	return 0;
}

