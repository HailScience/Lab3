/*********************************************************************
** Program name: main.cpp
** Author: Alexandra Carper
** Date: 01/28/2018
** Description: This main file simply creates a Game object and
 *              calls the menu, play_game, and displayRollResults
 *              function.
*********************************************************************/

#include <iostream>
#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"


int main()
{
    Game g;
    g.menu();
    g.play_game();
    g.displayRollResults();

    return 0;
}