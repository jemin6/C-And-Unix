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
        move(maxheight/2,maxwidth/2-12);
	printw("Hello, Welcome to the snake game!");
        move(maxheight/2+2,maxwidth/2-12);
        printw("Press <Enter> to start the game!");
	refresh();
}

menuclass::~menuclass()
{
        nodelay(stdscr,false);     //turn back
        getch(); 	           //wait until a key is pressed
        endwin();
}

void menuclass::menu()
{
	int tmp=getch();
	while(1){
		if(input == 'e'){
			clear();
			snakeclass s;
			s.start();
			break;
		}
		getinput();
		usleep(del);
	}
	
}


void menuclass::getinput()
{
	//detect key
	int tmp=getch();
	switch(tmp)
	{
		case 'e':
			input='e';
			break;
	} //End switch statement
}
