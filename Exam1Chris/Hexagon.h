/****************************
* Author: Chris Rodriguez	*
* Net-ID: cxr132930			*
* CS 3376.001				*
* Exam 1					*
****************************/

using namespace std;
#include <string>

#ifndef Hexagon_h
#define Hexagon_h

/************************************************************************************************************
* Hexagon																									*
* This class contains variables and methods needed to compute the areas of a hexagonal pizza and its slice	*
* No arguments																								*
************************************************************************************************************/
class Hexagon
{
private:
	int baseLength, whole, slice; // whole and slice will contain the ranks of the whole pizza and its slice
	double wholeArea, sliceArea; // will store areas

public:
	Hexagon();
	void setBase(int base);
	double computeWholeArea();
	double computeSliceArea();
	void setRank(int w, int s);
	string getInfo();
	string getRank(int rank);
};

#endif

