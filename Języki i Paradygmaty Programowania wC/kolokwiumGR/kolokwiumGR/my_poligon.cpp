#include "my_poligon.h"

using std::string;

MyPoligon::MyPoligon() : name(""), points(nullptr), numPoints(0) {}

MyPoligon::MyPoligon(string name, MyPoint* points, size_t numPoints)
    : name(name), points(points), numPoints(numPoints) {}

MyPoligon::~MyPoligon() {}

string MyPoligon::getName() const {
    return name;
}

MyPoint* MyPoligon::getPoints() const {
    return points;
}

size_t MyPoligon::getNumPoints() const {
    return numPoints;
}