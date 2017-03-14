#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include "highscore.h"
#include "snake.h"

#ifndef MENU_H
#define MENU_H


class menuclass{

        snakeclass s;
        char input;
        bool submenuOpen;
        int maxwidth;
        int maxheight;

        highscore h;
        std::vector<scores> highscores;

        void title();
        void readInstruction();
        void mainInstruction();
        void highScore();
public:
        menuclass();
        ~menuclass();
        void menu();
};

#endif

