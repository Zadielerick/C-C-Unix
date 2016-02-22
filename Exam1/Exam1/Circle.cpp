//Circle.cpp
// Author: Erick Narvaez
// Class/Procedures:
//	1) Circle(): Constructor for Circle class. Accepts a diameter length and calculates the rest of the properties
//	2) calcArea(): Will calculate the area using the sideLength property and sets the area property of the object
//	3) setWholeSize(): Will set the enum whole size property using the area property
//	4) setSliceSize(): Will set the enum slice size property using the slice area property
//	5) calcSliceArea(): Takes the whole area and calculates the slice area
//	6) toString(): Returns the properties of Square in a formatted string
//	7) size_Name(): Converts Size enum to string name
#include "stdafx.h"
#include "CIRCLE_H.h"
#include <iostream>
#include <math.h>

// Name:		Circle()
// Author:		Erick Narvaez
// Summary:		Contructor for the Circle class. Sets the value of the following properties for the
//				object: diameter, area, slice area, and size enums.
// Arguments:	
//				1) double length (input). The diameter length of the circle object.
Circle::Circle(double length) {
	diameter = length;
	calcArea();
	calcSliceArea();
	setWholeSize();
	setSliceSize();
}

// Name:		calcArea()
// Author:		Erick Narvaez
// Summary:		Calculates the area of the circle by multiplying pi by the radius squared. (A=pi*r^2)
// Arguments:	(none)
void Circle::calcArea() {
	double pi = 3.1415926535897;
	area = pow(diameter/2,2)*pi;
}

// Name:		setWholeSize()
// Author:		Erick Narvaez
// Summary:		Determines what size the pizza falls under. Assumes that a small pizza has an area less than 36 inches^2, 
//				a medium has between 36 and 144, and a large has 144 or more.
// Arguments:	(none)
void Circle::setWholeSize() {
	if (area <= 36)
		whole = SMALL;
	else if (area >= 144)
		whole = LARGE;
	else
		whole = MEDIUM;
}

// Name:		setSliceSize()
// Author:		Erick Narvaez
// Summary:		Determines what size the slice of the pizza falls under. Assumes that a small slice of pizza has an area less than 4 inches^2, 
//				a medium has between 4 and 16, and a large has 16 or more.
// Arguments:	(none)
void Circle::setSliceSize() {
	if (sliceArea <= 4)
		slice = SMALL;
	else if (sliceArea >= 16)
		slice = LARGE;
	else
		slice = MEDIUM;
}


// Name:		calcSliceArea()
// Author:		Erick Narvaez
// Summary:		Calculates the area of a slice of pizza using the area property of the object.
// Arguments:	(none)
void Circle::calcSliceArea() {
	sliceArea = area / 8;
}

// Name:		toString()
// Author:		Erick Narvaez
// Summary:		Takes all properties of the object and outputs them with identifying strings for the output file in the main function.
// Arguments:	(none)
std::string Circle::toString() {
	std::string str = "";
	str += "Type of Pizza: Circle\n";
	str += "Area of Whole Pizza: " + std::to_string(area) + "\n";
	str += "Whole Area Rank: " + size_Name(whole) + "\n";
	str += "Area of Slice: " + std::to_string(sliceArea) + "\n";
	str += "Slice Area Rank: " + size_Name(slice) + "\n";
	//std::cout << str;
	return str;
}

// Name:		size_Name()
// Author:		Erick Narvaez
// Summary:		Determines and returns what the String name for the Size enum value is. 
// Arguments:	(none)
std::string Circle::size_Name(int size) {
	switch (size) {
	case(0) : return "Small";
	case(1) : return "Medium";
	case(2) : return "Large";
	default: return "not a size";
	}
}