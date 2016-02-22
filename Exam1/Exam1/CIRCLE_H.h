//CIRCLE_H
// Author: Erick Narvaez
// Classes/Procedure: Circle Class

#ifndef CIRCLE_H
#define CIRCLE_H
#include "SIZE_H.h"

// Class:		Circle
// Author:		Erick Narvaez
// Summary:		The circle class represents the circle pizza. It takes in the diameter provided by the user and calculates its area, slice area
//				and determines whether these sizes fall under a small, medium or large category. It also has a toString method to output these values 
//				in a formated string.
class Circle {
private:
	Size whole;
	Size slice;
	double diameter;
	double area;
	double sliceArea;

public:
	Circle(double sideLength);
	void calcArea();
	void setWholeSize();
	void calcSliceArea();
	void setSliceSize();
	std::string toString();
	std::string size_Name(int size);
};

#endif