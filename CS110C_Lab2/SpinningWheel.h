//
//  Wheel.h
//  lab2
//
//  Created by Jon Chaney on 9/21/15.

#ifndef __lab2__Wheel__
#define __lab2__Wheel__

#include <iostream>
using namespace std;

class SpinningWheel
{
private:
        static const int NUM_VALUES = 20;  // number of values on wheel
        int values[NUM_VALUES];            // spinning wheel values
        int index;                         // number the wheel stopped spinning on
public:
        // default constructor
        //  puts values into array and randomizes the order, initialize index to zero
        SpinningWheel();
        // +spin() : integer
        // advances wheel a random number from 22 to 42), displaying the value at each
        // position as the wheel spins, and returning the value of the wheel when it has stopped
        // pre:  none
        // post: none
        int spin();
};


#endif /* defined(__lab2__Wheel__) */
