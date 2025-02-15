#pragma once

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>

#include "types.h"
#include "config.h"

using Graph = std::vector<std::vector<std::pair<int, int>>>;

class Map {
public:
    Map(const std::string& SpritePath);

    Map(const Map& other) = delete;
    Map operator=(const Map& other) = delete;

    sf::Sprite GetSprite();
    std::vector<Point> GetPoints();

    void Build(const std::string& jsonPath);

    std::vector<Point> GetPath(Point Start, Point Finish);

private:
    sf::Texture Texture;
    sf::Sprite Sprite;

    Graph Roads;
    std::unordered_map<Point, int, std::hash<Point>> PointToId;
    std::vector<Point> IdToPoint;

};
