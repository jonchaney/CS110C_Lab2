//
//  Player.cpp
//  lab2
//
//  Created by Jon Chaney on 9/21/15.

#include "Player.h"
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

