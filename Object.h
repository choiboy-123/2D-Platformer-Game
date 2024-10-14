/**
 * @file Object.h
 * @brief the header for Object.cpp
 * @author Jake, Karen
 * @bug no known bugs
 */

#ifndef PLATFORMER_OBJECT_H
#define PLATFORMER_OBJECT_H

#include <SFML/Graphics.hpp>

class Object {
public:
    Object(sf::Vector2f size);
    sf::Shape* getShape();
    sf::Vector2f getSize();
    int getPositionX();
    int getPositionY();
    bool collides(Object* otherObject);
    void collect();
    void show();

protected:
    sf::RectangleShape* shape;
};

#endif //PLATFORMER_OBJECT_H
