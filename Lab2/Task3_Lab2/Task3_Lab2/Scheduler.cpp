#include "stdafx.h"
#include "Scheduler.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>


Scheduler::Scheduler()
{
	//Makes the algorithm shuffle the schedule different each time the program is run.
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	auto rng = std::default_random_engine{ seed };

	shuffle(&schedule[0], &schedule[24], rng);
	numConflicts = TotNumConflicts();
};

void Scheduler::Swap(int p1, int p2) 
{
	string temp = schedule[p1];
	schedule[p1] = schedule[p2];
	schedule[p2] = temp;
	//cout << "Swapping: " << schedule[p1] << "\t"<< schedule[p2] << endl;

}

Scheduler::Scheduler(string Initschedule[])
{
	for (int i = 0; i < scheduleSize; i++)
	{
		schedule[i] = Initschedule[i];
	}

	numConflicts = TotNumConflicts();
};

bool Scheduler::isConflict(int p1, int p2) {
	if (p1 == 5 || p2 == 5)
	{
		return false;
	}

	if (p1 == p2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Calculating tot number of conflicts. Loops through every hour.
int Scheduler::TotNumConflicts()
{
	
	int totConflicts = 0;
	int room_lec[3];

	for (int i = 0; i < scheduleSize; i +=3)
	{
		room_lec[0] = schedule[i][2] - 48;
		room_lec[1] = schedule[i+1][2] - 48;
		room_lec[2] = schedule[i+2][2] - 48;

		if (isConflict(room_lec[0], room_lec[1]))
			totConflicts++;
		if (isConflict(room_lec[0], room_lec[2]))
			totConflicts++;
		if (isConflict(room_lec[1], room_lec[2])) 
			totConflicts++;
	}
	return totConflicts;
};


int Scheduler::findConflicts(string compareLec, int idx)
{
	
	int courseDigit = compareLec[0] - 48;

	//Which room the current index is located in
	int timeToCheck = idx % 3;
	
	int conflictsRow = 0;

	int tempRoom1 = 0;
	int tempRoom2 = 0;
	

	//Different rooms to check conflict with depending on where idx is loacted.
	switch (timeToCheck)
	{
	case 0:
		tempRoom1 = schedule[idx + 1][2] - 48;
		tempRoom2 = schedule[idx + 2][2] - 48;
		break;
	case 1:
		tempRoom1 = schedule[idx - 1][2] - 48;
		tempRoom2 = schedule[idx + 1][2] - 48;
		break;
	case 2:
		tempRoom1 = schedule[idx - 2][2] - 48;
		tempRoom2 = schedule[idx - 1][2] - 48;
		break;
	default:
		break;
	}

	//Check which rooms are in conflict withe our current course
	if (isConflict(tempRoom1, courseDigit))
		conflictsRow++;
	if (isConflict(tempRoom2, courseDigit))
		conflictsRow++;

	return conflictsRow;
}

int Scheduler::findMinConflictsIdx(int idx) {
	
	//Setting the current course digit(had to compare between strings because otherwise the empty lectures would had been wrongly interpreted) 
	string compLec = schedule[idx];
	string courseDigits(1, compLec[2]);

	//High number to start with to get a initial value that is lower.
	int minIdx = idx;
	int minConflicts = 100;
	
	//Check if the current lecture is empty.
	if (schedule[idx] == "     ")
	{
		return idx;
	}

	for (int i = 0; i < scheduleSize; i++)
	{
		//Calculating the conflict that would happend if courseDigits was moved to i.
		int conf = findConflicts(courseDigits, i);
	
		if (conf < minConflicts)
		{
			//String to check if the current slot have the same course digit as the moved one
			string compare(1, schedule[i][2]);
			
			//Change to the lowest amount of conflicts if they differ the course digit
			if (courseDigits != compare)
			{
				minConflicts = conf;
				minIdx = i;
			}

		}
	}

	return minIdx;
	
}

void Scheduler::Solver() {

	int totConf = TotNumConflicts();
	int maxSteps = 10000, stepCounter = 0;

	int randIdx = 0, minTempIdx = 0;
	
	//Min conflict algo
	while (totConf > 0 && stepCounter < maxSteps)
	{
		stepCounter++;
		//Setting a random lecture.
		randIdx = rand() % scheduleSize;
		//Find the minimum conflicts index 
		minTempIdx = findMinConflictsIdx(randIdx);
		//Swapping the position.
		Swap(randIdx, minTempIdx);
		//Calculating the total amount of conflicts.
		totConf = TotNumConflicts();
		
	}
	numConflicts = totConf;

	cout << endl <<"Number of steps: "<< stepCounter << endl << endl;

}

void Scheduler::Print() {
	cout << "TP51\tSP34 \t K3" << endl;
	cout << "----\t----\t----\t" << endl;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 3; col++) 
		{
			if (schedule[row * 3 + col] == "88888" || schedule[row * 3 + col] == "77777")
			{
				cout << "     \t";
			}
			else
			{
				cout << schedule[row * 3 + col] << "\t";
			}
		}
		cout << endl;
	}
}

