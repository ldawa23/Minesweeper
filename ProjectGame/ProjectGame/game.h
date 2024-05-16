#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream> // for file handeling

using namespace sf;

class Game
{
public:
    Game();
    void run();

private:
    RenderWindow window; //used for rendering window in SFML
    int tileSize;
    int grid[12][12];
    int displayGrid[12][12];
    Texture t;
    Sprite s;

    // Function prototypes
    void initializeGrids();
    void setupGame();
    void handleEvents();
    void revealTile(int x, int y);
    void draw();
    void saveGame(const std::string& filename);//save game state
    void loadGame(const std::string& filename);//load game state
};

#endif // GAME_H

