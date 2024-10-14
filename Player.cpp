/**
 * @file Player.cpp
 * @brief handles player movement and collisions
 * @author Liam, Karen, Jake, Emma
 * @bug no known bugs
 */

#include "Player.h"

using namespace std;

/**
 * @brief the constructor for a Player object
 * @param start starting position for a player on a level
 * @param levelSize 2d size of the level
 * @param size size of the player
 */
Player::Player(sf::Vector2f start, sf::Vector2f levelSize, sf::Vector2f size) : Animate(levelSize, size) {

    shape->move(start);
    textureRight.loadFromFile("Resources/Images/Main-Character-Right.png");
    textureLeft.loadFromFile("Resources/Images/Main-Character-Left.png");
    shape->setTexture(&textureRight);
    //shape->setFillColor(sf::Color::Blue);
}

/**
 * @brief control player left/right and jump movement with WASD keys
 * @param timeElapsed time since the last frame
 */
void Player::move(int timeElapsed) {

    timeElapsed *= simSpeed;

    //left and right motion
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shape->getPosition().x - speed * timeElapsed > lowerXBound) {
        shape->move(-speed * timeElapsed, 0);
        shape->setTexture(&textureLeft);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && shape->getPosition().x + speed * timeElapsed < upperXBound) {
        shape->move(speed * timeElapsed, 0);
        shape->setTexture(&textureRight);
    }
    //

    //initial jump
    if (!jumped &&
        ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))) {
        vy = initialJumpVelocity;
        jumped = true;
    }

        //midair control (jump higher/delay landing)
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        ay = midJumpAcceleration + gravity;
    } else ay = gravity;

    //change velocity based on acceleration up to some terminal velocity
    if (vy + ay * timeElapsed >= terminalVelocity) vy += ay * timeElapsed;
    else vy = terminalVelocity;
    //

    //change position until you hit the floor
    if (shape->getPosition().y - vy < lowerYBound) {
        shape->move(0, -vy * timeElapsed);
    } else {
        jumped = false; //reset jump
        shape->setPosition(shape->getPosition().x, lowerYBound);
    }
    //

}