// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

void GoalCheck(int theArr[], int GoalArr[]);

void printBoard(int theArr[]);


int main()
{
	// open [] minsta elementet måste vara soterat men inte resten log n att sortera.
	// closed [] bara lägga till
	/*
	int testArr[] = {1,0,5,6,4,7,2,3,8};
	int goalArr[] = {1,2,3,4,5,6,7,8,0};

	int test;
	cout << "Hello world";
	cin >> test;
	*/
	int test;
	EightPuzzle thePuzzle;
	thePuzzle.PuzzleSolver();
	thePuzzle.print();
	
	cin >> test;
	return 0;
}

void GoalCheck(int theArr[], int GoalArr[])
{
	for (int i = 0; i < 8; i++)
	{
		if (theArr[i] == GoalArr[i])
		{
			if (i == 8)
			{
				cout << "Its the goal array" << endl;
			}
		}
		else
		{
			cout << "Not goal board" << endl;
			break;
		}
	}
}

void printBoard(int theArr[])
{
		
}

