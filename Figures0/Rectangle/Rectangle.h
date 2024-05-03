#pragma once
#include <iostream>
#ifndef _DATETIME_H
#define _DATETIME_H




// Rectangle class
class Rectangle : public GeometricFigure {
private:
    T side1, side2;
public:
    Rectangle(T _side1, T _side2) : side1(_side1), side2(_side2) {}

    T calc_area() override {
        return side1 * side2;
    }

    T calc_perimeter() override {
        return 2 * (side1 + side2);
    }

    void name() override {
        cout << "Rectangle" << endl;
    }
};