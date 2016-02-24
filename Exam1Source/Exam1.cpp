// Exam1.cpp
// Author: Erick Narvaez
// Classes/Procedures:
//	int main(): Main method; requests user input for shape dimensions and writes specifications to "comparisons.prn".


#include <iostream>
#include <fstream>
#include "SQUARE_H.h"
#include "CIRCLE_H.h"
#include "HEXAGON_H.h"

// Procedure:	main()
// Author:		Erick Narvaez
// Summary:		The main method is the entry point to the program. It requests the side length or diameter for the different types 
//				of pizzas and then uses this data to create an instance of each pizza. Each pizza class has a toString() method to 
//				output the required information about each pizza. The main method uses this to output each toString to the "comparison.prn" 
//				file and to the console. 
//Arguments:	(none)
int main()
{
	using namespace std;

	//Get square pizza side length from user
	cout << "Side length of square pizza (inches): ";
	double squareLength;
	cin >> squareLength;

	//Get circle pizza diameter from user
	cout << "Diameter of circle pizza (inches): ";
	double circleDiameter;
	cin >> circleDiameter;

	//Get hexagon side length from user
	cout << "Side length of hexagonal pizza (inches): ";
	double hexagonalLength;
	cin >> hexagonalLength;

	//Declare and initialize Square, Circle and Hexagon pizza classes using user input
	Square Square1 = Square(squareLength);
	Circle Circle1 = Circle(circleDiameter);
	Hexagon Hexagon1 = Hexagon(hexagonalLength);

	//Compare the areas of the whole between each of the 3 classes
	//TODO: Figure out how to compare whole sizes and slice sizes!!
	if (Square1.getArea() < Circle1.getArea()) {
		if (Square1.getArea() < Hexagon1.getArea()) {
			Square1.setWholeSize(SMALL);
			if (Hexagon1.getArea() < Circle1.getArea()) {
				Circle1.setWholeSize(LARGE);
			}
			else {
				Hexagon1.setWholeSize(LARGE);
			}
		}
		else {
			Hexagon1.setWholeSize(SMALL);
			Circle1.setWholeSize(LARGE);
		}
	}
	else {
		if (Circle1.getArea() < Hexagon1.getArea()) {
			Circle1.setWholeSize(SMALL);
			if (Hexagon1.getArea() < Square1.getArea()) {
				Square1.setWholeSize(LARGE);
			}
			else {
				Hexagon1.setWholeSize(LARGE);
			}
		}
		else {
			Hexagon1.setWholeSize(SMALL);
			Square1.setWholeSize(LARGE);
		}
	}

	//Compare the areas of the slices between each of the 3 classes

	if (Square1.getSliceArea() < Circle1.getSliceArea()) {
		if (Square1.getSliceArea() < Hexagon1.getSliceArea()) {
			Square1.setSliceSize(SMALL);
			if (Hexagon1.getSliceArea() < Circle1.getSliceArea()) {
				Circle1.setSliceSize(LARGE);
			}
			else {
				Hexagon1.setSliceSize(LARGE);
			}
		}
		else {
			Hexagon1.setSliceSize(SMALL);
			Circle1.setSliceSize(LARGE);
		}
	}
	else {
		if (Circle1.getSliceArea() < Hexagon1.getSliceArea()) {
			Circle1.setSliceSize(SMALL);
			if (Hexagon1.getSliceArea() < Square1.getSliceArea()) {
				Square1.setSliceSize(LARGE);
			}
			else {
				Hexagon1.setSliceSize(LARGE);
			}
		}
		else {
			Hexagon1.setSliceSize(SMALL);
			Square1.setSliceSize(LARGE);
		}
	}
	//Output toString methods of each object to the console
	cout << Square1.toString() << "\n" << Circle1.toString() << "\n" << Hexagon1.toString();

	//Declare output file stream object to open "comparisons.prn" for writing
	ofstream outf("comparisons.prn");

	//Check if file was successfully opened, if not print error message
	if (!outf) {
		cerr << "Could not open comparisons.prn for writing.";
		exit(1);
	}

	//Output each toString of each object to the file
	outf << Square1.toString() << endl;
	outf << Circle1.toString() << endl;
	outf << Hexagon1.toString() << endl;

    return 0;
}
