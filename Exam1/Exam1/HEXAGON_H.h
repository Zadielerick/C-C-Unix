//HEXAGON_H
// Author: Erick Narvaez
// Classes/Procedure: Hexagon Class

#ifndef HEXAGON_H
#define HEXAGON_H
#include "SIZE_H.h"

// Class:		Hexagon
// Author:		Erick Narvaez
// Summary:		The hexagon class represents the hexagon pizza. It takes in the side length provided by the user and calculates its area, slice area
//				and determines whether these sizes fall under a small, medium or large category. It also has a toString method to output these values 
//				in a formated string.
class Hexagon {
private:
	Size whole;
	Size slice;
	double sideLength;
	double area;
	double sliceArea;

public:
	Hexagon(double sideLength);
	void calcArea();
	void setWholeSize();
	void calcSliceArea();
	void setSliceSize();
	std::string toString();
	std::string size_Name(int size);
};

#endif