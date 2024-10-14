/**
 * @file Obstacle.cpp
 * @brief defines objects that kill the player when touched
 * @author Karen
 * @bug no known bugs
 */

#include "Obstacle.h"

static sf::Texture* texture = new sf::Texture();
static bool texturesCreated = false;

// Obstacles constructor
/**
 * @brief Constructor for the Obstacle class
 * @param size The size of the Obstacle to create
 * @param pos The position to create the Obstacle at
 */
Obstacle::Obstacle(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    //load textures
    if (!texturesCreated) {
        texture->loadFromFile("Resources/Images/fire.png");
        texturesCreated = true;
    }
    shape->setTexture(texture);

    shape->setPosition(position.x, position.y);
    //shape->setFillColor(sf::Color::Red);
}

