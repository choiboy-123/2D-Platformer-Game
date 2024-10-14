
/**
 * @file Coin.cpp
 * @brief Class for coin as scoring system
 * @author Karen
 * @bug no known bugs
 */
#include "Coin.h"
/// Create texture and bool to check if texture has been applied
static sf::Texture* texture = new sf::Texture();
static bool texturesCreated = false;

/**
* @brief Coin constructor
* @author Karen
* @param size the size of the goal to be created
* @param pos the position of the goal to be created
* @bug no known bugs
*/
Coin::Coin(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    /// Load textures
    if (!texturesCreated) {
        texture->loadFromFile("Resources/Images/coin.png");
        texturesCreated = true;
    }
    /// Set Texture
    shape->setTexture(texture);

    /// Set Position
    shape->setPosition(position.x, position.y);
    //shape->setFillColor(sf::Color::Yellow);
}
/*void Coin::collect() {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Black);
}*/
