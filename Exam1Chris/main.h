#ifndef main_h
#define main_h

enum size { SMALL, MEDIUM, LARGE}; // Enumerated type for ranking each pizza area and slice area

void requestMeasurements();

void rankAreas(double s, double c, double h, double ss, double cc, double hh);

void outputInfo();

void computeAreas();

void swap(double a, double b);

#endif