/**
 * @brief Objects the player can collide with without being harmed
 * @author Liam
 */

#ifndef PLATFORMER_TERRAIN_H
#define PLATFORMER_TERRAIN_H

#include "Object.h"
#include <SFML/Graphics.hpp>

/**
 * @brief Terrain constructor
 * @param size the size of the terrain object to be created
 * @param pos the position for the terrain to be created at
 */
class Terrain : public Object {
public:
    Terrain(sf::Vector2f size, sf::Vector2f pos);

private:
    sf::Vector2f position;
};

#endif //PLATFORMER_TERRAIN_H
