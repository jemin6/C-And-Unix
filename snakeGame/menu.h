#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>

#ifndef MENU_H
#define MENU_H

class menuclass{
        int points,del;
        //indicates that the snake get food (it makes the snake longer)
        bool get;
        //indicates the current direction of the snake
        char input;
	bool instructionOpen;
        int maxwidth;
        int maxheight;
        char partchar;
        char oldalchar;
        char etel;
        void getInput();
        void title();
        void readInstruction();
        void mainInstruction();
public:
        menuclass();
        ~menuclass();
        void menu();
};

#endif

