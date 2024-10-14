/**
 * @file User.cpp
 * @brief
 * @author Jake
 * @bug no known bugs
 */

#include "User.h"

/**
 * @brief Construtor for User object.
 * @param userName      name of user
 * @param window        window being used by the game
 */
User::User(string userName, shared_ptr<sf::RenderWindow> window) {
    mainWindow = window;
    user = userName;
    fstream savedData;
    savedData.open("Resources/Metadata/SavedUsers.txt", ios::in); // open metadata
    if (!savedData) {
        cout << "Saved data was not found. Please ensure it's in the correct place.";
        window->close();
    }
    else { // correctly parse data from metadata to correctly load the user's saved state
        for (string line; getline(savedData, line); ) {
            string delimiter = " ";
            size_t pos = 0;
            string token;
            pos = line.find(delimiter);
            token = line.substr(0, pos);
            line.erase(0, pos+delimiter.length());
            if (token.find(user) != string::npos) {
                while ((pos = line.find(delimiter)) != string::npos) {
                    token = line.substr(0, pos);
                    levels.push_back(token);
                    line.erase(0, pos+delimiter.length());
                }
                token = line.substr(0, pos);
                if (token != "User1:") {
                    levels.push_back(token);
                }
                break;
            }
        }
        if (levels.empty()) { // if first time playing, allow player to play level 1
            levels.push_back("level1");
        }
    }
}

/**
 * @brief Function to update save state when another level has been completed.
 * @param levelCompleted    the level that was completed
 */
void User::saveState(int levelCompleted) {
    if (levelCompleted < 5 && levelCompleted >= levels.size()) { // add to the vector the most recent level completed
        if (levelCompleted == 1) {

        }
            string nextLevel = "level" + to_string(levelCompleted + 1);
            levels.push_back(nextLevel);
    }
    else if (levelCompleted >= 5) { // if all 5 levels have been completed, add complete to indicate in save state that the levels are complete
        levels.push_back("complete");
    }
}

/**
 * @brief Get the number of accessible levels to the user
 * @return      return number of accessible levels
 */
int User::getNumAccessibleLevels() {
    return levels.size();
}

/**
 * @brief Update meta before closing game to ensure that save state is saved for next time game is run.
 */
void User::updateMeta() {
    fstream savedData;
    savedData.open("Resources/Metadata/SavedUsers.txt", ios::out);
    if (!savedData) {
        cout << "Saved data was not found. Please ensure it's in the correct place.";
        mainWindow->close();
    }
    else {
        savedData << user << ": ";
        for (int i=0; i < levels.size(); ++i) {
            if (i == levels.size()-1) {
                savedData << levels[i] << "\n";
            }
            else {
                savedData << levels[i] << " ";
            }
        }
    }
}