/**
 * @file Obstacle.h
 * @brief the header for Obstacle.cpp
 * @author Karen, Jake
 * @bug no known bugs
 */

#ifndef PLATFORMER_OBSTACLES_H
#define PLATFORMER_OBSTACLES_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Obstacle : public Object {
public:
    Obstacle(sf::Vector2f size, sf::Vector2f pos);

private:
    sf::Vector2f position;
};


#endif //PLATFORMER_PLAYER_H
