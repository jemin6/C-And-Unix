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
        oldalchar=(char)219;
        del=110000;
        get=0;
        input=' ';
        move(maxheight/2-10,maxwidth/2-27);
	printw("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	move(maxheight/2-9,maxwidth/2-27);
	printw("@                                                   @");
	move(maxheight/2-8,maxwidth/2-27);
	printw("@      ******   *     *      *     *  *  *****      @");
	move(maxheight/2-7,maxwidth/2-27);
	printw("@     *         * *   *     * *    * *   *          @");
	move(maxheight/2-6,maxwidth/2-27);
	printw("@      ******   *  *  *    *   *   **    ****       @");
	move(maxheight/2-5,maxwidth/2-27);
	printw("@            *  *   * *   *******  * *   *          @");
	move(maxheight/2-4,maxwidth/2-27);
	printw("@      ******   *     *  *       * *  *  *****      @");
	move(maxheight/2-3,maxwidth/2-27);
	printw("@                                                   @");      
	move(maxheight/2-2,maxwidth/2-27);
	printw("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");

	move(maxheight/2+2, maxwidth/2-27);
	printw("       KEYPRESS              FUCTIONS                ");	
	move(maxheight/2+3, maxwidth/2-27);
	printw("-----------------------------------------------------");	
	move(maxheight/2+4,maxwidth/2-27);
	printw("         <e>                 To start the game!      ");
	move(maxheight/2+5,maxwidth/2-27);
	printw("         <r>                 Read game rules!        ");
	move(maxheight/2+6,maxwidth/2-27);
	printw("         <q>                 Exit	             "); 
	refresh();
}//End menuclass()

menuclass::~menuclass()
{
        nodelay(stdscr,false);     //turn back
        getch(); 	           //wait until a key is pressed
        endwin();
}//End ~menuclass()

void menuclass::menu()
{
	int tmp=getch();
	while(1){
		if(input == 'e'){
			clear();
			snakeclass s;        //snakeclass
			s.start();	     //Start snakeclass
			break;
		} //End if statement
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
	} //End switch statement
} // End void getInput() function 
