#pragma once
#include <iostream>
#ifndef _DATETIME_H
#define _DATETIME_H



// Polygon class
class Polygon : public GeometricFigure {
private:
    vector<Point> vertices;
public:
    Polygon(vector<Point> _vertices) : vertices(_vertices) {}

    T calc_area() override {
        T area = 0;
        int n = vertices.size();
        for (int i = 0; i < n; ++i) {
            area += (vertices[i].x * vertices[(i + 1) % n].y - vertices[(i + 1) % n].x * vertices[i].y);
        }
        return fabs(area) / 2;
    }

    T calc_perimeter() override {
        T perimeter = 0;
        int n = vertices.size();
        for (int i = 0; i < n; ++i) {
            perimeter += distance(vertices[i], vertices[(i + 1) % n]);
        }
        return perimeter;
    }

    void name() override {
        cout << "Polygon" << endl;
    }

private:
    T distance(Point p1, Point p2) {
        return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    }
};