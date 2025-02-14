#include "map.h"

Map::Map(std::string SpritePath) 
    : Texture(SpritePath)
    , Sprite(Texture)
{}

sf::Sprite Map::GetSprite() {
    return Sprite;
}
