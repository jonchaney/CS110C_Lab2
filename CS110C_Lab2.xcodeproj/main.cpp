//
//  main.cpp
//  lab2
//
//  Created by Jon Chaney on 9/21/15.
//  Copyright (c) 2015 Jon Chaney. All rights reserved.
//

#include <iostream>
#include "Player.h"
#include "SpinningWheel.h"
using namespace std;

int main() {
  
  Player playerOne, playerTwo;
  SpinningWheel gameWheel;
  
  playerOne.spin(gameWheel);
  cout << endl << endl;
  playerTwo.spin(gameWheel);

    return 0;
}


