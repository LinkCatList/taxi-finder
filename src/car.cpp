#include "car.h"

Car::Car(const std::string& Name, const std::string& Number, const std::string& DriversName)
    : Position(START_POINT)
    , Speed(0)
    , IsBuisy(false)
    , Mark(0)
    , TripsCount(0)
    , Name(Name)
    , Number(Number)
    , DriversName(DriversName)
{}

void Car::UpdateMark(const double CurMark) {
    ++TripsCount;
    Mark = (Mark + CurMark) / 2;
}

void Car::SetBuisy(const double Buisy) {
    IsBuisy = Buisy;
}
