#include "car.h"
#include "config.h"

Car::Car(const std::string Name, const std::string Number, const std::string DriversName)
    : Position(START_POINT)
    , MoveType(0)
    , IsBusy(false)
    , Mark(0)
    , TripsCount(0)
    , Name(Name)
    , Number(Number)
    , DriversName(DriversName)
    , VertexMatch(0)
    , Texture(PICS_PATH + Number + ".png")
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

void Car::Normalize() {
    for (int i = 0; i < 4 - MoveType; ++i) {
        Sprite.rotate(sf::degrees(-90));
    }
    MoveType = 0;
}

void Car::Rotate(int newMoveType) {
    Sprite.setPosition({100, 100});
    if (MoveType == newMoveType) {
        return;
    }
    Normalize();
    for (int i = 0; i < newMoveType; ++i) {
        Sprite.rotate(sf::degrees(-90));
        std::cout << "rotated" << std::endl;
    }
    MoveType = newMoveType;
}
