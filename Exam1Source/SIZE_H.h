//SIZE_H.h
//Author:	Erick Narvaez
//Classes/Procedures:	(none)

#ifndef SIZE_H
#define SIZE_H

//Included here because each file using this enum will need to output the string value, not the integer, in its toString method
#include <string>

//Size will be used to compare different pizza classes using a standard size
enum Size {
	SMALL = 0,
	MEDIUM,
	LARGE
};

#endif