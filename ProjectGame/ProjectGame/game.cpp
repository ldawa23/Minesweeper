#include "Game.h"

Game::Game()
{
    window.create(sf::VideoMode(400, 400), "Welcome to MineSweeper");
    tileSize = 32;

    srand(time(nullptr)); // generates random number in boxes
    t.loadFromFile("images/tiles.jpg");// loads texture for tiles
    s.setTexture(t);

    initializeGrids(); // initializes the game grids
    setupGame(); //setup game with numbers and bombs
}

void Game::run()
{
    while (window.isOpen())
    {
        handleEvents();//handles user input
        draw();//draws game graphics
    }
}

void Game::initializeGrids()
{
    //Initialize displaygrid and grid
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            displayGrid[i][j] = 10;
            grid[i][j] = 0;
        }
    }
}

void Game::setupGame()
{
    //Place bombs randomly on grid and calculate numbers
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (rand() % 5 == 0) //1/5 chance for each tile to be bomb
            {
                grid[i][j] = 9;
            }
        }
    }

    //calculates number for non bomb 
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (grid[i][j] != 9) //not a bomb will run this code
            {
                int count = 0;
                
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (grid[i + x][j + y] == 9)
                        {
                            count++;
                        }
                    }
                }
                grid[i][j] = count;//tile number will set here
            }
        }
    }
}

void Game::handleEvents()
{
    sf::Event e;
    while (window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
        {
            window.close(); //close window
        }
        if (e.type == sf::Event::MouseButtonPressed)
        {
            revealTile(e.mouseButton.x / tileSize, e.mouseButton.y / tileSize);//Reveals tile when mouse is clicked
        }
        if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::S)
        {
            saveGame("savegame.txt");//Saves the game state when pressed S
        }
        if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::L)
        {
            loadGame("savegame.txt");//Loads the game state when pressed L
        }
    }
}

void Game::revealTile(int x, int y)
{
    if (grid[x][y] == 9) // Check if the revealed tile is a bomb
    {
        // If the revealed tile is a bomb, reveal all bomb tiles
        for (int i = 1; i <= 10; i++)
        {
           for (int j = 1; j <= 10; j++)
           {
              if (grid[i][j] == 9)
              {
                 displayGrid[i][j] = 9;
              }
           }
        }
        // Redraw the game to display the updated grid
        draw();

        //close game window
        window.close();
    }
    else
    {
       displayGrid[x][y] = grid[x][y]; //reveal the tile and display the grid
    }
}

void Game::draw()
{
    window.clear(sf::Color::White); // clears the window with white color

    //draw tiles based on displayGrid
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            s.setTextureRect(sf::IntRect(displayGrid[i][j] * tileSize, 0, tileSize, tileSize));//set rectangle textures
            s.setPosition(i * tileSize, j * tileSize);//set position of sprite
            window.draw(s);//Draws sprite
        }
    }
    window.display();//displays the draw content
}

void Game::saveGame(const std::string& filename)
{
    std::ofstream file(filename);//opens a file for writing
    if (file.is_open())
    {
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                file << displayGrid[i][j] << " ";
            }
            file << "\n";
        }
        file.close();//file will close here
    }
}

void Game::loadGame(const std::string& filename)
{
    std::ifstream file(filename);//opens a file for reading
    if (file.is_open())
    {
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                file >> displayGrid[i][j];
            }
        }
        file.close();//file will close here
    }
}
