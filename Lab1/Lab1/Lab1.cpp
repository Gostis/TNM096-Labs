// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <iostream>


using namespace std;


int main()
{
	// open [] minsta elementet m�ste vara soterat men inte resten log n att sortera.
	// closed [] bara l�gga till
	int test;
	EightPuzzle thePuzzle;
	thePuzzle.PuzzleSolver();
	thePuzzle.print();
	
	cin >> test;
	return 0;
}

