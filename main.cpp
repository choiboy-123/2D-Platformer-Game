/**
 * @file main.cpp
 * @brief The main file, where the game is initiated.
 * @author Liam, Karen, Jake
 * @bug no known bugs
 */


#include <iostream>
#include <SFML/Graphics.hpp>

#include "Menu.h"

using namespace std;

int main() {

    shared_ptr<sf::RenderWindow> mainWindow(nullptr); //define main window to be used by all classes

    mainWindow = make_shared<sf::RenderWindow> (sf::VideoMode::getFullscreenModes()[0], "Platformer", sf::Style::Fullscreen); //set to fullscreen mode

    while (mainWindow->isOpen())
    {
        mainWindow->setView(sf::View(sf::FloatRect(0, 0, mainWindow->getSize().x, mainWindow->getSize().y)));
        int select = MainMenu(mainWindow); //open main menu
        if (!mainWindow->isOpen()) {
            break;
        }
        else if (select == 1) {
            int selectedLevel = LevelSelectMenu(mainWindow); //open level select
            if (selectedLevel < 0) {
                mainWindow->close();
                break;
            }
        }
    }
    return 0;
}

