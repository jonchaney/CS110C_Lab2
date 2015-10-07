//
//  main.cpp
//  lab2
//
//  Created by Jon Chaney on 9/21/15.
//  Copyright (c) 2015 Jon Chaney. All rights reserved.
//

#include <iostream>
#include <cctype>     // for function tolower
#include "Player.h"
#include "SpinningWheel.h"
using namespace std;

// function prototypes
bool spinAgain();
char playGame();


int main() {
  
  cout << "Game Show";
  char choice; // continue gameplay
  
  do
  {
    choice = playGame();
  } while(tolower(choice) == 'y');
  
  cout << "Thanks for playing!";
  
    return 0;
}
// play game
// pre: none
// post: return decision to play again
char playGame()
{
  const int NUM_PLAYERS = 3;   // number of players
  Player players[NUM_PLAYERS]; // array of players
  char choice;                 // continue gameplay
  SpinningWheel gamewheel;
  
  // spin wheel for each player
  for(int i = 0;i < NUM_PLAYERS;i++)
  {
    cout << "\nPlayer " << i+1 << endl;
    
    cout << "First Spin: \t";
    players[i].spin(gamewheel);
    cout << "\nPoints so far:  " << players[i].totalPoints();
  
    // skip for third player if first two players go over 100
    if(players[0].totalPoints() > 100 && players[1].totalPoints() > 100);
    
    else if(spinAgain())
    {
      cout << "Second Spin: \t";
      players[i].spin(gamewheel);
      // test if total points is over 100
      if(players[i].totalPoints() > 100)
      {
        cout << "\nTotal Points: Over 100";
        
      }
      else
        cout << "\nTotal Points:  " << players[i].totalPoints();
    }
  }
  
  // pick game winner
  int winner = 0;
  int max = players[0].totalPoints();    // first player gets max value
  // find which player has the most points
  for(int i = 1; i < NUM_PLAYERS; i++)
   {
     if(players[i].totalPoints() > max)
     {
       max = players[i].totalPoints();
     }
   }
  
  cout << "\nPlayer " << winner << " wins!\n";
  
  do
  {
    cout << "Would you like to play again? (y/n): ";
    cin >> choice;
  } while(tolower(choice) != 'y' && tolower(choice) != 'n');
  
  return tolower(choice);
}
// check if player would like to spin again
// pre: none
// post: true or false
bool spinAgain()
{
  char choice;
  bool status = false;
  
  do
  {
    cout << "\nSpin again (y/n)? ";
    cin >> choice;
  } while (tolower(choice) != 'n' && tolower(choice) != 'y');
  
  if(tolower(choice) == 'y')
    status = true;
  
  return status;
}

