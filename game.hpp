/*********************************************************************
** Program name: game.hpp
** Author: Alexandra Carper
** Date: 01/26/2018
** Description: This class declaration includes the variables for
 *              rounds, pointers to each player's die, and the array
 *              that contains the results for each roll. It also
 *              introduces the menu, play_game, and displayRollResults
 *              functions. Finally, it includes a destructor that
 *              deallocates the memory for the pointers.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "die.hpp"

using std::cin;
using std::cout;
using std::endl;

class Game
{
private:
    int rounds;
    Die *die1, *die2;
    int rolls[50][2];

public:
    Game();
    ~Game();
    void menu();
    void play_game();
    void displayRollResults();

};

#endif