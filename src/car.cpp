#include "car.h"

Car::Car(const std::string Name, const std::string Number, const std::string DriversName, std::string SpritePath)
    : Position(START_POINT)
    , MoveType(0)
    , IsBusy(false)
    , Mark(0)
    , TripsCount(0)
    , Name(Name)
    , Number(Number)
    , DriversName(DriversName)
    , VertexMatch(0)
    , Texture(SpritePath)
    , Sprite(Texture)
{}

void Car::UpdateMark(const double CurMark) {
    ++TripsCount;
    Mark = (Mark + CurMark) / 2;
}

void Car::SetBusy(const double Busy) {
    IsBusy = Busy;
}

Point Car::GetPosition() {
    return Position;
}

sf::Sprite Car::GetSprite() {
    return Sprite;
}
