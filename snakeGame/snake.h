#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#ifndef SNAKE_H
#define SNAKE_H
struct snakepart{
	int x,y;
	snakepart(int col, int row);
	snakepart();
};

struct food{
	int x,y,i;
	char charpool[4];
	char character;
	food();
};

class snakeclass{
	int points,del;
	//indicates that the snake get food (it makes the snake longer)
	bool get;
	//indicates the current direction of the snake
	char direction;

	// tracks the window's max height and width
	int maxwidth, maxheight;
	
	// tracks the combo multiplier
	int combo;
		
	char partchar;
	char oldalchar;
	char etel;
	
	// game will spawn two foods and a poison;
	food f;
	food f2;
	food poison;
	
	std::vector<char> foodtrack; // tracks the history of food characters
	
	std::vector<food> poisontrack; // tracks where the poisons are located
	
	std::vector<snakepart> snake; //represent the snake

	
	bool collision(); // returns true for game over, also handles food collisions
	void movesnake();
	void addpoints();
	void placement();
	void place(food *placefood);
	void printtext();
	
public:
	snakeclass();
	~snakeclass();
	void start();
};

#endif
