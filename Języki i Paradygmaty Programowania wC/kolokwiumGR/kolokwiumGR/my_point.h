#pragma once

#ifndef MY_POINT_H
#define MY_POINT_H

#include <string>

using std::string;

class MyPoint {
public:
    MyPoint();
    MyPoint(string name, double x, double y);
    ~MyPoint();

    string getName() const;
    double getX() const;
    double getY() const;

private:
    string name;
    double x;
    double y;
};

#endif
