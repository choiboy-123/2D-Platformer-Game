/**
 * @file Coin.h
 * @brief Header for Score.cpp
 * @author Karen
 * @bug no known bugs
 */
#ifndef PLATFORMER_SCORE_H
#define PLATFORMER_SCORE_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Score : public Object {
public:
    /**
     * @brief Score constructor
     * @author Karen
     * @param size the size of the goal to be created
     * @param pos the position of the goal to be created
     * @bug no known bugs
     */
    Score(sf::Vector2f size, sf::Vector2f pos);
    /*  Score();
      void increment();
      sf::Text getScore();*/
    //void collect(); //Collect coin

private:
    /// Variable for position
    sf::Vector2f position;
    /*sf::Text score;
    std::string nonConstStr;*/
};

#endif ///PLATFORMER_SCORE_H
