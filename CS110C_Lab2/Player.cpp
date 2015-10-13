//
//  Player.cpp
//  lab2
//
//  Created by Jon Chaney on 9/21/15.
//  Copyright (c) 2015 Jon Chaney. All rights reserved.
//

#include "Player.h" // header file
#include "SpinningWheel.h"

Player::Player() : points(0)
{
}

void Player::spin(SpinningWheel &gameWheel)
{
  points += gameWheel.spin();
}

int Player::totalPoints() const
{
  return points;
}

