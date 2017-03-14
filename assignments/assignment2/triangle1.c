/***********************************************************
University of Oregon 2017 Winter
CIS330 Assignment 2. Part 2.a
  - define a rectangular 2-D array of ints
    of fixed size containing single-digit values and print it.

01-25-2017
by Je Min Son.

*************************************************************/

#include "triangle.h"
#include <stdlib.h> // malloc
#include <stdio.h>  // printf
#include <string.h> // memset

#define ROW 5
#define COL 9
/* Function implementation */
/* Print a triangle of height 5 */
void print5Triangle() {
  int i, j;
  int count = 0;
  int startPrint = (COL -1) / 2;
  int leftSide = startPrint;
  int rightSide = startPrint;

  for(i = 0; i < ROW; ++i){
      for(j = 0; j < COL; j++){
          if(j < leftSide || j > rightSide){
              printf("  ");
          } // End if statement
          else{
              printf("%d ", count);
              count++;
          } // End else statement
      } // End nested for loop
      count = 0;
      leftSide--;
      rightSide++;
      printf("\n");
  } // End for loop
} // End void print5Triangle

