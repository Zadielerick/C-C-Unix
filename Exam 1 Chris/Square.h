/****************************
* Author: Chris Rodriguez	*
* Net-ID: cxr132930			*
* CS 3376.001				*
* Exam 1					*
****************************/

using namespace std;
#include <string>

#ifndef Square_h
#define Square_h

/********************************************************************************************************
* Square																								*
* This class contains variables and methods needed to compute the areas of a square pizza and its slice	*
* No arguments																							*
********************************************************************************************************/
class Square
{
private:
	int sideLength, whole, slice; // whole and slice will contain the ranks of the whole pizza and its slice
	double wholeArea, sliceArea; // will store areas

public:
	Square();
	void setLength(int length);
	double computeWholeArea();
	double computeSliceArea();
	void setRank(int w, int s);
	string getInfo();
	string getRank(int rank);
};

#endif
