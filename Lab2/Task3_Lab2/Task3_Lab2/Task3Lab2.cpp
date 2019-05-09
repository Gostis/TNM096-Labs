// Task3Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Scheduler.h"
#include <iostream>
#include <string>
#include <vector>

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
	cout << "Schedule score: " << schedule.score << endl;
	

	//Task 4
	/*
	vector<Scheduler> scheduleVec;

	int bestIdx = 0;
	int bestScore = 0;
	int counter = 0;

	while (counter < 500)
	{

		Scheduler tempSchedule;
		tempSchedule.Solver();

		cout << counter << endl;

		if (tempSchedule.numConflicts != 0)
		{
			continue;
		}

		if (tempSchedule.score > bestScore)
		{
			bestIdx = counter;
			bestScore = tempSchedule.score;
		}

		scheduleVec.push_back(tempSchedule);
		counter++;

		if (tempSchedule.score == 4)
		{
			cout << "Optimal score found..." << endl;
			break;
		}
	}
	
	cout << "The best score that was found was: " << bestScore << endl;
	cout << "This was the schedule with the best score: " << endl;
	Scheduler bestSchedule = scheduleVec.at(bestIdx);
	bestSchedule.Print();
	*/
	return 0;
}

