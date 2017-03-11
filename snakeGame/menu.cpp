#include "menu.h"
#include "snake.h"

using namespace std;

menuclass::menuclass()
{
        initscr();
        nodelay(stdscr,true); //if none key pressed don't wait for keypress
        keypad(stdscr,true);  //init the keyboard
        noecho();             //don't write
        curs_set(0);          //cursor invisible
        getmaxyx(stdscr,maxheight,maxwidth);
        del=110000;
        get=0;
        input=' ';
        title();        // Prints the title
        mainInstruction();  //Print the instruction
}//End menuclass()

menuclass::~menuclass()
{
        nodelay(stdscr,false);     //turn back
        getch();                   //wait until a key is pressed
        endwin();
}//End ~menuclass()

void menuclass::menu()
{
        int tmp=getch();
        while(1){
                if(input == 'e'){
                        clear();
                        snakeclass s;        //snakeclass
                        s.start(1, 0);           //Start snakeclass
                        break;
                }
                if (input == 'q'){
                        endwin();
                        exit(0);
                        break;
                }
                if(input == 'r'){
                        clear();
                        readInstruction();
                        break;
                }
                getInput();
                usleep(del);
        } // End while loop
} // End void menu() function


void menuclass::getInput()
{
        //detect key
        int tmp=getch();
        switch(tmp)
        {
                case 'e':
                        input='e';
                        break;
                case 'q':
                        input='q';
                        break;
                case 'r':
                        input='r';
                        break;
        } //End switch statement
} // End void getInput() function

void menuclass::title()
{
        move(maxheight/2-10,maxwidth/2-39);
        printw("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        move(maxheight/2-9,maxwidth/2-39);
        printw("@                                                                     @");
        move(maxheight/2-8,maxwidth/2-39);
        printw("@      ******   *     *      *     *  *  *****      *         *       @");
        move(maxheight/2-7,maxwidth/2-39);
        printw("@     *         * *   *     * *    * *   *          *         *       @");
        move(maxheight/2-6,maxwidth/2-39);
        printw("@      ******   *  *  *    *   *   **    ****    *******   *******    @");
        move(maxheight/2-5,maxwidth/2-39);
        printw("@            *  *   * *   *******  * *   *          *         *       @");
        move(maxheight/2-4,maxwidth/2-39);
        printw("@      ******   *     *  *       * *  *  *****      *         *       @");
        move(maxheight/2-3,maxwidth/2-39);
        printw("@                                                                     @");
        move(maxheight/2-2,maxwidth/2-39);
        printw("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        refresh();
} //End title()

void menuclass::mainInstruction()
{
        move(maxheight/2+2, maxwidth/2-30);
        printw("       KEYPRESS              FUNCTIONS               ");
        move(maxheight/2+3, maxwidth/2-30);
        printw("-----------------------------------------------------");
        move(maxheight/2+4,maxwidth/2-30);
        printw("         <e>                 To start the game!      ");
        move(maxheight/2+5,maxwidth/2-30);
        printw("         <r>                 Read game rules!        ");
        move(maxheight/2+6,maxwidth/2-30);
        printw("         <q>                 Exit                    ");
        refresh();
} // End mainInstruction()



void menuclass::readInstruction()
{
        move(maxheight/2-10, maxwidth/2-39);
        printw("***********************************************************************");
        move(maxheight/2-9, maxwidth/2-39);
        printw("*                                                                     *");
        move(maxheight/2-8,maxwidth/2-39);
        printw("* WELCOME to the SNAKE++ game! READ carefully about the rules!        *");
        move(maxheight/2-7,maxwidth/2-39);
        printw("*                                                                     *");
        move(maxheight/2-6,maxwidth/2-39);
        printw("***********************************************************************");
        move(maxheight/2-4,maxwidth/2-39);
        printw("**************************** RULES ************************************");
        move(maxheight/2-3,maxwidth/2-39);
        printw("*                                                                     *");
        move(maxheight/2-2,maxwidth/2-39);
        printw("* 1. Don't run the snake into the wall, or his own tail: you die.     *");
        move(maxheight/2-1,maxwidth/2-39);
        printw("* 2. Use your cursor keys: up, left, right, and down.                 *");
        move(maxheight/2,maxwidth/2-39);
        printw("* 3. Eat the food, try to score as high as you can.                   *");
        move(maxheight/2+1,maxwidth/2-39);
        printw("* 4. Enjoy the game, and be the best player.                          *");
        move(maxheight/2+2,maxwidth/2-39);
        printw("*                                                                     *");
        move(maxheight/2+3,maxwidth/2-39);
        printw("***********************************************************************");

        move(maxheight/2+5,maxwidth/2-39);
        printw(" SELECT (e) to play, (q) to quit, (b) to check the highest score       ");

} //End instruction()

