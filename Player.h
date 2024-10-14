/**
 * @file Player.h
 * @brief the header for Player.cpp
 * @author Liam, Karen, Jake, Emma
 * @bug no known bugs
 */

#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include "Animate.h"
#include <SFML/Graphics.hpp>

/**
 * @brief an Player object's methods and instances. It also inherits from Animate and Object
 */
class Player : public Animate {
public:
    using Animate::Animate;
    Player(sf::Vector2f start, sf::Vector2f levelSize, sf::Vector2f size);

private:
//    const float speed = 0.002;
//    const unsigned int lowerXBound = 0; //temporary
//    unsigned int lowerYBound; //temporary
//    const float gravity = -0.0000002;
//    const float initialJumpVelocity = 0.008;
//    const float midJumpAcceleration = 0.0000001;
//    const float terminalVelocity = -0.1;
//    const float simSpeed = 0.25;
//    float vy = 0;
//    float ay = 0;
//    bool jumped = false;
//    sf::Vector2<float> prevPosition;
    sf::Texture textureRight;
    sf::Texture textureLeft;

    void move(int timeElapsed) override;   // made private as it's inherited from Animate
};


#endif //PLATFORMER_PLAYER_H
