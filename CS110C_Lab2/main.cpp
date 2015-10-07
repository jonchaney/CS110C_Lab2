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
void spinWheel(Player,SpinningWheel,int);
char playGame(Player[],SpinningWheel,const int);


int main() {
  
  const int NUM_PLAYERS = 3;   // number of players
  Player players[NUM_PLAYERS]; // array of players
  char choice;                 // continue gameplay
  SpinningWheel gamewheel;
  cout << "Game Show";
  
  do
  {
    choice = playGame(players,gamewheel,NUM_PLAYERS);
  } while(tolower(choice) == 'y');
  
  cout << "Thanks for playing!";
  
    return 0;
}
//
//
//
char playGame(Player players[],SpinningWheel gamewheel, const int length)
{
  char choice;    // continue gameplay
  
  // spin wheel for each player
  for(int i = 0;i < length;i++)
  {
    spinWheel(players[i],gamewheel,i+1);
  }
  
  // pick game winner
  
  do
  {
  cout << "\nWould you like to play again? (y/n): ";
  cin >> choice;
  } while(tolower(choice) != 'y' && tolower(choice) != 'n');
  
  return tolower(choice);
}
//
//
//
void spinWheel(Player player,SpinningWheel wheel,int num)
{
  cout << "\nPlayer " << num << endl;

  cout << "First Spin: \t";
  player.spin(wheel);
  cout << "\nPoints so far:  " << player.totalPoints();
  
  if(spinAgain())
  {
    cout << "Second Spin: \t";
    player.spin(wheel);
    // test if total points is over 100
    if(player.totalPoints() > 100)
    {
      cout << "\nTotal Points: Over 100";

    }
    else
      cout << "\nTotal Points:  " << player.totalPoints();
  }
}
//
//
//
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

