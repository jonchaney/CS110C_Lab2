//
//  main.cpp
//  lab2
//
//  Created by Jon Chaney on 9/21/15.
//
//  This program is a three player game of chance. Two chances to spin the wheel and stay beneath 100.
//  The player with the highest score wins!

#include <iostream>
#include <cctype>     // tolower()
#include "Player.h"
#include "SpinningWheel.h"
using namespace std;

// function prototypes
bool spinAgain();
char playGame();

int main() {
  
  cout << "Game Show";
  char choice;    // continue gameplay
  
  // play game
  do
  {
    choice = playGame();
  } while(tolower(choice) == 'y');
  
  cout << "Thanks for playing!";
  
    return 0;
}
// playGame() : character
// This function is the spinning wheel game
// pre: none
// post: return decision to play again
char playGame()
{
  const int NUM_PLAYERS = 3;   // number of players
  Player players[NUM_PLAYERS]; // array of players
  char choice;                 // continue gameplay
  SpinningWheel gamewheel;     // creates SpinningWheel object
  bool playerThree = false;    // check if player three wins early
  
  // spin wheel for each player
  for(int i = 0; i < NUM_PLAYERS; i++)
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
      i++;
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
            cout << "\nTotal Points: Over 100\n";
          else
            cout << "\nTotal Points:   " << players[i].totalPoints() << endl;
        }
      }
  } // end for
  
  // if player three did not win already, find winner/s
  if(!playerThree)
  {
    int max = 0;  // highest score
    
    // find highest score
    for(int i = 0; i < NUM_PLAYERS; i++)
    {
      if(players[i].totalPoints() <= 100 && max < players[i].totalPoints())
      {
        max = players[i].totalPoints();
      }
    }
    
    // find winner
    if (max == players[0].totalPoints() && max == players[1].totalPoints() && max == players[2].totalPoints())
      cout << "\nEveryone wins!";
    else if (max == players[0].totalPoints() && max == players[1].totalPoints() && max != players[2].totalPoints())
      cout << "\nPlayer 1 and 2 win!";
    else if (max != players[0].totalPoints() && max == players[1].totalPoints() && max == players[2].totalPoints())
      cout << "\nPlayer 2 and 3 win!";
    else if (max == players[0].totalPoints() && max != players[1].totalPoints() && max == players[2].totalPoints())
      cout << "\nPlayer 1 and 3 win!";
    else if (max == players[0].totalPoints() && max != players[1].totalPoints() && max != players[2].totalPoints())
      cout << "\nPlayer 1 wins!";
    else if (max != players[0].totalPoints() && max == players[1].totalPoints() && max != players[2].totalPoints())
      cout << "\nPlayer 2 wins!";
    else if (max != players[0].totalPoints() && max != players[1].totalPoints() && max == players[2].totalPoints())
      cout << "\nPlayer 3 wins!";
  }
  
  // ask player if they want to play again
  do
  {
    cout << "\nPlay again? (y/n): ";
    cin >> choice;
  } while(tolower(choice) != 'y' && tolower(choice) != 'n');
  
  return tolower(choice);
}
// spinAgain() : boolean
// This function asks the player if they would like to spin again
// pre:  none
// post: return true or false
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