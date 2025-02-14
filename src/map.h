#pragma once
#include <SFML/Graphics.hpp>

class Map {
public:
    Map(std::string SpritePath);

    Map(const Map& other) = delete;
    Map operator=(const Map& other) = delete;

private:
    sf::Texture Texture;
    sf::Sprite Sprite;

    std::vector<std::vector<int>> Roads;

};
