//
//  Wheel.cpp
//  lab2
//
//  Created by Jon Chaney on 9/21/15.

#include "SpinningWheel.h"
#include <iostream>
#include <ctime>

SpinningWheel::SpinningWheel() : index(0)
{
  // seed random number
  srand(unsigned(time(nullptr)));
  
  // put point values into array
  for(int i = 0, j = 5; i < NUM_VALUES; i++, j+=5)
  {
    values[(i+1)%NUM_VALUES] = j;
  }
  
  // randomizes array
  int randNum = 0;
  int temp = 0;
  for(int i = 0; i < NUM_VALUES; i++)
  {
    // get random number between 0 and 19
    randNum = rand() % 20;
    // swap values
    temp = values[(i + 1) % NUM_VALUES];
    values[(i + 1) % NUM_VALUES] = values[randNum % NUM_VALUES];
    values[randNum % NUM_VALUES] = temp;
  }
}

int SpinningWheel::spin()
{
  
  int randNum = 22 + rand() % (42 - 22);    // get random number between 22 and 42
  int finalNum = 0;                         // value that wheel ends on
  int count = 1;                            // count for formatting
  
  // print gamewheel values
  for(int i = 0; i < randNum; i++)
  {
    cout << values[(index + 1) % NUM_VALUES] << " ";
    // after printing 20 values, end line and indent
    if(count % NUM_VALUES == 0)
    {
      cout << endl;
      cout << "\t\t\t\t";
    }
    count++;
    index++;
  }
  
  finalNum = values[index % NUM_VALUES];
  
  return finalNum;
}





