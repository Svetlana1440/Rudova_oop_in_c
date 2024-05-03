#pragma once
#include <iostream>
#ifndef _DATETIME_H
#define _DATETIME_H



// Circle class
class Circle : public GeometricFigure {
private:
    Point center;
    T radius;
public:
    Circle(Point _center, T _radius) : center(_center), radius(_radius) {}

    T calc_area() override {
        return M_PI * radius * radius;
    }

    T calc_perimeter() override {
        return 2 * M_PI * radius;
    }

    void name() override {
        cout << "Circle" << endl;
    }
};