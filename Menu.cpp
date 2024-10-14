/**
 * @file Menu.cpp
 * @brief Handles any menus (level select, pause, etc.)
 * @author Jake
 * @bug no known bugs
 */

#include "Menu.h"

using namespace std;

/**
 * @brief This is the main menu function.
 * @param window    the window to draw the main menu to
 * @return          returns an integer based on the user selection
 */
int MainMenu(shared_ptr<sf::RenderWindow> window) {
    // set background
    window->clear(sf::Color::Black);

    // set up title of game texture
    sf::Texture titleTexture;
    sf::Sprite title;
    titleTexture.loadFromFile("Resources/Images/mainTitle.png");
    title.setTexture(titleTexture);
    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    title.setPosition(window->getSize().x/2, window->getSize().y/3);

    // set up play button for main menu
    sf::Texture playButtonText;
    sf::Sprite playButton;
    playButtonText.loadFromFile("Resources/Images/play_button.png");
    playButton.setTexture(playButtonText);
    playButton.setOrigin(playButton.getLocalBounds().width/2, playButton.getLocalBounds().height/2);
    playButton.setPosition(window->getSize().x/2, (window->getSize().y/3)*2);
    playButton.setColor(sf::Color(208, 169, 51));

    sf::Event evt;
    while (1) {
        while (window->pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            else if (evt.type == sf::Event::MouseMoved) { //if mouse hovers over sprites
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playButton.getGlobalBounds().contains(MPos)) {
                    playButton.setColor(sf::Color(34, 139, 34));
                }
                else {
                    playButton.setColor(sf::Color(208, 169, 51));
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) { //if mouse clicks while hovering over sprite
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playButton.getGlobalBounds().contains(MPos)) {
                    return 1;
                }
            }

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(playButton);
            window->display();
        }
    }
}

/**
 * @brief This is the game over menu (when player dies).
 * @param window    window to draw game over menu
 * @return          integer returned based on user selection
 */
int GameOver(shared_ptr<sf::RenderWindow> window) {
    // set background
    window->clear(sf::Color::Black);

    // set up title of game texture
    sf::Texture titleTexture;
    sf::Sprite title;
    titleTexture.loadFromFile("Resources/Images/gameover.png");
    title.setTexture(titleTexture);
    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    title.setPosition(window->getSize().x/2, window->getSize().y/4);

    // set up play button for game over menu
    sf::Texture playAgain;
    sf::Sprite playAgainButton;
    playAgain.loadFromFile("Resources/Images/playagain_button.png");
    playAgainButton.setTexture(playAgain);
    playAgainButton.setOrigin(playAgainButton.getLocalBounds().width/2, playAgainButton.getLocalBounds().height/2);
    playAgainButton.setPosition(window->getSize().x/2, (window->getSize().y/8)*5);

    // set up exit button for game over menu
    sf::Texture exit;
    sf::Sprite exitButton;
    exit.loadFromFile("Resources/Images/exit_button.png");
    exitButton.setTexture(exit);
    exitButton.setOrigin(exitButton.getLocalBounds().width/2, exitButton.getLocalBounds().height/2);
    exitButton.setPosition(window->getSize().x/2, (window->getSize().y/8)*7);

    sf::Event evt;
    while (1) {
        while (window->pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            else if (evt.type == sf::Event::MouseMoved) { // when mouse hovers over selectable sprites
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playAgainButton.getGlobalBounds().contains(MPos)) {
                    playAgainButton.setColor(sf::Color(34, 139, 34));
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    exitButton.setColor(sf::Color(34, 139, 34));
                }
                else {
                    playAgainButton.setColor(sf::Color::White);
                    exitButton.setColor(sf::Color::White);
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) { // when mouse clicks while hovering over selectable sprite
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playAgainButton.getGlobalBounds().contains(MPos)) {
                    return 0;
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    return 1;
                }
            }

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(playAgainButton);
            window->draw(exitButton);
            window->display();
        }
    }
}

/**
 * @brief The Level Complete level.
 * @param window    window to draw the level complete menu
 * @return          return integer based on user selection
 */
int LevelComplete(shared_ptr<sf::RenderWindow> window) {
    // set background
    window->clear(sf::Color::Black);

    // set up title of game texture
    sf::Texture titleTexture;
    sf::Sprite title;
    titleTexture.loadFromFile("Resources/Images/levelcomplete.png");
    title.setTexture(titleTexture);
    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    title.setPosition(window->getSize().x/2, window->getSize().y/4);

    // set up play button for level select menu
    sf::Texture playAgain;
    sf::Sprite playAgainButton;
    playAgain.loadFromFile("Resources/Images/playagain_button.png");
    playAgainButton.setTexture(playAgain);
    playAgainButton.setOrigin(playAgainButton.getLocalBounds().width/2, playAgainButton.getLocalBounds().height/2);
    playAgainButton.setPosition(window->getSize().x/2, (window->getSize().y/8)*5);

    // set up exit button
    sf::Texture exit;
    sf::Sprite exitButton;
    exit.loadFromFile("Resources/Images/exit_button.png");
    exitButton.setTexture(exit);
    exitButton.setOrigin(exitButton.getLocalBounds().width/2, exitButton.getLocalBounds().height/2);
    exitButton.setPosition(window->getSize().x/2, (window->getSize().y/8)*7);

    sf::Event evt;
    while (1) {
        while (window->pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            else if (evt.type == sf::Event::MouseMoved) { // hover over selectable sprites
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playAgainButton.getGlobalBounds().contains(MPos)) {
                    playAgainButton.setColor(sf::Color(34, 139, 34));
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    exitButton.setColor(sf::Color(34, 139, 34));
                }
                else {
                    playAgainButton.setColor(sf::Color::White);
                    exitButton.setColor(sf::Color::White);
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) {   // click mouse while hovering over selectable sprite
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playAgainButton.getGlobalBounds().contains(MPos)) {
                    return 0;
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    return 1;
                }
            }

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(playAgainButton);
            window->draw(exitButton);
            window->display();
        }
    }
}

/**
 * @brief Pause menu to be used.
 * @param window    the window to draw the pause menu onto
 * @return          return integer based on pause menu selection from user
 */
int PauseMenu(std::shared_ptr<sf::RenderWindow> window) {
    // set background
    window->clear(sf::Color::Black);

    // set up title of game texture
    sf::Texture titleTexture;
    sf::Sprite title;
    titleTexture.loadFromFile("Resources/Images/pauseMenu.png");
    title.setTexture(titleTexture);
    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    title.setPosition(window->getSize().x/2, window->getSize().y/4);

    // set up resume button
    sf::Texture resume;
    sf::Sprite resumeButton;
    resume.loadFromFile("Resources/Images/resume.png");
    resumeButton.setTexture(resume);
    resumeButton.setOrigin(resumeButton.getLocalBounds().width/2, resumeButton.getLocalBounds().height/2);
    resumeButton.setPosition(window->getSize().x/2, (window->getSize().y/16)*9);

    // set up level select button
    sf::Texture levelSelect;
    sf::Sprite levelSelectButton;
    levelSelect.loadFromFile("Resources/Images/levelSelect.png");
    levelSelectButton.setTexture(levelSelect);
    levelSelectButton.setOrigin(levelSelectButton.getLocalBounds().width/2, levelSelectButton.getLocalBounds().height/2);
    levelSelectButton.setPosition(window->getSize().x/2, (window->getSize().y/16)*11);

    // set up main menu button
    sf::Texture mainMenu;
    sf::Sprite mainMenuButton;
    mainMenu.loadFromFile("Resources/Images/mainMenu.png");
    mainMenuButton.setTexture(mainMenu);
    mainMenuButton.setOrigin(mainMenuButton.getLocalBounds().width/2, mainMenuButton.getLocalBounds().height/2);
    mainMenuButton.setPosition(window->getSize().x/2, (window->getSize().y/16)*13);

    // set up exit button
    sf::Texture exit;
    sf::Sprite exitButton;
    exit.loadFromFile("Resources/Images/exitGame.png");
    exitButton.setTexture(exit);
    exitButton.setOrigin(exitButton.getLocalBounds().width/2, exitButton.getLocalBounds().height/2);
    exitButton.setPosition(window->getSize().x/2, (window->getSize().y/16)*15);

    sf::Event evt;
    while (1) {
        while (window->pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            else if (evt.type == sf::Event::MouseMoved) { // if mouse hovers over selectable sprite
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (resumeButton.getGlobalBounds().contains(MPos)) {
                    resumeButton.setColor(sf::Color(34, 139, 34));
                } else if (levelSelectButton.getGlobalBounds().contains(MPos)) {
                    levelSelectButton.setColor(sf::Color(34, 139, 34));
                }
                else if (mainMenuButton.getGlobalBounds().contains(MPos)) {
                    mainMenuButton.setColor(sf::Color(34, 139, 34));
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    exitButton.setColor(sf::Color(34, 139, 34));
                } else {
                    resumeButton.setColor(sf::Color::White);
                    levelSelectButton.setColor(sf::Color::White);
                    mainMenuButton.setColor(sf::Color::White);
                    exitButton.setColor(sf::Color::White);
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) { // when mouse is clicked while hovering over selectable sprite
                // to be added...Resume (to continue playing), Level Select, Help, Main Menu, Exit Game
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (resumeButton.getGlobalBounds().contains(MPos)) {
                    return 0;
                }
                else if (levelSelectButton.getGlobalBounds().contains(MPos)) {
                    return 1;
                }
                else if (mainMenuButton.getGlobalBounds().contains(MPos)) {
                    return 2;
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    return -1;
                }
            }

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(resumeButton);
            window->draw(levelSelectButton);
            window->draw(mainMenuButton);
            window->draw(exitButton);
            window->display();
        }
    }
}

/**
 * @brief This is the pause menu while in level select.
 * @param window    window to draw the pause menu for the level select.
 * @return          return integer based on user selection
 */
int LevelSelectPause(std::shared_ptr<sf::RenderWindow> window) {
    // set background
    window->clear(sf::Color::Black);

    // set up title of game texture
    sf::Texture titleTexture;
    sf::Sprite title;
    titleTexture.loadFromFile("Resources/Images/pauseMenu.png");
    title.setTexture(titleTexture);
    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    title.setPosition(window->getSize().x/2, window->getSize().y/4);

    // set up resume button
    sf::Texture resume;
    sf::Sprite resumeButton;
    resume.loadFromFile("Resources/Images/resume.png");
    resumeButton.setTexture(resume);
    resumeButton.setOrigin(resumeButton.getLocalBounds().width/2, resumeButton.getLocalBounds().height/2);
    resumeButton.setPosition(window->getSize().x/2, (window->getSize().y/12)*7);

    // set up main menu button
    sf::Texture mainMenu;
    sf::Sprite mainMenuButton;
    mainMenu.loadFromFile("Resources/Images/mainMenu.png");
    mainMenuButton.setTexture(mainMenu);
    mainMenuButton.setOrigin(mainMenuButton.getLocalBounds().width/2, mainMenuButton.getLocalBounds().height/2);
    mainMenuButton.setPosition(window->getSize().x/2, (window->getSize().y/12)*9);

    // set up exit button
    sf::Texture exit;
    sf::Sprite exitButton;
    exit.loadFromFile("Resources/Images/exitGame.png");
    exitButton.setTexture(exit);
    exitButton.setOrigin(exitButton.getLocalBounds().width/2, exitButton.getLocalBounds().height/2);
    exitButton.setPosition(window->getSize().x/2, (window->getSize().y/12)*11);

    sf::Event evt;
    while (1) {
        while (window->pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            else if (evt.type == sf::Event::MouseMoved) {
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (resumeButton.getGlobalBounds().contains(MPos)) {
                    resumeButton.setColor(sf::Color(34, 139, 34));
                }
                else if (mainMenuButton.getGlobalBounds().contains(MPos)) {
                    mainMenuButton.setColor(sf::Color(34, 139, 34));
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    exitButton.setColor(sf::Color(34, 139, 34));
                } else {
                    resumeButton.setColor(sf::Color::White);
                    mainMenuButton.setColor(sf::Color::White);
                    exitButton.setColor(sf::Color::White);
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) {
                // to be added...Resume (to continue playing), Level Select, Help, Main Menu, Exit Game
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (resumeButton.getGlobalBounds().contains(MPos)) {
                    return 0;
                }
                else if (mainMenuButton.getGlobalBounds().contains(MPos)) {
                    return 2;
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    return -1;
                }
            }

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(resumeButton);
            window->draw(mainMenuButton);
            window->draw(exitButton);
            window->display();
        }
    }
}

/**
 * @brief The Level Select Menu that will call and play a level for the user based on their selection.
 * @param window    window to draw the level select menu
 * @return          returns an integer based on user's action
 */
int LevelSelectMenu(std::shared_ptr<sf::RenderWindow> window) {

    User* user1 = new User("User1", window); // open user's saved state
    vector<sf::Sprite> checks;
    vector<sf::Sprite> locks;
    vector<bool> visibleLevels;
    for (int i=0; i < 5; ++i) {
        visibleLevels.push_back(false);
    }
    visibleLevels[0] = true; // set only true for the first level so first level is playable

    // set up checkmarks
    sf::Texture check;
    check.loadFromFile("Resources/Images/check.png");

    sf::Sprite level1Check;
    level1Check.setTexture(check);
    level1Check.setOrigin(level1Check.getLocalBounds().width/2, level1Check.getLocalBounds().height/2);
    level1Check.setPosition(window->getSize().x/4, window->getSize().y/4);
    checks.push_back(level1Check);

    sf::Sprite level2Check;
    level2Check.setTexture(check);
    level2Check.setOrigin(level2Check.getLocalBounds().width/2, level2Check.getLocalBounds().height/2);
    level2Check.setPosition((window->getSize().x/4)*2, window->getSize().y/4);
    checks.push_back(level2Check);

    sf::Sprite level3Check;
    level3Check.setTexture(check);
    level3Check.setOrigin(level3Check.getLocalBounds().width/2, level3Check.getLocalBounds().height/2);
    level3Check.setPosition((window->getSize().x/4)*3, window->getSize().y/4);
    checks.push_back(level3Check);

    sf::Sprite level4Check;
    level4Check.setTexture(check);
    level4Check.setOrigin(level4Check.getLocalBounds().width/2, level4Check.getLocalBounds().height/2);
    level4Check.setPosition((window->getSize().x/3), (window->getSize().y/4)*3);
    checks.push_back(level4Check);

    sf::Sprite level5Check;
    level5Check.setTexture(check);
    level5Check.setOrigin(level5Check.getLocalBounds().width/2, level5Check.getLocalBounds().height/2);
    level5Check.setPosition((window->getSize().x/3)*2, (window->getSize().y/4)*3);
    checks.push_back(level5Check);

    // set up locks
    sf::Texture lock;
    lock.loadFromFile("Resources/Images/lock.png");

    sf::Sprite level1Lock;
    level1Lock.setTexture(lock);
    level1Lock.setOrigin(level1Lock.getLocalBounds().width/2, level1Lock.getLocalBounds().height/2);
    level1Lock.setPosition(window->getSize().x/4, window->getSize().y/4);
    locks.push_back(level1Lock);

    sf::Sprite level2Lock;
    level2Lock.setTexture(lock);
    level2Lock.setOrigin(level2Lock.getLocalBounds().width/2, level2Lock.getLocalBounds().height/2);
    level2Lock.setPosition((window->getSize().x/4)*2, window->getSize().y/4);
    locks.push_back(level2Lock);

    sf::Sprite level3Lock;
    level3Lock.setTexture(lock);
    level3Lock.setOrigin(level3Lock.getLocalBounds().width/2, level3Lock.getLocalBounds().height/2);
    level3Lock.setPosition((window->getSize().x/4)*3, window->getSize().y/4);
    locks.push_back(level3Lock);

    sf::Sprite level4Lock;
    level4Lock.setTexture(lock);
    level4Lock.setOrigin(level4Lock.getLocalBounds().width/2, level4Lock.getLocalBounds().height/2);
    level4Lock.setPosition((window->getSize().x/3), (window->getSize().y/4)*3);
    locks.push_back(level4Lock);

    sf::Sprite level5Lock;
    level5Lock.setTexture(lock);
    level5Lock.setOrigin(level5Lock.getLocalBounds().width/2, level5Lock.getLocalBounds().height/2);
    level5Lock.setPosition((window->getSize().x/3)*2, (window->getSize().y/4)*3);
    locks.push_back(level5Lock);

    // set up level boxes
    sf::Texture level1;
    sf::Sprite level1Box;
    level1.loadFromFile("Resources/Images/level1Box.png");
    level1Box.setTexture(level1);
    level1Box.setOrigin(level1Box.getLocalBounds().width/2, level1Box.getLocalBounds().height/2);
    level1Box.setPosition(window->getSize().x/4, window->getSize().y/4);

    // set up level boxes
    sf::Texture level2;
    sf::Sprite level2Box;
    level2.loadFromFile("Resources/Images/level2Box.png");
    level2Box.setTexture(level2);
    level2Box.setOrigin(level2Box.getLocalBounds().width/2, level2Box.getLocalBounds().height/2);
    level2Box.setPosition(window->getSize().x/2, (window->getSize().y/4));

    // set up level boxes
    sf::Texture level3;
    sf::Sprite level3Box;
    level3.loadFromFile("Resources/Images/level3Box.png");
    level3Box.setTexture(level3);
    level3Box.setOrigin(level3Box.getLocalBounds().width/2, level3Box.getLocalBounds().height/2);
    level3Box.setPosition((window->getSize().x/4)*3, (window->getSize().y/4));

    // set up level boxes
    sf::Texture level4;
    sf::Sprite level4Box;
    level4.loadFromFile("Resources/Images/level4Box.png");
    level4Box.setTexture(level4);
    level4Box.setOrigin(level4Box.getLocalBounds().width/2, level4Box.getLocalBounds().height/2);
    level4Box.setPosition(window->getSize().x/3, (window->getSize().y/4)*3);

    // set up level boxes
    sf::Texture level5;
    sf::Sprite level5Box;
    level5.loadFromFile("Resources/Images/level5Box.png");
    level5Box.setTexture(level5);
    level5Box.setOrigin(level5Box.getLocalBounds().width/2, level5Box.getLocalBounds().height/2);
    level5Box.setPosition((window->getSize().x/3)*2, (window->getSize().y/4)*3);

    sf::Event evt;
    while (1) {
        while (window->pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            else if (evt.type == sf::Event::MouseMoved) {
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (level1Box.getGlobalBounds().contains(MPos) && visibleLevels[0]) {
                    level1Box.setColor(sf::Color(34, 139, 34));
                } else if (level2Box.getGlobalBounds().contains(MPos) && visibleLevels[1]) {
                    level2Box.setColor(sf::Color(34, 139, 34));
                }
                else if (level3Box.getGlobalBounds().contains(MPos) && visibleLevels[2]) {
                    level3Box.setColor(sf::Color(34, 139, 34));
                }
                else if (level4Box.getGlobalBounds().contains(MPos) && visibleLevels[3]) {
                    level4Box.setColor(sf::Color(34, 139, 34));
                }
                else if (level5Box.getGlobalBounds().contains(MPos) && visibleLevels[4]) {
                    level5Box.setColor(sf::Color(34, 139, 34));
                } else {
                    level1Box.setColor(sf::Color::White);
                    level2Box.setColor(sf::Color::White);
                    level3Box.setColor(sf::Color::White);
                    level4Box.setColor(sf::Color::White);
                    level5Box.setColor(sf::Color::White);
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) {
                // to be added...Resume (to continue playing), Level Select, Help, Main Menu, Exit Game
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (level1Box.getGlobalBounds().contains(MPos) && visibleLevels[0]) { //open level 1
                    Level* level = new Level(window, "level1");
                    int gameEvent = level->play(window);
                    if (gameEvent == 0) { // if player dies
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        int select = GameOver(window);
                        if (select == 0) { // selected play again
                            continue;
                        }
                        else if (select == 1) { // selected quit
                            user1->updateMeta(); // update metadata to save the current state
                            return -1;
                        }
                    }
                    else if (gameEvent == 1) { // if player completes level
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        user1->saveState(1); // update the save state to reflect completed level (ie. unlock new level)
                        int select = LevelComplete(window);
                        if (select == 0) { // if player selects to play again
                            continue;
                        }
                        else if (select == 1) { // if player decides to quit
                            user1->updateMeta();
                            return -1;
                        }
                    }
                    else if (gameEvent == 2) { // if player goes to level select from pause menu
                        continue;
                    }
                    else if (gameEvent == 3) { // if player goes to main menu from pause menu
                        user1->updateMeta();
                        return 0;
                    }
                    else if (gameEvent == -1) { // if player exits from pause menu
                        user1->updateMeta();
                        return -1; //game was closed
                    }
                }
                else if (level2Box.getGlobalBounds().contains(MPos) && visibleLevels[1]) { // same comments as the first level for the rest of the level blocks
                    Level* level = new Level(window, "level2");
                    int gameEvent = level->play(window);
                    if (gameEvent == 0) {
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        int select = GameOver(window);
                        if (select == 0) {
                            continue;
                        }
                        else if (select == 1) {
                            user1->updateMeta();
                            return -1;
                        }
                    }
                    else if (gameEvent == 1) {
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        user1->saveState(2);
                        int select = LevelComplete(window);
                        if (select == 0) {
                            continue;
                        }
                        else if (select == 1) {
                            user1->updateMeta();
                            return -1;
                        }
                    }
                    else if (gameEvent == 2) {
                        continue;
                    }
                    else if (gameEvent == 3) {
                        user1->updateMeta();
                        return 0;
                    }
                    else if (gameEvent == -1) {
                        user1->updateMeta();
                        return -1; //game was closed
                    }
                }
                else if (level3Box.getGlobalBounds().contains(MPos) && visibleLevels[2]) {
                    Level* level = new Level(window, "level3");
                    int gameEvent = level->play(window);
                    if (gameEvent == 0) {
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        int select = GameOver(window);
                        if (select == 0) {
                            continue;
                        }
                        else if (select == 1) {
                            user1->updateMeta();
                            return -1;
                        }
                    }
                    else if (gameEvent == 1) {
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        user1->saveState(3);
                        int select = LevelComplete(window);
                        if (select == 0) {
                            continue;
                        }
                        else if (select == 1) {
                            user1->updateMeta();
                            return -1;
                        }
                    }
                    else if (gameEvent == 2) {
                        continue;
                    }
                    else if (gameEvent == 3) {
                        user1->updateMeta();
                        return 0;
                    }
                    else if (gameEvent == -1) {
                        user1->updateMeta();
                        return -1; //game was closed
                    }
                }
                else if (level4Box.getGlobalBounds().contains(MPos) && visibleLevels[3]) {
                    Level* level = new Level(window, "level4");
                    int gameEvent = level->play(window);
                    if (gameEvent == 0) {
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        int select = GameOver(window);
                        if (select == 0) {
                            continue;
                        }
                        else if (select == 1) {
                            user1->updateMeta();
                            return -1;
                        }
                    }
                    else if (gameEvent == 1) {
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        user1->saveState(4);
                        int select = LevelComplete(window);
                        if (select == 0) {
                            continue;
                        }
                        else if (select == 1) {
                            user1->updateMeta();
                            return -1;
                        }
                    }
                    else if (gameEvent == 2) {
                        continue;
                    }
                    else if (gameEvent == 3) {
                        user1->updateMeta();
                        return 0;
                    }
                    else if (gameEvent == -1) {
                        user1->updateMeta();
                        return -1; //game was closed
                    }
                }
                else if (level5Box.getGlobalBounds().contains(MPos) && visibleLevels[4]) {
                    Level* level = new Level(window, "level5");
                    int gameEvent = level->play(window);
                    if (gameEvent == 0) {
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        int select = GameOver(window);
                        if (select == 0) {
                            continue;
                        }
                        else if (select == 1) {
                            user1->updateMeta();
                            return -1;
                        }
                    }
                    else if (gameEvent == 1) {
                        window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                        user1->saveState(5);
                        int select = LevelComplete(window);
                        if (select == 0) {
                            continue;
                        }
                        else if (select == 1) {
                            user1->updateMeta();
                            return -1;
                        }
                    }
                    else if (gameEvent == 2) {
                        continue;
                    }
                    else if (gameEvent == 3) {
                        user1->updateMeta();
                        return 0;
                    }
                    else if (gameEvent == -1) {
                        user1->updateMeta();
                        return -1; //game was closed
                    }
                }
            }
            else if (evt.type == sf::Event::KeyPressed) { // if user selects escape from level select
                if (evt.key.scancode == sf::Keyboard::Scan::Escape) {
                    window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                    int pauseSelect = LevelSelectPause(window);
                    if (pauseSelect == 2) {
                        // open main menu again
                        user1->updateMeta();
                        return 0;
                    }
                    else if (pauseSelect == -1) { // exit game
                        user1->updateMeta();
                        return -1;
                    }
                }
            }

            window->clear(sf::Color::Black);

            window->draw(level1Box);
            window->draw(level2Box);
            window->draw(level3Box);
            window->draw(level4Box);
            window->draw(level5Box);

            int numLevels = user1->getNumAccessibleLevels();
            int counter = 0;
            for (int i = 0; i < numLevels-1; i++) { // check what levels have been completed
                window->draw(checks[i]);
                counter++;
                visibleLevels[i] = true;
            }
            visibleLevels[numLevels-1] = true;
            counter += 1;

            for (int i=5; i > counter; i--) { // lock what levels cannot be accessed
                window->draw(locks[i-1]);
            }

            window->display();
        }
    }
}
