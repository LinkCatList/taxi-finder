#pragma once

#include <cmath>

struct Point {
    Point(double x, double y)
        : x(x)
        , y(y)
    {}

    Point operator +(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    Point operator -(const Point& other) {
        return Point(x - other.x, y - other.y);
    }

    bool operator ==(const Point& other) {
        return x == other.x && y == other.y;
    }

    double Dist(const Point& other) {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

    double x;
    double y;

};

#define START_POINT Point(0, 0)
