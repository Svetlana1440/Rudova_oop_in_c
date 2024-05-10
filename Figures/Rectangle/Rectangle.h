#pragma once
#include "../figures.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

template <class T>
// Rectangle class
class Rectangle : public GeometricFigure {
private:
    T side1, side2;
public:
    Rectangle(T _side1, T _side2);

    double calc_area() override {}

    double calc_perimeter() override {}

    void name() override {}
};


template <class T>
// Rectangle class
class Rectangle : public GeometricFigure {
private:
    T side1, side2;
public:
    Rectangle(T _side1, T _side2) : side1(_side1), side2(_side2) {}

    double calc_area() override {
        return side1 * side2;
    }

    double calc_perimeter() override {
        return 2 * (side1 + side2);
    }

    void name() override {
        cout << "Rectangle" << endl;
    }
};

#endif