# Group 14 - Platformer Game

## Getting Started

### Dependencies and Set-Up

This program requires downloading SFML 2.6.0 or later. Please click [here](https://www.sfml-dev.org/download/sfml/2.6.1/) and download your compatible version.

Currently our program has been tested on Windows and Intel-based Macs.

To run on an application CLion, copy and paste the following in your CMakeLists.txt to build and run the program properly.

#### For Windows:
```
cmake_minimum_required(VERSION 3.23)
project(Platformer)

set(CMAKE_CXX_STANDARD 14)
include_directories(../libraries)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "libraries/SFML-2.6.0/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)
add_executable(Platformer main.cpp Player.cpp Player.h Level.cpp Level.h Obstacle.cpp Obstacle.h Object.cpp Object.h Menu.cpp Menu.h Goal.cpp Goal.h Terrain.cpp Terrain.h Animate.cpp Animate.h Enemy.cpp Enemy.h Coin.cpp Coin.h Score.cpp Score.h User.cpp User.h)
target_link_libraries(Platformer sfml-graphics sfml-audio sfml-system sfml-window -static)
```

#### For Mac:
```
cmake_minimum_required(VERSION 3.23)
project(group14)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
include_directories(${SFML_INCLUDE_DIRS})

find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)
add_executable(
        group14
        main.cpp
        Player.h Player.cpp
        Level.h Level.cpp
        Menu.h Menu.cpp
        Obstacle.h Obstacle.cpp
        Object.h Object.cpp
        Goal.h Goal.cpp
        Terrain.h Terrain.cpp
        Animate.h Animate.cpp
        Enemy.h Enemy.cpp
        Score.h Score.cpp
        Coin.h Coin.cpp
        User.h User.cpp
)
target_link_libraries(group14 sfml-graphics sfml-audio sfml-system sfml-window)
```

To build this program properly in CLion, please ensure that the "Resources" directory is moved/copied into you "cmake-build-debug" directory to ensure that all textures are loaded in properly.

### Executing Program

To run the program, open the specific build folder and ensure it's in the main directory.
Open the executable and the game should run.

For mac we recommend the following:
* After opening the mac build folder and moving it into the main directory, go to the terminal.
* In the terminal, change directory to the directory with the executable.
* Run the executable with the following command:
```
./group14
```

## How to Play

Use 'A' and 'D' keys to move right and left. Use Space or 'W' key to jump. 

Avoid the fire and spiders, collect the coins, and move to the portal to complete the level.