//
//  Player.h
//  lab2
//
//  Created by Jon Chaney on 9/21/15.
//  Copyright (c) 2015 Jon Chaney. All rights reserved.
//

#ifndef __lab2__Player__
#define __lab2__Player__

#include <iostream>
#include "SpinningWheel.h"
using namespace std;

class Player
{
private:
        // total number of points for given player
        int points;
public:
        // default constructor intializes points to zero
        Player();
        // player spins wheel, total player points is updated
        void spin(SpinningWheel &gameWheel);
        // returns total number of points by player so far
        int totalPoints() const;
};

#endif /* defined(__lab2__Player__) */
