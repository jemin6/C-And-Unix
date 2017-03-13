#include "snake.h"
using namespace std;
snakepart::snakepart(int col,int row)
{
        x = col;
        y = row;
} //End snakepart()

snakepart::snakepart()
{
        x = 0;
        y = 0;
} //End snakepart()

food::food()
{
        x = 0;
        y = 0;
        i = 0;

        // these are the basic food types
        charpool[0] = '*';
        charpool[1] = 'O';
        charpool[2] = '&';

        // this is the poison
        charpool[3] = (char)219;
        character = charpool[1];
} //End fodd()

snakeclass::snakeclass()
{
        initscr();
        nodelay(stdscr,true);                   //if there wasn't any key pressed don't wait for keypress
        keypad(stdscr,true);                    //init the keyboard
        noecho();                                                                       //don't write
        curs_set(0);                                                    //cursor invisible
        getmaxyx(stdscr,termheight,termwidth);
        partchar='x';
        oldalchar=(char)219;                            // border character
        etel='*';

        // initialze poison
        poison.i=2;
        poison.character = poison.charpool[3];

        // initial values
        levelpoints = 500; // amount of points required to reach the next level
        combo = 1;
        points=0;
        level = 0;
        del=110000;
        get=0;
        direction='l';
        input = ' ';
        pauser = ' ';
        speedctrl = ' ';
        srand(time(NULL));

        // default size for the game window (within the larger terminal window)
        width = 80;
        height = 30;
} //End snakeclass()

snakeclass::~snakeclass()
{
        nodelay(stdscr,false);                  //turn back
        getch();                                //wait until a key is pressed
        endwin();
} //End ~snakeclass()

// checks conditions of leveling up;
bool snakeclass::levelcheck()
{
        if (points >= levelpoints)
        {
                clear();

                move((minheight+maxheight)/2, (minwidth+maxwidth)/2 - 24);
                printw("Level %d complete! Press 'y' to go to next level", level);
                placeboard();
                refresh();

                while (1){
                        usleep(del);
                        getkey();
                        if (input == 'y')
                        {
                                clear();
                                snakeclass s;
                                s.start(level+1,overallscore);
                                break;
                        } // End nested nested if statement
                } // End nested while loop 
                return true;
        } // End if statement
        else
                return false;
} // End levelcheck()

void snakeclass::getspeed()
{
        // speed increases based on level
        del = del - (level*10000);
} // End getspeed()

void snakeclass::placesnake()
{
        // initial placement for snake
        for(int i=0;i<5;i++)
                snake.push_back(snakepart(minwidth+40+i,minheight+10));

        //draw the snake
        for(int i=0;i<snake.size();i++)
        {
                move(snake[i].y,snake[i].x);
                addch(partchar);
        } // End for loop 
} // End placesnake()

void snakeclass::placeboard()
{
        //make the game-board -- up-vertical
        for(int i=minwidth;i<maxwidth-1;i++)
        {
                move(minheight,i);
                addch(oldalchar);
        } // End for loop 
        //left-horizontal
        for(int i=minheight;i<maxheight-1;i++)
        {
                move(i,minwidth);
                addch(oldalchar);
        } // End for loop 
        //down-vertical
        for(int i=minwidth;i<maxwidth-1;i++)
        {
                move(maxheight-2,i);
                addch(oldalchar);
        } // End for loop 
        //right-horizontal
        for(int i=minheight;i<maxheight-1;i++)
        {
                move(i,maxwidth-2);
                addch(oldalchar);
        } // End for loop 
} // End placeboard()

// calculates the location of the board based on the dimensions of the terminal (to center it)
void snakeclass::getdimensions()
{
        // if the desired game dimensions are smaller than the terminal, move to the center
        // otherwise, set the max dimensions to the size of the terminal
        if (termwidth > width)
        {
                int midwidth = termwidth/2;
                maxwidth = midwidth + width/2;
                minwidth = midwidth - width/2;

        } // End if statement
        else
        {
                minwidth = 0;
                maxwidth = termwidth;
        } // End elst statement

        if (termheight > height)
        {
                int midheight = termheight/2;
                maxheight = midheight + height/2;
                minheight = midheight - height/2;
        } // End if statement
        else
        {
                minheight = 0;
                maxheight = termheight;
        } // End else statement
} // End getdimensions()


// tracks the combo multiplier and adds points accordingly
// if the player hits the same type of food twice in a row, the combo multiplier increases, once they break the combo, it returns to 1
// the combo multiplier is multiplied by the base addition of 10 points, so a multiplier of 3 would add 30 points

void snakeclass::addpoints(){

        int max = foodtrack.size(); // total size food history vector

        // if the most recently acquired food matches the one previous, increase the combo multiplier, or else return it to 1.
        if (foodtrack[max-1] == foodtrack[max-2])
                combo++;
        else
                combo = 1;

        // add 10 * combo multiplier to the points
        points += (combo*10);
        overallscore += (combo*10);

        printtext();

}

void snakeclass::printtext(){
        // prints out current score, combo multiplier, and current food
        char curfood = ' ';

        // gets the most recently eaten food (if there is one)
        if (foodtrack.size() > 0){
                curfood = foodtrack[foodtrack.size()-1];
        }

        move(maxheight-1,minwidth);
        printw("Points: %d   Combo x %d   Current Food: %c",overallscore, combo, curfood);
        move(maxheight-1, maxwidth-26);
        printw("Next Level: %d Level: %d", (levelpoints-points),level);
}


// places new food
void snakeclass::placement()
{
        place(&f);
        place(&f2);
        place(&poison);
}

void snakeclass::place(food *placefood)
{

        //this loop runs until a valid placement location is found.
        while(1)
        {
                // generates a random placement location
                int tmpx = (rand()%(maxwidth-minwidth)+1)+minwidth;
                int tmpy = (rand()%(maxheight-minheight)+1)+minheight;

                // makes sure the food doesn't spawn on the snake
                for(int i=0;i<snake.size();i++)
                        if(snake[i].x==tmpx && snake[i].y==tmpy)
                                continue;

                // checks to ensure that food/poison doesn't spawn directly in front of the snake
                for(int i=-3; i<3; i++)
                {
                        for (int j=-3; j<3; j++){
                                if (snake[0].x == tmpx + i && snake[0].y == tmpy + j)
                                        continue;
                        }

                }

                // makes sure the food doesn't spawn on an existing poison
                for (int i = 0; i < poisontrack.size(); i++)
                        if (poisontrack[i].x == tmpx && poisontrack[i].y == tmpy)
                                continue;

                // makes sure the food doesn't spawn on the edge
                if(tmpx >= maxwidth-2 || tmpy >= maxheight-3)
                        continue;

                // makes sure the food doesn't spawn on top of other food
                if (tmpx == f.x && tmpy == f.y)
                        continue;

                if (tmpx == f2.x && tmpy == f2.y)
                        continue;

                // whichever food or poison is being placed has it's x and y set to tmpx and tmpy
                placefood -> x = tmpx;
                placefood -> y = tmpy;
                break;
        }

        // if it's not poison
        if (placefood -> i != 2)
        {
                // randomly choose from one of the 3 food characters
                placefood -> character = placefood -> charpool[rand()%3];
        }
        // if it's poison, add the location to the poison tracking vector.
        else
        {
                //adds the location of the poison to the poison tracker
                poisontrack.push_back(*placefood);
        }

        // places the food on board
        move(placefood -> y, placefood -> x);
        addch(placefood -> character);
        refresh();
}

// returns true when snake collides into game ending feature
// also handles collision with food
bool snakeclass::collision()
{
        // collision with boundary
        if(snake[0].x==minwidth || snake[0].x==maxwidth-1 || snake[0].y==minheight || snake[0].y==maxheight-2)
                return true;

        // collision with self
        for(int i=2;i<snake.size();i++)
                if(snake[0].x==snake[i].x && snake[0].y==snake[i].y)
                        return true;

        // collision with poison
        for (int i = 0; i < poisontrack.size(); i++)
                if (snake[0].x==poisontrack[i].x && snake[0].y==poisontrack[i].y)
                        return true;

        // collision with the food
        bool foodhit = false;

        // checks first food
        if (snake[0].x==f.x && snake[0].y==f.y)
        {
                foodhit = true; // if it hits, check true
                move(f2.y, f2.x);
                printw(" "); // print a blank spot in the spot where food 2 was (to clear it)
                foodtrack.push_back(f.character);
        }

        // checks second food
        if (snake[0].x==f2.x && snake[0].y==f2.y)
        {
                foodhit = true; // if it hits, checks true
                move(f.y, f.x);
                printw(" "); // print a blank spot in the spot where food 1 was (to clear it)
                foodtrack.push_back(f2.character);
        }

        // if food is hit
        if(foodhit == true)
        {
                // increase the size of the snake
                get = true;

                // place new foods and poisons and allocate points
                placement();
                addpoints();

        }else
                get = false;
        return false;
}

void snakeclass::gameover()
{
        move((minheight+maxheight)/2,(minwidth+maxwidth)/2-4);
        printw("game_over");
        move((minheight+maxheight)/2+1, (minwidth+maxwidth)/2-6);
        printw("play again? y/n");
        refresh();

        while(1)
        {
                usleep(del);
                if (input == 'y'){
                        //restart the game
                        clear();
                        refresh();
                        snakeclass s;
                        s.start(1,0);
                        break;
                }
                else if (input == 'n'){
                        //close the game
                        endwin();
                        exit(0);
                        break;
                }
                getkey();
        }
}

void snakeclass::getkey(){

        //detect key
        int tmp=getch();
        switch(tmp)
        {
                case KEY_LEFT:
                        if(direction != 'r')
                                direction = 'l';
                        break;
                case KEY_UP:
                        if(direction != 'd')
                                direction = 'u';
                        break;
                case KEY_DOWN:
                        if(direction != 'u')
                                direction = 'd';
                        break;
                case KEY_RIGHT:
                        if(direction != 'l')
                                direction = 'r';
                        break;
                case KEY_BACKSPACE:
                        input = 'q';
                        break;
                case 'y':
                        input = 'y';
                        break;
                case 'n':
                        input = 'n';
                        break;
                case 'q':
                        input = 'q';
                        break;
                case 'p':
                        move(maxheight-1,minwidth+41);
                        printw("~[ PAUSED ]~");
                        refresh();
                        while(1){
                                pauser = getch();
                                if(pauser == 'p')
                                {
                                        printtext();
                                        move(maxheight-1,minwidth+41);
                                        printw("            ");
                                        break;
                                }
                                else if(pauser == 'q')
                                {
                                        endwin();
                                        exit(1);
                                }
                        }
                        break;
        }


}


void snakeclass::movesnake()
{
        getkey();

        //if there wasn't a collision with food
        if(!get)
        {
                move(snake[snake.size()-1].y,snake[snake.size()-1].x);
                printw(" ");
                refresh();
                snake.pop_back();
        }

        // changes direction and where the snakes are added
        if(direction=='l'){
                snake.insert(snake.begin(),snakepart(snake[0].x-1,snake[0].y));
        }else if(direction=='r'){
                snake.insert(snake.begin(),snakepart(snake[0].x+1,snake[0].y));
        }else if(direction=='u'){
                snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y-1));
        }else if(direction=='d'){
                snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y+1));
        }
                move(snake[0].y,snake[0].x);
                addch(partchar);
        refresh();
}

void snakeclass::start(int inplevel, int inpoverallscore)
{

        // input level and overall score from previous level
        level = inplevel;
        overallscore = inpoverallscore;

        // place initial snake, board, score line, speed, foods, and poison
        getspeed();
        getdimensions();
        placeboard();
        placesnake();
        placement();
        printtext();

        refresh();





        while(1)
        {
                if (collision())
                {
                        gameover();
                        break;
                }
                movesnake();
                if (input == 'q')
                {                               //exit
                        break;
                }

                if (levelcheck() == true)
                        break;
                usleep(del);                    //Linux delay
        }
        endwin();
        exit(1);

}

