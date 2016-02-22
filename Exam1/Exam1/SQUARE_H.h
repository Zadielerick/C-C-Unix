//SQUARE_H
// Author: Erick Narvaez
// Classes/Procedure: Square Class

#ifndef SQUARE_H
#define SQUARE_H
#include "SIZE_H.h"

// Class:		Square
// Author:		Erick Narvaez
// Summary:		The square class represents the square pizza. It takes in the side length provided by the user and calculates its area, slice area
//				and determines whether these sizes fall under a small, medium or large category. It also has a toString method to output these values 
//				in a formated string.
class Square {
private:
	Size whole;
	Size slice;
	double sideLength;
	double area;
	double sliceArea;

public:
	Square(double length);
	void calcArea();
	void setWholeSize();
	void calcSliceArea();
	void setSliceSize();
	std::string toString();
	std::string size_Name(int size);
};

#endif
