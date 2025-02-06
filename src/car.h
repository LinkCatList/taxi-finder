#pragma once

#include "types.h"

#include <iostream>

class Car {
public:
    Car(const std::string& Name, const std::string& Number, const std::string& DriversName);

    void UpdateMark(const double CurMark);
    void SetBuisy(const double Buisy);


private:
    Point Position;
    double Speed;

    bool IsBuisy;

    double Mark;
    int TripsCount;

    const std::string Name;
    const std::string Number;

    std::string DriversName;

};
