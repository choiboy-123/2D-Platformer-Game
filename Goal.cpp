/**
 * @file Goal.cpp
 * @brief object that finishes the level on collision
 * @author Jake, Karen
 * @bug no known bugs
 */

#include "Goal.h"

static sf::Texture* texture = new sf::Texture();
static bool texturesCreated = false;

/**
 * @brief creates a new goal/endpoint
 * @param size the size of the goal to be created
 * @param pos the position of the goal to be created
 */
Goal::Goal(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    /// Load textures
    if (!texturesCreated) {
        texture->loadFromFile("Resources/Images/door.png");
        texturesCreated = true;
    }
    /// Set Texture and Position
    shape->setTexture(texture);
    shape->setPosition(position.x, position.y);
    //shape->setFillColor(sf::Color::Green);
}