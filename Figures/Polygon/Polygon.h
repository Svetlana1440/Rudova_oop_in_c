#pragma once
#include "../figures.h"
#include <vector>
#include <string>
#include <fstream>
#ifndef POLYGON_H
#define POLYGON_H


template <class T>
// Polygon class
class Polygon : public GeometricFigure {
private:
    vector<Point> vertices;
public:
    Polygon(vector<Point> _vertices) : vertices(_vertices) {}

    double calc_area() override {
        T area = 0;
        int n = vertices.size();
        for (int i = 0; i < n; ++i) {
            area += (vertices[i].x * vertices[(i + 1) % n].y - vertices[(i + 1) % n].x * vertices[i].y);
        }
        return fabs(area) / 2;
    }

    double calc_perimeter() override {
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
    double distance(Point p1, Point p2) {
        return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    }
};

#endif