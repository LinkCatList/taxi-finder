#pragma once

#include "types.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Car {
public:
    Car(const std::string Name, const std::string Number, const std::string DriversName, std::string SpritePath);

    void UpdateMark(const double CurMark);
    void SetBusy(const double Busy);

    Point GetPosition();
    sf::Sprite GetSprite();

private:
    Point Position;
    int MoveType;

    bool IsBusy;

    double Mark;
    int TripsCount;

    const std::string Name;
    const std::string Number;

    std::string DriversName;

    int VertexMatch;

    sf::Texture Texture;
    sf::Sprite Sprite;

};
