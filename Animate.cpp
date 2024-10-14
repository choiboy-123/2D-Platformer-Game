/**
 * @file Animate.cpp
 * @brief a subclass of Object, which acts as a superclass for all animated objects (Player and Enemy)
 * @author Emma, Jake
 * @bug no known bugs
 */

#include <iostream>
#include "Animate.h"

using namespace std;

/**
 * @brief constructor for an Animate object
 * @param levelSize 2D size of the level
 * @param size 2D size of the object
 */
Animate::Animate(sf::Vector2f levelSize, sf::Vector2f size) : Object(size) {
    lowerYBound = levelSize.y-shape->getSize().y;
    upperXBound = levelSize.x-shape->getSize().x;
}

/**
 * @brief updates the position of the object
 * @param timeElapsed time that has passed in the level
 */
void Animate::Update(int timeElapsed) {

    prevPosition = shape->getPosition();
    move(timeElapsed);

}

/**
 * @brief controls object movement; is left empty to indicate all Animate objects need this method
 * @param timeElapsed time since the last frame
 */
void Animate::move(int timeElapsed) {

}

/**
 * @brief lets the object stand on floors, hit walls/ceilings, and jump from the top of a block
 * @param terrain the Terrain object being collided against
 */
void Animate::collided(Object* terrain) {

    float xdif, ydif;

    if (prevPosition.x < shape->getPosition().x)
        xdif = terrain->getShape()->getPosition().x -
               (shape->getPosition().x + shape->getSize().x); //difference from left of terrain to right of player
    else
        xdif = terrain->getShape()->getPosition().x + terrain->getSize().x -
               shape->getPosition().x; //difference from right of terrain to left of player

    if (prevPosition.y < shape->getPosition().y)
        ydif = terrain->getShape()->getPosition().y -
               (shape->getPosition().y + shape->getSize().y); //difference from top of terrain to bottom of player
    else
        ydif = terrain->getShape()->getPosition().y + terrain->getSize().y -
               shape->getPosition().y; //difference from bottom of terrain to top of player

    //move the player as little as possible (towards its last position)
    if (abs(xdif) < abs(ydif))
        shape->move(xdif, 0);
    else {
        shape->move(0, ydif);
        vy = 0; //set the y velocity to 0 if there's a mostly vertical collision
        if (ydif < 0) jumped = false; //allow the player to jump if it's on top of a block
    }
}

/**
 * @brief get method for the object's prevPosition
 * @return returns the object's previous position
 */
sf::Vector2<float> Animate::getPrevPosition() {
    return prevPosition;
}