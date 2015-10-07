//
//  Wheel.cpp
//  lab2
//
//  Created by Jon Chaney on 9/21/15.
//  Copyright (c) 2015 Jon Chaney. All rights reserved.
//

#include "SpinningWheel.h"
#include <iostream>
#include <ctime>

SpinningWheel::SpinningWheel() : index(0)
{
  srand(time(nullptr));    // seed random number
  
  // puts point values into array
  for(int i = 0, j = 5; i < NUM_VALUES; i++, j+=5)
  {
    values[i%NUM_VALUES] = j;
  }
  
  // randomizes array
  int randNum = 0;
  int temp = 0;
  for(int i = 0; i < NUM_VALUES; i++)
  {
    randNum = getRand(0,19);
    temp = values[i% NUM_VALUES];
    values[i% NUM_VALUES] = values[randNum% NUM_VALUES];
    values[randNum% NUM_VALUES] = temp;
  }
}

// advances the wheel a random number of positions (a random number from 22 to 42), displaying the value
// at each position as the wheel spins, and returning the value of the wheel when it has stopped spinning.
int SpinningWheel::spin()
{
  
  int randNum = getRand(22,42);   // get random number between 22 and 42
  int finalNum = 0;               // value that wheel ends on
  int count = 0;                  // create new line after 20 values printed
  
  while(index < randNum)
  {
    cout << values[index % NUM_VALUES] << " ";
    finalNum = values[index % NUM_VALUES];
    index++;
    count++;
    
    // print value in correct format
    if(count%20==0)
    {
      cout << endl;
      cout << "\t\t\t\t";
    }
  }
  index = index % NUM_VALUES; // update index
  
  return finalNum;
}
// helper function to get random number between a range
int SpinningWheel::getRand(int floor, int ceiling)
{
  int randNum = 0;
  randNum = rand() % ceiling + floor;
  
  return randNum;
}
// test function
void SpinningWheel::print()
{
  for(int i = 0; i < NUM_VALUES; i++)
  {
    cout << values[i] << " ";
  }
}
