/**
 * @file Enemy.h
 * @brief The header file for Enemy.cpp
 * @author Emma
 * @bug no known bugs
 */

#ifndef PLATFORMER_ENEMY_H
#define PLATFORMER_ENEMY_H

#include "Animate.h"
#include <SFML/Graphics.hpp>

/**
 * @brief an Enemy object's methods and instances. It also inherits from Animate and Object
 */
class Enemy : public Animate {
public:
    using Animate::Animate;
    Enemy(sf::Vector2f enemyStart, sf::Vector2f enemyEnd, sf::Vector2f levelSize, sf::Vector2f size);

private:
    void move(int timeElapsed) override;
    sf::Vector2f enemyStartPosition;   // setting points where enemy walks
    sf::Vector2f enemyEndPosition;
    bool left = false;      // detect if enemy's going left or not
};


#endif //PLATFORMER_ENEMY_H
