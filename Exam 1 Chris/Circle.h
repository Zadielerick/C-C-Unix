/****************************
* Author: Chris Rodriguez	*
* Net-ID: cxr132930			*
* CS 3376.001				*
* Exam 1					*
****************************/

using namespace std;
#include <string>

#ifndef Circle_h
#define Circle_h

/********************************************************************************************************
* Circle																								*
* This class contains variables and methods needed to compute the areas of a circle pizza and its slice	*
* No arguments																							*
********************************************************************************************************/
class Circle
{
private:
	int diameter, whole, slice; // whole and slice will contain the ranks of the whole pizza and its slice
	double wholeArea, sliceArea; // will store areas

public:
	Circle();
	void setDiam(int diam);
	double computeWholeArea();
	double computeSliceArea();
	void setRank(int w, int s);
	string getInfo();
	string getRank(int rank);
};

#endif

