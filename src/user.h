#pragma once

#include "types.h"

class User {
public:
    User(const Point& Position, const double Radius)
        : Position(Position)
        , SearchRadius(Radius)
    {}

    Point GetPosition();

private:
    Point Position;
    double SearchRadius;

};
