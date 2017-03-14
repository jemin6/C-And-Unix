/***********************************************************
University of Oregon 2017 Winter
CIS330 Assignment 2. Part 2.a
  - define a rectangular 2-D array of ints
    of fixed size containing single-digit values and print it.

01-25-2017
by Je Min Son.

*************************************************************/

#include "triangle.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    int **triangle;
    int height;

    printf("Problem 1 (a triangle of height 5):\n");
    print5Triangle();

    printf("\nProbelm 2:\nPlease enter the height of"
            " the triangle [1-5]: ");
    fflush(stdout);
    scanf("%d",&height);

    if(height > 0 && height < 6){
        
    }
    else{
        do{
            printf("Please enter the height of"
                    " the triangle [1-5]: ");
            fflush(stdout);
            scanf("%d",&height);
        } while(height <= 0 || height > 5);
    }


    printNumberTriangle(height, (int**) triangle);

    allocateNumberTriangle(height, &triangle);
    initializeNumberTriangle( height, triangle );

    // Free memory allocated earlier
    deallocateNumberTriangle( height, &triangle );


    return 0;
}

