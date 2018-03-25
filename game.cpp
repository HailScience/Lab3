/*********************************************************************
** Program name: game.cpp
** Author: Alexandra Carper
** Date: 01/26/2018
** Description: The Game class controls the bulk of the game. First,
 *              it displays a menu which asks the player if they want
 *              to play the game or exit. If the player chooses to
 *              play, the game continues by asking the user for the
 *              number of rounds, whether each player is playing with
 *              a loaded die or a regular die, and how many sides
 *              there are on each die. The play function then rolls
 *              the dice for each round and stores the results in a
 *              2d array. The display roll results function displays
 *              the side and type of the die for each player, the
 *              number each player rolls, and the score result of
 *              each round.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

Game::Game()
{
    die1 = die2 = NULL;
}
/***********************************************************************
 * Description: Menu function that asks the user if they want to play
 *              the game or quit. Proceeds by asking for more details
 *              such as number of rounds, player 1 die type, player 1
 *              die sides, player 2 die type, and player 2 die sides.
 **********************************************************************/
void Game::menu()
{
    int choice;
    char loaded_die;
    int sides;

    //Display menu
    cout << "Welcome! Would you like to play War, or quit?\n";
    cout << "1. Play game\n";
    cout << "2. Exit game\n";

    bool validData = false;         //For input validation
    bool validData2 = false;        //For input validation

    while (!validData)
    {
        //Input choice
        cin >> choice;

        //If wrong input type
        if(cin.fail())
        {
            cout << "Error! Please enter '1' or '2'." << endl;
            //Clear stream
            cin.clear();
            //Skip newline character
            cin.ignore();
        }
        //If input is wrong number
        else if(choice != 1 && choice != 2)
        {
            cout << "Error! Please enter '1' or '2'." << endl;
            //Clear stream
            cin.clear();
            //Skip newline character
            cin.ignore();
        }
            //If user chooses to quit
        else if(choice == 2)
        {
            validData = true;
            cout << "Goodbye" << endl;
        }
        //If user chooses to play
        else if (choice == 1)
        {
            //Prompt for rounds
            cout << "How many rounds would you like to play?" << endl;
            while(!validData)
            {
                cin >> rounds;
                //If wrong type
                if (cin.fail())
                {
                    cout << "Error! Please enter an integer." << endl;
                    //Clear stream
                    cin.clear();
                    //Skip newline character
                    cin.ignore();
                }
                else
                {
                    //Don't return through loop
                    validData = true;
                }
            }

            cout << "Please enter the type of die and side of dice for both players." << endl;
            cout << endl;

            validData = false;

            //Player 1 details
            cout << "Will Player 1 play with loaded die? (Y/N)" << endl;
            while (!validData)
            {
                cin >> loaded_die;

                //If wrong type
                if (cin.fail())
                {
                    cout << "Error! Please enter 'Y' or 'N'." << endl;
                    //Clear stream
                    cin.clear();
                    //Skip newline character
                    cin.ignore();
                }
                //If wrong character
                else if (loaded_die != 'Y' && loaded_die != 'y' && loaded_die != 'N' && loaded_die != 'n')
                {
                    cout << "Error! Please enter 'Y' or 'N'." << endl;
                    //Clear stream
                    cin.clear();
                    //Skip newline character
                    cin.ignore();
                }

                //If user chooses not to use loaded die for player 1
                else if (loaded_die == 'n' || loaded_die == 'N')
                {
                    cout << "How many sides do you want the die to have?" << endl;
                    while(!validData2)
                    {
                        cin >> sides;
                        if (cin.fail())
                        {
                            cout << "Error! Please enter an integer." << endl;
                            //Clear stream
                            cin.clear();
                            //Skip newline character
                            cin.ignore();
                        }
                        else
                        {
                            //Don't return through loop
                            validData2 = true;
                        }
                    }
                    //Create new Die object
                    die1 = new Die(sides);
                    validData = true;
                }

                //If user chooses to use loaded die for player 1
                else if (loaded_die == 'y' || loaded_die == 'Y')
                {
                    cout << "How many sides do you want the die to have?" << endl;
                    while(!validData2)
                    {
                        cin >> sides;
                        if(cin.fail())
                        {
                            cout << "Error! Please enter an integer." << endl;
                            //Clear stream
                            cin.clear();
                            //Skip newline character
                            cin.ignore();
                        }
                        else
                        {
                            //Don't return through loop
                            validData2 = true;
                        }
                    }
                    //Create new LoadedDie object
                    die1 = new LoadedDie(sides);
                    validData = true;
                }
            }
            //Set back to false for player 2
            validData = false;
            validData2 = false;

            //Player 2
            cout << "Will Player 2 play with loaded die? (Y/N)" << endl;
            while (!validData)
            {
                cin >> loaded_die;

                //If wrong type
                if (cin.fail())
                {
                    cout << "Error! Please enter 'Y' or 'N'." << endl;
                    //Clear stream
                    cin.clear();
                    //Skip newline character
                    cin.ignore();
                }
                //If wrong character
                else if (loaded_die != 'Y' && loaded_die != 'y' && loaded_die != 'N' && loaded_die != 'n')
                {
                    cout << "Error! Please enter 'Y' or 'N'." << endl;
                    //Clear stream
                    cin.clear();
                    //Skip newline character
                    cin.ignore();
                }

                //If user chooses not to use loaded die for player 2
                else if (loaded_die == 'n' || loaded_die == 'N')
                {
                    cout << "How many sides do you want the die to have?" << endl;
                    while(!validData2)
                    {
                        cin >> sides;
                        //Validate input
                        if(cin.fail())
                        {
                            cout << "Error! Please enter an integer." << endl;
                            //Clear stream
                            cin.clear();
                            //Skip newline character
                            cin.ignore();
                        }
                        else
                        {
                            //Don't return through loop
                            validData2 = true;
                        }
                    }
                    //Create new Die object
                    die2 = new Die(sides);
                    validData = true;
                }

                //If user chooses to use loaded die for player 2
                else if (loaded_die == 'y' || loaded_die == 'Y')
                {
                    cout << "How many sides do you want the die to have?" << endl;
                    while(!validData2)
                    {
                        cin >> sides;
                        //Validate input
                        if (cin.fail())
                        {
                            cout << "Error! Please enter an integer." << endl;
                            //Clear stream
                            cin.clear();
                            //Skip newline character
                            cin.ignore();
                        }
                        else
                        {
                            validData2 = true;
                        }
                    }
                    //Create new LoadedDie object
                    die2 = new LoadedDie(sides);
                    //Don't return through loop
                    validData = true;
                }
            }
        }
    }
}

/*********************************************************************
 * Description: Play game function calls on roll function to roll the
 *              dice and store each roll in an array. Both display
 *              results functions pull from array to determine score
 *              and winner.
*********************************************************************/
void Game::play_game()
{
    for(int i = 0; i < rounds; i++)
    {
        rolls[i][0] = die1->roll();     //player 1 rolls
        rolls[i][1] = die2->roll();     //player 2 rolls
    }
}

/*********************************************************************
 * Description: Display roll results function displays the number of
 *              sides and type of die for each player, number each
 *              player rolls, and score result for each roll. Displays
 *              end results at the end of the game.
*********************************************************************/
void Game::displayRollResults()
{
    //Initialize points at zero
    int points_p1 = 0;
    int points_p2 = 0;

    //For each round, display type of die, what each player rolled
    //and increment points
    for (int i = 0; i < rounds; i++)
    {
        cout << "Player 1 is using a " << die1->getType() << " with " << die1->getSides() << " sides." << endl;
        cout << "Player 2 is using a " << die2->getType() << " with " << die2->getSides() << " sides." << endl;
        cout << "Player 1 \t Player 2 \t" << endl;
        cout << "    " << rolls[i][0] << "                " << rolls[i][1] << endl;

        if (rolls[i][0] > rolls[i][1])
        {
            points_p1++;
        }
        else if (rolls[i][0] < rolls[i][1])
        {
            points_p2++;
        }

        cout << "Player 1 points: " << points_p1 << endl;
        cout << "Player 2 points: " << points_p2 << endl;

    }
    //Display how many times each player won
    cout << "Player 1 has won " << points_p1 << " times!" << endl;
    cout << "Player 2 has won " << points_p2 << " times!" << endl;

    //Display winner
    if (points_p1 > points_p2)
    {
        cout << "Player 1 wins!" << endl;
    }
    else if (points_p1 < points_p2)
    {
        cout << "Player 2 wins!" << endl;
    }
    else
    {
        cout << "Draw!" << endl;
    }
}

/*********************************************************************
 * Description: Destructor deletes the allocated memory for the
 *              class objects to prevent memory leaks.
*********************************************************************/
Game::~Game()
{
    delete die1;
    delete die2;
}