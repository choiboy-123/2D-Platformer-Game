/**
 * @file User.h
 * @brief Header file for User.cpp
 * @author Jake
 * @bug no known bugs
 */

#ifndef PLATFORMER_USER_H
#define PLATFORMER_USER_H

#include <iostream>
#include <fstream>
#include "Level.h"
#include "Menu.h"

using namespace std;

class User {
public:
    User(string userName, shared_ptr<sf::RenderWindow> window);
    void saveState(int levelCompleted);
    void updateMeta();
    int getNumAccessibleLevels();

private:
    string user;
    vector<string> levels;
    shared_ptr<sf::RenderWindow> mainWindow;
};

#endif //PLATFORMER_USER_H
