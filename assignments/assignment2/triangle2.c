#include "triangle.h"
#include <stdlib.h> // malloc
#include <stdio.h>  // printf
#include <string.h> // memset

/* Allocate a triangle of height "height" (a 2-D array of int)*/
void allocateNumberTriangle(const int height, int ***triangle){
    int i;
    (*triangle) = (int **) malloc(height * sizeof(int*));
    for(i = 0; i < height; i++){
        (*triangle)[i] = (int *) malloc(height * sizeof(int));
    }
} // End of allocateNumberTriangle

/* Initialize the 2-D triangle array */
void initializeNumberTriangle(const int height, int **triangle){
    int i, j;
    for(i = 0; i < height; i++){
        for(j = 0; j < height; j++){
            triangle[j][i] = i;
        } // End nested for loop
    } // End for loop
} // End initializeNumberTriangle

/* Print a triangle of the specified height containing the digits 0 - 9 */
void printNumberTriangle(const int height, int **triangle){
    int i, j;
    int count = 0;
    int col = height * 2 - 1;
    int startPrint = (col -1) / 2;
    int leftSide = startPrint;
    int rightSide = startPrint;

    for(i = 0; i < height; ++i){
        for(j = 0; j < col; j++){
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
} // End void printNumberTriangle

/* Free the memory for the 2-D triangle array */
void deallocateNumberTriangle(const int height, int ***triangle){
    int i;
    for(i = 0; i < height; ++i){
        free(triangle[i]);
    } // End for loop
    free(triangle);
} // End deallocateNumberSquare

