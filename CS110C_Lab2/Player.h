//
//  Player.h
//  lab2
//
//  Created by Jon Chaney on 9/21/15.

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
        // +spin(in gamewheel: SpinningWheel)
        // player spins wheel, total player points is updated
        // pre  : SpinningWheel
        // post : updates points with new total
        void spin(SpinningWheel &gameWheel);
        // +totalPoints() : integer {query}
        // returns total number of points by player so far
        // pre  : none
        // post : return total number of points
        int totalPoints() const;
};

#endif /* defined(__lab2__Player__) */
