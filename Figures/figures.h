#pragma once
#include <iostream>
#ifndef _FIGURES_H
#define FIGURES_H

using namespace std;
const double pi = 3.1415926535;


// Point class
class Point {
public:
    double x, y;
    Point(double _x, double _y);
    Point();
};


// Abstract class for geometric figure
class GeometricFigure {
public:
    virtual double calc_area() = 0;
    virtual double calc_perimeter() = 0;
    virtual void name() = 0;
};

//calcDistance
double calcDistance(const Point& pa, const Point& pb);
#endif