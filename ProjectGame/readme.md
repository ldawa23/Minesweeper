Minesweeper Game Using SFML

This is a simple basic minesweeper game I created using SFML (Simple and Fast Multimedia Library). So, this game acts as the old Minesweeper game with similar rules where the user must find all numbers tiles without clicking on any bomb.

Instruction on How to install and import SFML library in Visual Studio 2022

•	Download the SFML library from https://www.sfml-dev.org/download/sfml/2.6.1/ .
•	Extract the downloaded zip file.
•	Create a new project in Visual Studio 2022.
•	In your project folder, create a folder named ‘SFML’.
•	Copy the ‘bin’, ‘include’ and ‘lib’ folders from the SFML library folder into ‘SFML’ folder.
•	In your visual studio 2022, open your project properties by right clicking in your project.
•	Go to Linker > Additional library Directories and add path to the SFML ‘lib’ folder.
•	Go to Linker > Input > Additional Dependencies and add these files (sfml-system-d.lib, sfml-graphics-d.lib, sfml-audio-d.lib, sfml-network-d.lib, sfml-window-d.lib).
•	Go to C/C++ > Additional Include Directories and add the path to the SFML ‘include’ folder.

Usage in this game

•	Left click will reveal a tile.
•	The number on revealed tile will indicate the number of adjacent bombs.
•	Without clicking on the bombs if you uncover all the number tiles you will win the game.
•	If you reveal a bomb, the game will reveal all the bomb’s location and closes the window.
•	Press ‘S’ to save the game state, and ‘L’ to load a saved game.

Features in this game

•	Based on grid gameplay.
•	Reveals tile mechanics.
•	Game state management (game over, success).
