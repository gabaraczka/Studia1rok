#pragma once
#ifndef MY_POLIGON_H
#define MY_POLIGON_H

#include "my_point.h"

using std::string;

class MyPoligon {
public:
    MyPoligon();
    MyPoligon(string name, MyPoint* points, size_t numPoints);
    ~MyPoligon();

    string getName() const;
    MyPoint* getPoints() const;
    size_t getNumPoints() const;

private:
    string name;
    MyPoint* points;
    size_t numPoints;
};

#endif
