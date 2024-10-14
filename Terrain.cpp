/**
 * @brief Objects the player can collide with without being harmed
 * @author Liam
 */

#include "Terrain.h"

static sf::Texture* texture = new sf::Texture();
static bool texturesCreated = false;

/**
 * @brief Terrain constructor
 * @author Liam
 * @param size the size of the terrain object to be created
 * @param pos the position for the terrain to be created at
 */
Terrain::Terrain(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    if (!texturesCreated) {
        texture->loadFromFile("Resources/Images/Smaller-Tiles.png");
        texturesCreated = true;
    }
    shape->setTexture(texture);
}

