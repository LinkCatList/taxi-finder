#pragma once

#include <SFML/Graphics.hpp>

#include "types.h"
#include "map.h"

#include <iostream>

class Car {
public:
    Car(const std::string Name, const std::string Number, const std::string DriversName);

    void UpdateMark(const double CurMark);
    void SetBusy(const double Busy);

    Point GetPosition();
    sf::Sprite GetSprite();

    void SetPos(Point p);
    void SetFinish(Point p);
    void SetStart(Point p);

    void MoveTo(Point p);
    void Rotate(Point p);
    void Rotate(int newMoveType);
    void Normalize();

    void InitStations(Map& map);

    bool OnNextTick();

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

    Point Start;
    Point Finish;

    std::vector<Point> Stations;

};
