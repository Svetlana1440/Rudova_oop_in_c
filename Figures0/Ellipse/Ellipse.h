#pragma once
#include <iostream>
#ifndef _DATETIME_H
#define _DATETIME_H


// Ellipse class
class Ellipse : public GeometricFigure {
private:
    Point center;
    T semi_major_axis;
    T semi_minor_axis;
public:
    Ellipse(Point _center, T _semi_major_axis, T _semi_minor_axis) : center(_center), semi_major_axis(_semi_major_axis), semi_minor_axis(_semi_minor_axis) {}

    T calc_area() override {
        return M_PI * semi_major_axis * semi_minor_axis;
    }

    T calc_perimeter() override {
        return 2 * M_PI * sqrt((semi_major_axis * semi_major_axis + semi_minor_axis * semi_minor_axis) / 2);
    }

    void name() override {
        cout << "Ellipse" << endl;
    }
};