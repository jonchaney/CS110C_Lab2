//
//  Wheel.h
//  lab2
//
//  Created by Jon Chaney on 9/21/15.
//  Copyright (c) 2015 Jon Chaney. All rights reserved.
//

#ifndef __lab2__Wheel__
#define __lab2__Wheel__

#include <iostream>
using namespace std;

class SpinningWheel
{
private:
        static const int NUM_VALUES = 20;
        int values[NUM_VALUES];    // array to store spinning wheel values
        int index;
        int getRand(int floor, int ceiling); // helper function
public:
        // default constructor
        SpinningWheel();
        // advances wheel a random number of positions (a random number from 22 10 42),
        // displaying the value at each position as the wheel spins, and returning the
        // value of the wheel when it has stopped
        int spin();
        // debug function to test constructor
        void print();
};


#endif /* defined(__lab2__Wheel__) */
