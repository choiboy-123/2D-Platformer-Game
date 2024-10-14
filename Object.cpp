/**
 * @file Object.cpp
 * @brief defines methods and attributes any object in the game will have
 * @author Jake, Karen
 * @bug no known bugs
 */

#include <iostream>
#include "Object.h"

using namespace std;

/**
 * @brief The constructor for the Object class
 * @param size The size of the Object to create
 */
Object::Object(sf::Vector2f size) {
    shape = new sf::RectangleShape(size);
}

/**
 * @brief gets the shape of the object class
 * @return the shape of the object class
 */
sf::Shape* Object::getShape() {
    return shape;
}

/**
 * @brief gets the size of the object class
 * @return the size of the object
 */
sf::Vector2f Object::getSize() {
    return shape->getSize();
}

/**
 * @brief gets the x position of the object as an int
 * @return the x position of the object
 */
int Object::getPositionX() {
    return shape->getPosition().x;
}

/**
 * @brief gets the y position of the object as an int
 * @return the y position of the object
 */
int Object::getPositionY() {
    return shape->getPosition().y;
}

/**
 * @brief checks for collision between two objects
 * @param otherObject the object to check if this object is colliding with
 * @return true if the two objects are colliding, false otherwise
 */
bool Object::collides(Object* otherObject) {
    return shape->getGlobalBounds().intersects(otherObject->getShape()->getGlobalBounds());
}

void Object::collect() {
     shape->setSize(sf::Vector2f(0,0));
}

void Object::show() {
    shape->setSize(sf::Vector2f(50,50));
}