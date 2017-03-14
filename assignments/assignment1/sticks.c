#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int getUserChoice() {

     int playerOneStick = 0;

     printf("Player 1: How many sticks do you take (1-3)? ");
     fflush(stdout);
     scanf("%d", &playerOneStick);

     if(playerOneStick > 0 && playerOneStick < 4){
          return playerOneStick;
     } // End if statement
     else{
          do{
              printf("Wrong input, type again: \n");
              fflush(stdout);
              scanf("%d",&playerOneStick);
          } while(playerOneStick <= 0 || playerOneStick > 3);
     } // End else statement

} // End int getUserChoice()

int getComputerChoice(int current_sticks) {

    /* get a pseudo-random integer between 1 and 3 (inclusive) */
    int rand_choice = rand() % 3 + 1;

    if (rand_choice > current_sticks) return current_sticks;

    /* Optionally replace with additional logic for the computer's strategy */

    return rand_choice;
}


int main(int argc, char** argv)
{
    int user, computer, number_sticks;

    srand (time(NULL)); /* for reproducible results, you can call srand(1); */

    printf("Welcome to the game of sticks!\n");
    printf("How many sticks are there on the table initially (10-100)? ");
    fflush(stdout);
    scanf("%d", &number_sticks);

    /* TODO: check that num_sticks is between 10 and 100 (inclusive) and print
                    an error and exit, if it is not.
    */
    if(number_sticks > 9 && number_sticks < 101) {
        printf("\n\nThere are %d sticks on the board.\n",number_sticks);
    } // End if statement
    else {
        printf("\n\nError\n");
        exit(1);
    } // End else statement

    do{
          user = getUserChoice();
          number_sticks -= user;

          if(number_sticks <= 0){
              printf("You lose!\n");
              exit(1);
          } // End if statement

          printf("\nThere are %d sticks on the board.\n",number_sticks);
          computer = getComputerChoice(number_sticks);
          printf("Computer selects: %d\n", computer);
          number_sticks -= computer;

          if(number_sticks <= 0){
              printf("You win!\n");
              exit(1);
          } // End if statement

          printf("\nThere are %d sticks on the board.\n",number_sticks);


    } while(number_sticks > 0);

    return 0;
}
