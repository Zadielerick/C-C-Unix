/****************************
* Author: Chris Rodriguez	*
* Net-ID: cxr132930			*
* CS 3376.001				*
* Exam 1					*
****************************/
// Classes/Procedures
// main: driver method for the program
// requestMeasurements: the program requests the measurements from the user
// computeAreas: compute the whole and slice areas for the pizzas and pass them to the ranking method
// rankAreas: rank the areas the program calculated
// swap: swap the values of the two arguments
// outputInfo: send the info to an output file

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include "Square.h"
#include "Circle.h"
#include "Hexagon.h"

// Before getting to any methods, let's declare some objects so that all the methods here have access to them
Square square;
Circle circle;
Hexagon hexagon;

/********************************************************************************
* main																			*
* Calls helper methods which interact with the user, classes, and output file	*
* No arguments																	*
********************************************************************************/
int main()
{
	requestMeasurements();
	computeAreas();
	outputInfo();
	return 0;
}

/********************************************************************************
* requestMeasurements															*
* Interacts with the user to get the three measurements needed for calculations	*
* No Arguments																	*
********************************************************************************/
void requestMeasurements()
{
	// These ints will be passed to the class objects
	int rect, circ, hex;

	// Explain what's going on to the user
	cout << "Hi, there! I'm the pizza calculator. Just give me some measurements and I'll work some magic." << endl;
	cout << "Make sure each measurement is a positive integer or I'll complain!" << endl;
	
	// Let's get the side length of a square
	cout << "Side length of the square pizza: ";
	cin >> rect;
	// Error handling
	while (cin.fail() || rect <= 0)
	{
		cout << "Oops, that's not a positive int!" << endl;
		// The next two lines are needed for non-int cases
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Side length of the square pizza: ";
		cin >> rect;
	}

	// Let's get the diameter of a circle
	cout << "Diameter of the circular pizza: ";
	cin >> circ;
	// Error handling
	while (cin.fail() || circ <= 0)
	{
		cout << "Oops, that's not a positive int!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Diameter of the circular pizza: ";
		cin >> circ;
	}

	// Let's get the side length of a hexagonal pizza
	cout << "Side length of the hexagonal pizza: ";
	cin >> hex;
	// Error handling
	while (cin.fail() || hex <= 0)
	{
		cout << "Oops, that's not a positive int!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Side length of the hexagonal pizza: ";
		cin >> hex;
	}
	
	// Now let's pass these measurements to the objects, yeah?
	square.setLength(rect);
	circle.setDiam(circ);
	hexagon.setBase(hex);
}

/************************************************************************************************
* computeAreas																					*
* computes the whole areas and slice areas of the pizzas and passes them to the ranking methods	*
* No arguments																					*
************************************************************************************************/
void computeAreas()
{
	// Let's save the whole areas as we compute them
	double s = square.computeWholeArea();
	double c = circle.computeWholeArea();
	double h = hexagon.computeWholeArea();

	// Let's save the slice areas as we compute them
	double ss = square.computeSliceArea();
	double cc = circle.computeSliceArea();
	double hh = hexagon.computeSliceArea();

	// Now we pass the values to the ranking method
	rankAreas(s, c, h, ss, cc, hh);
}

/********************************************************************
* rankAreas															*
* Ranks the areas of the pizzas and tells each object their ranks	*
* Arguments:	s, I/P, double				ss, I/P, double			*
*				whole area of square		slice area of square	*
*																	*
*				c, I/P, double				cc, I/P, double			*
*				whole area of circle		slice area of circle	*
*																	*
*				h, I/P, double				hh, I/P, double			*
*				whole area of hexagon		slice area of hexagon	*
********************************************************************/
void rankAreas(double s, double c, double h, double ss, double cc, double hh)
{
	// Arrays for storing rank
	double values[3] = { s, c, h }; // For sorting
	int wholes[3]; // stores whole rankings( 0 = square, 1 = circle, 2 = hexagon)
	int slices[3]; // stores slice rankings( 0 = square, 1 = circle, 2 = hexagon)

	// Now we sort the values
	if (values[0] > values[1])
		swap(values[0], values[1]);
	if (values[0] > values[2])
		swap(values[0], values[2]);
	if (values[1] > values[2])
		swap(values[1], values[2]);

	// values is now sorted in ascending order (containing whole areas)
	// Let's assign rankings now
	// Square first
	if (s == values[0])
		wholes[0] = SMALL;
	else if (s == values[1])
		wholes[0] = MEDIUM;
	else
		wholes[0] = LARGE;

	// And circle
	if (c == values[0])
		wholes[1] = SMALL;
	else if (c == values[1])
		wholes[1] = MEDIUM;
	else
		wholes[1] = LARGE;

	// Finally hexagon
	if (h == values[0])
		wholes[2] = SMALL;
	else if (h == values[1])
		wholes[2] = MEDIUM;
	else
		wholes[2] = LARGE;

	// That was alot of stuff!
	// Now we do it all over for the slice rankings
	values[0] = ss;
	values[1] = cc;
	values[2] = hh;
	
	// Now we sort the values
	if (values[0] > values[1])
		swap(values[0], values[1]);
	if (values[0] > values[2])
		swap(values[0], values[2]);
	if (values[1] > values[2])
		swap(values[1], values[2]);

	// values is now sorted in ascending order (containing whole areas)
	// Let's assign rankings now
	// Square first
	if (ss == values[0])
		slices[0] = SMALL;
	else if (ss == values[1])
		slices[0] = MEDIUM;
	else
		slices[0] = LARGE;

	// And circle
	if (cc == values[0])
		slices[1] = SMALL;
	else if (cc == values[1])
		slices[1] = MEDIUM;
	else
		slices[1] = LARGE;

	// Finally hexagon
	if (hh == values[0])
		slices [2] = SMALL;
	else if (hh == values[1])
		slices[2] = MEDIUM;
	else
		slices[2] = LARGE;

	// Phew! Now we can tell the objects their rankings
	square.setRank(wholes[0], slices[0]);
	circle.setRank(wholes[1], slices[1]);
	hexagon.setRank(wholes[2], slices[2]);
}


/****************************************************************
* swap															*
* Swaps the values of a and b									*
* Arguments:	a, I/O, double				b, I/O, dpuble		*
*				will have value of b	will have value of a	*
****************************************************************/
void swap(double a, double b)
{
	double temp = a; // temporarily stores the value of a
	a = b;
	b = temp;
}

/********************************************************
* outputInfo											*
* Sends the output for the program to comparisons.prn	*
* No arguments											*
********************************************************/
void outputInfo()
{
	// Let's get the info for each pizza
	string s = "\n" + square.getInfo();
	string c = "\n" + circle.getInfo();
	string h = "\n" + hexagon.getInfo();

	// Now we open the file and dump the contents
	ofstream file;
	file.open("comparisons.prn");
	file << s + c + h;

	// Finally, we close the file stream
	file.close();
}