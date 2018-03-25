/*****************************************************
 * Description: This file declares and defines the
 *              LoadedDie class, which is a the
 *              derived class of the Die class. It
 *              inherits all the attributes of the
 *              Die class, but the die_type is set
 *              to "Loaded Die" and the roll function
 *              is modified so that there is a bias
 *              for the loaded die, making it roll
 *              a higher average than the regular die.
 ****************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include <iostream>
#include "die.hpp"

class LoadedDie : public Die
{
private:
    int bias;

public:
    LoadedDie(int s) : Die(s)
    {
        bias = 1;
        die_type = "Loaded Die";
    }
    int roll()
    {
        int value = bias == 1 ? N : Die::roll();
        bias = (bias + 1) % 2;
        return value;
    }

};

#endif