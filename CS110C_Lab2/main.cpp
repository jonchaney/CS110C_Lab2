//
//  main.cpp
//  lab2
//
//  Created by Jon Chaney on 9/21/15.
//  Copyright (c) 2015 Jon Chaney. All rights reserved.
//

#include <iostream>
#include <cctype>     // for tolower()
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
  bool playerThree = false;    // check if player three wins early
  
  // spin wheel for each player
  for(int i = 0;i < NUM_PLAYERS;i++)
  {
    cout << "\nPlayer " << i+1 << endl;
    
    cout << "First Spin: \t";
    players[i].spin(gamewheel);
    cout << "\nPoints so far:  " << players[i].totalPoints();
  
    // if first two players are over 100 the third player does not spin a second time and wins
    if(players[0].totalPoints() > 100 && players[1].totalPoints() > 100)
    {
      playerThree = true;
      cout << "\nPlayer 3 wins!";
    }
    // if current player is less than or equal to 100 they can choose to spin again
    else if(players[i].totalPoints() < 100)
    {
        if(spinAgain())
        {
          cout << "Second Spin: \t";
          players[i].spin(gamewheel);
          // test if total points is over 100
          if(players[i].totalPoints() > 100)
          {
            cout << "\nTotal Points: Over 100\n";
          }
          else
            cout << "\nTotal Points:  " << players[i].totalPoints() << endl;
        }
      }
  } // end for
  
  // if player three did not win already, check for tie and find winner
  if(!playerThree)
  {
    int winner = 0;         // highest score
    int winnerIndex = 0;    // winner of game
    if(players[0].totalPoints() == players[1].totalPoints() && players[0].totalPoints() == players[2].totalPoints())
      cout << "Everyone wins!";
    else if(players[0].totalPoints() == players[1].totalPoints())
      cout << "Player 1 and 2 win!";
    else if(players[0].totalPoints() == players[2].totalPoints())
      cout << "Player 1 and 3 win!";
    else if(players[1].totalPoints() == players[2].totalPoints())
      cout << "Player 2 and 3 win!";
    else
    {
      // find which player has the most points
      for(int i = 0; i < NUM_PLAYERS; i++)
      {
        if(players[i].totalPoints() <= 100 && winner < players[i].totalPoints())
        {
          winner = players[i].totalPoints();
          winnerIndex = i;
        }
      }
     cout << "\nPlayer " << winnerIndex+1 << " wins!";
    }
  }
  
  do
  {
    cout << "\nPlay again? (y/n): ";
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