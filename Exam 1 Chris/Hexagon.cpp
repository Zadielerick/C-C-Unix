/****************************
* Author: Chris Rodriguez	*
* Net-ID: cxr132930			*
* CS 3376.001				*
* Exam 1					*
****************************/
// Square: the constructor for the Square class
// setLength: tell the class what the user input was
// computeWholeArea: use the measurement to compute the area of the pizza
// computeSliceArea: use the whole area to compute the slice area
// setRank: tell the class what the ranks of the areas are
// getInfo: nicely format the info of the pizza and return
// getRank: decode the rank of the area

#include "Hexagon.h"

// Before we get to our class, let's define ourselves some nifty little constants
double sqrtthree = 1.73205080757; // the most significant digits google gave for 3^(1/2)
double areaConstant = 3 * sqrtthree / 2; // looks wierd but these are all the constants in the formula for area of a hexagon

/****************************************************************
* Hexagon (constructor)											*
* Creates Hexagon object										*
* No arguments													*
****************************************************************/
Hexagon::Hexagon()
{
	
}

/****************************************************************
* setBase														*
* initializes the baseLength									*
* Arguments:	base, I/P, int									*
*				Is the length that the user input in main.cpp	*
****************************************************************/
void Hexagon::setBase(int base)
{
	baseLength = base;
}


/************************************************************************************
* computeWholeArea																	*
* Uses the base length to compute the whole area of the pizza and returns this area	*
* No arguments																		*
************************************************************************************/
double Hexagon::computeWholeArea()
{
	// Let's compute the area! (3 * 3^(1/2) * a^2 / 2)
	wholeArea = areaConstant * baseLength * baseLength; // areaConstant defined in Hexagon.h
	
	// and return the area!
	return wholeArea;
}


/****************************************************************************
* computeSliceArea															*
* Uses the whole area to compute the area of a slice and returns this area	*
* No arguments																*
****************************************************************************/
double Hexagon::computeSliceArea()
{
	// Divide the are by number of slices!
	sliceArea = wholeArea / 6;

	// and return it!
	return sliceArea;
}

/********************************************************
* setRank												*
* Used to set the rank of the whole area and slice area	*
* Arguments:	w, I/P, int								*
*				will be the rank of the whole area		*
*														*
*				s, I/P, int								*
*				will be the rank of the slice area		*
********************************************************/
void Hexagon::setRank(int w, int s)
{
	// As simple as passing values along
	whole = w;
	slice = s;
}

/********************************************************
* getInfo()												*
* Returns all the info of the pizza in a nice format	*
* No arguments											*
********************************************************/
string Hexagon::getInfo()
{
	// Let's write all the info of the pizza in a nice format
	// But these doubles and ints will get us in trouble

	// We start writing things in a nice format
	string start = "\nHexagon";

	// And now we handle the first double
	string wa = "\nArea of pizza: " + to_string(wholeArea) + " square in.";

	// For the ints, we need to get the rank in a string
	// So we use a helper method to do that for us
	string wr = "\nSize of pizza: " + getRank(whole);

	// We continue in the same fashion for the slice info
	string sa = "\nArea of slice: " + to_string(sliceArea) + " square in.";
	string sr = "\nSize of slice: " + getRank(slice);

	// Put it all together and return it
	string info = start + wa + wr + sa + sr;
	return info;
}

/************************************
* getRank							*
* Returns the rank in string format	*
* Arguments:	rank, I/P, int		*
*				the rank of an area	*
************************************/
string Hexagon::getRank(int rank)
{
	// Decode the rank from the value
	if (rank == 0)
		return "SMALL";
	else if (rank == 1)
		return "MEDIUM";
	else
		return "LARGE";
}