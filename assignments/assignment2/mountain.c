#include "mountain.h"
#include "triangle.h"

#include <stdlib.h> // malloc
#include <stdio.h>  // printf
#include <string.h> // memset


void printNumberMountain(const int numPeaks, int *heights, int ***triangles){

}

int main(int argc, char * argv[]){
    int **triangle;

    int peakNum = 0;
    int height1, height2, height3, height4, height5 = 0;

    printf("Please enter the number of peaks [1-5]: ");
    fflush(stdout);
    scanf("%d", &peakNum);

    if(peakNum > 0 && peakNum < 6){
        printf("%d",peakNum);
    }
    else{
        do{
            printf("Please enter the number of peaks [1-5]: ");
            fflush(stdout);
            scanf("%d",&peakNum);
        } while(peakNum <= 0 || peakNum > 5);
    }
    printf("Please enter the heights of the peaks [each should be between 1 and 5]: ");
    switch (peakNum) {
        case 1:
            fflush(stdout);
            scanf("%d",&height1);
            printNumberTriangle(height1, (int**)triangle);
            break;
        case 2:
            fflush(stdout);
            scanf("%d %d",&height1, &height2);
            printNumberTriangle(height1, (int**)triangle);
            printNumberTriangle(height2, (int**)triangle);
            break;
        case 3:
            fflush(stdout);
            scanf("%d %d %d",&height1, &height2, &height3);
            printNumberTriangle(height1, (int**)triangle);
            printNumberTriangle(height2, (int**)triangle);
            printNumberTriangle(height3, (int**)triangle);
            break;
        case 4:
            fflush(stdout);
            scanf("%d %d %d %d",&height1, &height2, &height3, &height4);
            printNumberTriangle(height1, (int**)triangle);
            printNumberTriangle(height2, (int**)triangle);
            printNumberTriangle(height3, (int**)triangle);
            printNumberTriangle(height4, (int**)triangle);
            break;
        case 5:
            fflush(stdout);
            scanf("%d %d %d %d %d",&height1, &height2, &height3, &height4, &height5);
            printNumberTriangle(height1, (int**)triangle);
            printNumberTriangle(height2, (int**)triangle);
            printNumberTriangle(height3, (int**)triangle);
            printNumberTriangle(height4, (int**)triangle);
            printNumberTriangle(height5, (int**)triangle);
            break;
        default:
            printf("Try again\n");
    }

} // End main

