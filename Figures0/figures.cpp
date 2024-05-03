#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// Abstract class for geometric figure
class GeometricFigure {
public:
    virtual T calc_area() = 0;
    virtual T calc_perimeter() = 0;
    virtual void name() = 0;
};

// Point class
template< class T>
class Point {
public:
    T x, y;
    Point(T _x, T _y),(x=_x, y=_y) {}
};







