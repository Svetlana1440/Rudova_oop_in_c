#pragma once
#include <iostream>
#include "../figures.h"
#ifndef CIRCLE_H
#define  CIRCLE_H


template <class T>
// Circle class
class Circle : public GeometricFigure {
private:
    Point center;
    T radius;
public:
    Circle(Point _center, T _radius) : center(_center), radius(_radius) {}

    double calc_area() override {
        return M_PI * radius * radius;
    }

    double calc_perimeter() override {
        return 2 * M_PI * radius;
    }

    void name() override {
        cout << "Circle" << endl;
    }
};



#endif