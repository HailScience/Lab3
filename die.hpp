/*********************************************************************
** Program name: die.hpp
** Author: Alexandra Carper
** Date: 01/26/2018
** Description: Die is the parent class for LoadedDie. The constructor
 *              takes the number of sides as a parameter and sets it
 *              equal to an int 'N', and it sets 'die_type' equal to
 *              'Regular Die'. The roll function rolls the die,
 *              generating a random number, which is then stored in an
 *              array. The getType function returns the die_type each
 *              player is using, and the getSides function returns the
 *              number of sides of each die for each player.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using std::string;

class Die
{
protected:
    int N;
    string die_type;
public:
    Die(int s)
    {
        N = s;
        die_type = "Regular Die";
    }
    virtual int roll()
    {
        return rand() % N + 1;
    }
    string getType()
    {
        return die_type;
    }
    int getSides()
    {
        return N;
    }
};

#endif