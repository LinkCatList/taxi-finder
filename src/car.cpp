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
{
    Sprite.setOrigin({22, 37});
}

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
    if (MoveType == newMoveType) {
        return;
    }
    Normalize();
    for (int i = 0; i < newMoveType; ++i) {
        Sprite.rotate(sf::degrees(-90));
    }
    MoveType = newMoveType;
}

void Car::SetPos(Point p) {
    Sprite.setPosition({p.x, p.y});
    Position = p;
}

void Car::MoveTo(Point p) {
    if (std::abs(Position.x - p.x) > std::abs(Position.y - p.y)) {
        if (Position.x < p.x) {
            ++Position.x;
        }
        if (Position.x > p.x) {
            --Position.x;
        }
    }
    else {
        if (Position.y < p.y) {
            ++Position.y;
        }
        if (Position.y > p.y) {
            --Position.y;
        }
    }
    SetPos(Position);
}

void Car::Rotate(Point p) {
    if (std::abs(Position.y - p.y) > std::abs(Position.x - p.x)) {
        if (Position.y < p.y) {
            Rotate(0);
            MoveType = 0;
        }
        if (Position.y > p.y) {
            Rotate(2);
            MoveType = 2;
        }
    }
    else {
        if (Position.x < p.x) {
            Rotate(1);
            MoveType = 1;
        }
        if (Position.x > p.x) {
            Rotate(3);
            MoveType = 3;
        }
    }
}
