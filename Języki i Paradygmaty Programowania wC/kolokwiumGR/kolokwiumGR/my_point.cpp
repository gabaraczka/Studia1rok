#include "my_point.h"

using std::string;

MyPoint::MyPoint() : name(""), x(0.0), y(0.0) {}

MyPoint::MyPoint(string name, double x, double y) : name(name), x(x), y(y) {}

MyPoint::~MyPoint() {}

string MyPoint::getName() const {
    return name;
}

double MyPoint::getX() const {
    return x;
}

double MyPoint::getY() const {
    return y;
}

