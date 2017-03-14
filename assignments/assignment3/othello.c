#include <stdio.h>
#include <stdlib.h>

#include "game.h"

int main(int argc, char **argv){

    struct Count c2;
    c2.current = BLACK;
    c2.result = 1;
    int AI;
    int board_size;
    int m,n, s;
    int arg;


    printf("Enter board size: ");
    fflush(stdout);
    scanf("%d",&board_size);

    if( board_size % 2 == 1){
        do{
            printf("Wrong input! Enter even numbers!!\n");
            fflush(stdout);
            scanf("%d",&board_size);
        } while(board_size % 2 == 1);
    } // End if

    GAME data;
    data.size = board_size;
    m = data.row;
    n = data.col;
    s = data.size;

    init(&data);
    //AI_move(&data);

    while(c2.result > 0){
        display(&data);
        if(c2.current == AI){
            c2.result = AI_move(&data);
        }
        else {
            if ( c2.current == BLACK ) {
              printf("\nBlack's turn。\n");
            }
            else {
              printf("\nWhite's turn。\n");
            }
            while ( 1 ) {
      				printf("-> Enter column, then row: ");
      				fflush(stdout);
      				if ( scanf("%d", &m)<0 || scanf("%d", &n)<0 ) {
        					printf("Invaild Input。\n");
        					printf("try again、");
        					continue;
      				}
      				c2.result = reverse(m, n, &data);
      				if ( c2.result == 0 ) {
      					printf("\n*** At point (%d, %d) ***\n Can't place a stone here。\n", m, n);
      					printf("*************************\n\n");
      				}
      				else {
      					break;
      			}
        }
    }
}

display(&data);
printf("\nResult: \n");
switch ( winner(&data) ) {
  case BLACK: printf("\n\n&&& Black won! &&&\n\n");
        break;
  case WHITE: printf("\n\n&&& White won!&&&\n\n");
        break;
  case NONE : printf("\n\nNo winner!\n\n");
        break;
}

finalize(&data);


    return 0;
} // End main

