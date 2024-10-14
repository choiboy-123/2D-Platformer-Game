/**
 * @file Level.h
 * @brief The header file for Level.cpp
 * @author Liam, Karen, Jake, Emma
 * @bug no known bugs
 */
#ifndef PLATFORMER_LEVEL_H
#define PLATFORMER_LEVEL_H

#define GRIDSIZE 64
//#define DEFAULT_WINDOW_WIDTH 800
//#define DEFAULT_WINDOW_HEIGHT 600
#define BACKGROUND_HEIGHT (-1080+159)
#define BACKGROUND_WIDTH 1920

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "Obstacle.h"
#include "Terrain.h"
#include "Goal.h"
#include "Menu.h"
#include "Coin.h"
#include "Score.h"
#include "Enemy.h"

class Level {
public:
    Level(std::shared_ptr<sf::RenderWindow> window, std::string levelName);
    int play(std::shared_ptr<sf::RenderWindow> window);
    bool load(std::string levelName);
    int getLevel();
private:
    //Initialize needed variables
    bool coinsCollect = false;
    sf::Clock gameClock;
    Player* player;
    std::vector<Object*> deathObjects;
    std::vector<Object*> rewardObjects;
    std::vector<Object*> scoreObjects;
    std::vector<Object*> terrain;
    std::vector<Goal*> goals;
    sf::RectangleShape floor;
    sf::Texture backgroundTexture;
    std::vector<sf::Sprite*> backgrounds;
    sf::Vector2f start;
    sf::Vector2f size;
    //Goal* goal;
    sf::View* camera;
    Enemy* enemy;
    std::vector<Enemy*> enemies;
    std::vector<sf::Vector2f*> enemyStartPositions;  // setting points where enemy walks
    std::vector<sf::Vector2f*> enemyEndPositions;
    int levelNum;
};



#endif //PLATFORMER_LEVEL_H
