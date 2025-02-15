#pragma once

#include <cmath>
#include <iostream>
#include <memory>

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

    bool operator ==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    double SquareDist(const Point& other) {
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
    }

    double x;
    double y;

};

template<>
class std::hash<Point> {
public:
    std::size_t operator()(const Point& key) const {
        return std::hash<double>()(key.x) ^ (std::hash<double>()(key.y) << 1);
    }
};

#define START_POINT Point(0, 0)
