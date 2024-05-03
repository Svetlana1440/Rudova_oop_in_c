#pragma once
#include <iostream>
#ifndef _DATETIME_H
#define _DATETIME_H


// Triangle class
class Triangle : public GeometricFigure {
private:
    Point vertex1, vertex2, vertex3;
public:
    Triangle(Point _vertex1, Point _vertex2, Point _vertex3) : vertex1(_vertex1), vertex2(_vertex2), vertex3(_vertex3) {}

    T calc_area() override {
        T a = distance(vertex1, vertex2);
        T b = distance(vertex2, vertex3);
        T c = distance(vertex3, vertex1);
        T s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    T calc_perimeter() override {
        return distance(vertex1, vertex2) + distance(vertex2, vertex3) + distance(vertex3, vertex1);
    }

    void name() override {
        cout << "Triangle" << endl;
    }

private:
    T distance(Point p1, Point p2) {
        return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    }
};