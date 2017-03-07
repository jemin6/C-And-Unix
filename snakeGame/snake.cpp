#include "snake.h"
using namespace std;
snakepart::snakepart(int col,int row)
{
	x=col;
	y=row;
}

snakepart::snakepart()
{
	x=0;
	y=0;
}

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
	
}

snakeclass::snakeclass()
{
	initscr();
	nodelay(stdscr,true);			//if there wasn't any key pressed don't wait for keypress
	keypad(stdscr,true);			//init the keyboard
	noecho();									//don't write
	curs_set(0);							//cursor invisible
	getmaxyx(stdscr,maxheight,maxwidth);
	
	partchar='x';
	oldalchar=(char)219;				// border character
	etel='*';
	
	// initialze poison
	poison.i=2;
	poison.character = poison.charpool[3];

	for(int i=0;i<5;i++)
		snake.push_back(snakepart(40+i,10));
	
	combo = 1;
	points=0;
	del=110000;
	get=0;
	direction='l';
	srand(time(NULL));
	
	// place initial foods and poison
	placement();
	printtext();
	
	//make the game-board -- up-vertical
	for(int i=0;i<maxwidth-1;i++)
	{
		move(0,i);
		addch(oldalchar);
	}
	//left-horizontal
	for(int i=0;i<maxheight-1;i++)
	{
		move(i,0);
		addch(oldalchar);
	}
	//down-vertical
	for(int i=0;i<maxwidth-1;i++)
	{
		move(maxheight-2,i);
		addch(oldalchar);
	}
	//right-horizontal
	for(int i=0;i<maxheight-1;i++)
	{
		move(i,maxwidth-2);
		addch(oldalchar);
	}
	//draw the snake
	for(int i=0;i<snake.size();i++)
	{
		move(snake[i].y,snake[i].x);
		addch(partchar);
	}
	refresh();
}

snakeclass::~snakeclass()
{
	nodelay(stdscr,false);			//turn back
	getch();										//wait until a key is pressed
	endwin();
}

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
	
	printtext();
	


	
}

void snakeclass::printtext(){
	// prints out current score, combo multiplier, and current food
	char curfood = ' ';
	
	if (foodtrack.size() > 0){
		curfood = foodtrack[foodtrack.size()-1];
	}
	
	move(maxheight-1,0);
	printw("Points: %d   Combo x %d   Current Food: %c",points, combo, curfood);	
}

void snakeclass::placement()
{
	place(&f);
	place(&f2);
	place(&poison);
}

void snakeclass::place(food *placefood)
{
	while(1)
	{
		int tmpx = rand()%maxwidth+1;
		int tmpy = rand()%maxheight+1;

		// makes sure the food doesn't spawn on the snake
		for(int i=0;i<snake.size();i++)
			if(snake[i].x==tmpx && snake[i].y==tmpy)
				continue;
			
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
	} else 
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
	if(snake[0].x==0 || snake[0].x==maxwidth-1 || snake[0].y==0 || snake[0].y==maxheight-2)
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
		get=true;
		
		// place new foods and poisons and allocate points
		placement();
		addpoints();
		
	}else
		get=false;
	return false;
}


void snakeclass::movesnake()
{
	//detect key
	int tmp=getch();
	switch(tmp)
	{
		case KEY_LEFT:
			if(direction!='r')
				direction='l';
			break;
		case KEY_UP:
			if(direction!='d')
				direction='u';
			break;
		case KEY_DOWN:
			if(direction!='u')
				direction='d';
			break;
		case KEY_RIGHT:
			if(direction!='l')
				direction='r';
			break;
		case KEY_BACKSPACE:
			direction='q';
			break;
	}
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

void snakeclass::start()
{
	while(1)
	{
		if(collision())
		{
			move(12,36);
			printw("game_over");
			break;
		}
		movesnake();
		if(direction=='q')				//exit
			break;
		usleep(del);			//Linux delay
	}
	endwin();
}
