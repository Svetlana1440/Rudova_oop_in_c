#include<iostream>
#include"figures.h"

using namespace std; 

int main() {
    // Example
    Point center(0, 0);
    Circle circle(center, 5);
    circle.name();
    std::cout << "Area: " << circle.calc_area() << std::endl;
    std::cout << "Perimeter: " << circle.calc_perimeter() << std::endl;

    return 0;