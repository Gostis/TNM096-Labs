// Task3Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Scheduler.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Scheduler test;
	//string test2[2] = { "Hello", "MT101"};

	//char c = test2[1][2];
	char p;
	//cout << test.TotNumConflicts() << endl;
	//test.Solver();
	test.Print();
	cout << "Number of conflicts: "<< test.numConflicts << endl;
	
	cin >> p;
	
	return 0;
}

