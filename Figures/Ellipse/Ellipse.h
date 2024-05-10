#pragma once
#include "../figures.h"

#ifndef ELLIPSE_H
#define ELLIPSE_H

template <class T>
// Ellipse class
class Ellipse : public GeometricFigure {
private:
    Point center;
    T semi_major_axis;
    T semi_minor_axis;
public:
    Ellipse(Point _center, T _semi_major_axis, T _semi_minor_axis);

    double calc_area();

    double calc_perimeter();

    void name();
};


template <class T>
// Ellipse class
class Ellipse : public GeometricFigure {
private:
    Point center;
    T semi_major_axis;
    T semi_minor_axis;
public:
    Ellipse(Point _center, T _semi_major_axis, T _semi_minor_axis) : center(_center), semi_major_axis(_semi_major_axis), semi_minor_axis(_semi_minor_axis) {}

    double calc_area() override {
        return M_PI * semi_major_axis * semi_minor_axis;
    }

    double calc_perimeter() override {
        return 2 * M_PI * sqrt((semi_major_axis * semi_major_axis + semi_minor_axis * semi_minor_axis) / 2);
    }

    void name() override {
        cout << "Ellipse" << endl;
    }
};
#endif