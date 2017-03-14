#include "menu.h"

using namespace std;

menuclass::menuclass()
{
        clear();
        initscr();
        nodelay(stdscr,true); //if none key pressed don't wait for keypress
        keypad(stdscr,true);  //init the keyboard
        noecho();             //don't write
        curs_set(0);          //cursor invisible
        getmaxyx(stdscr,maxheight,maxwidth);

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

        submenuOpen = false;
        int tmp=getch();
        while(1){

                input = getch();

                if (submenuOpen == false)
                {
                        if(input == 'e'){
                                clear();
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
                                refresh();
                        }
                        if(input =='h'){
                                clear();
                                highScore();
                                refresh();
                        }
                }

                if (submenuOpen == true)
                {
                        if(input == 'b'){
                                clear();
                                title();
                                mainInstruction();
                                refresh();
                                submenuOpen = false;
                        }
                }
        } // End while loop

} // End void menu() function

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
        printw("         <e>                 Start                   ");
        move(maxheight/2+5,maxwidth/2-30);
        printw("         <r>                 Rules                   ");
        move(maxheight/2+6,maxwidth/2-30);
        printw("         <h>                 High Scores             ");
        move(maxheight/2+7,maxwidth/2-30);
        printw("         <q>                 Exit                    ");
        refresh();
} // End mainInstruction()



void menuclass::readInstruction()
{
        submenuOpen = true;
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
        printw("* 3. Eat the food, try to eat combo to score higher points            *");
        move(maxheight/2+1,maxwidth/2-39);
        printw("* 4. Enjoy the game!                                                  *");
        move(maxheight/2+2,maxwidth/2-39);
        printw("*                                                                     *");
        move(maxheight/2+3,maxwidth/2-39);
        printw("***********************************************************************");

        move(maxheight/2+5,maxwidth/2-39);
        printw("Press <b> to return to the main menu");

} //End instruction()

void menuclass::highScore()
{

        submenuOpen = true;
        highscores = h.load();

        // starting point for printing high score
        int startrow = (maxheight/2) - (h.numscores/2);
        int startcol = (maxwidth/2) - 5;

        move (startrow - 2, startcol);
        printw("High Scores: ");

        for (int i = 0; i < h.numscores; i++)
        {
                move(startrow + i,startcol);
				if (i < 9)
						printw(" ");
                printw("%d. ", i+1);
                if (i < highscores.size())
                        printw("%d - %s", highscores[i].score, highscores[i].name.c_str());

        }

        move(startrow + h.numscores+2, startcol-5);
        printw("Press <b> to return to the main menu");

}
