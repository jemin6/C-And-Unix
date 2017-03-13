Team name: Hana
Team leader: Je Min Son	
Team member names: Je Min Son, Nicolas Sim, Dan White

Project title: Snake++

Short project description: 
Nick- I also like the idea of a 2-D game, I was thinking if we were to go for something simple then snake or pong would be ideal, but if we want to go for something just a little harder , a space invader esque game would be cool too.
(an advanced snake game is my first choice though)
Implementation approach: 
Snake game: Make an instruction page showing how to play and what to press to start the game. Have the snake be stationary in the middle of the screen until you give it a direction. Directional movement for snake, x and y component to keep track. When the snake eats a randomly generated food on the screen it increases its tail by 1. (we could add different items for different effects to add difficulty to assignment).

Dan - Snake is good because it’s constant motion, so you don’t have to worry about implementing stopping and starting movement, just direction and speed. I would prefer this one. The biggest hurdle is figuring out how to set up the UI, but that should not be too hard.

https://www.youtube.com/watch?v=E_-lMZDi7Uw

Tutorial on making a snake game, we can use for inspiration and ideas.

We could also spice up snake by having multiple food types that have different effects on the snake (for example, there might be one that reduces the size, or one that doubles the size, or halves the size). These don’t seem like they would be very hard to implement and could prove that we aren’t just copying code from somewhere else.


Pong game: Make an instruction page showing how to play, 2 player game. Have certain key’s represent up and down for the left and right side. Have a ball move across the screen, 3 different x y coordinates. ( have random items pop up in the screen to increase speed of ball, or slow ball ) 

Risk management plan: 








2/18/17 Meeting:

Things to do - 

Git Repository

Choose an original code to build off of.

base code: https://codingsec.net/2016/04/program-snake-game-visual-c/

<conio.h> -> #include <curses.h>
<dos.h> no equivalent, but apparently is used for time

2/27/17 Meeting:

Originally was going to use Microsoft Visual studios, but couldn’t get conio.h to work. Microsoft Visual Studios is also not unix based so some libraries would not transfer over and not be able to be of use on ix? Our original plan was to make use of the visual libraries, but again libraries not compatible (microsoft libraries and linux libraries/ conio.h). We thought of ways to run it on unix and without special libraries we thought of the implementation that was used for the othello game which prints a new screen every time a movement is placed. This would then make it print a whole screen (probably static dimensions) to be printed over and over again every second the snake moves in a direction. The problems with this is the memory problem as well as the inefficiency of running. We use the ncurses library.

Goals for the week:

Je-min : Loading Screen Menu
Nick :  Make a set width then (Hit a certain score then reach a higher level), but ultimate goal is to make obstacles - Make different maps for difficulty.
Dan : Different effect of consumables 


By next week:
Get the base code running in visual studio.
Try to divide the code into appropriate classes.
BitButcket working (ask for help).









3/5/2017 Meeting:

Completed: Got some special food effects, got a border to pop up every food encounter. Title screen still in the making.

Dan will implement the border pop up every time a food is eaten. His implementation makes it so 2 foods pop up at once and when one is eaten, refreshes both to a different location (eating the same type make a combo multiplier).

Goals for next week: 
(Nick reason statement for terminal resize problem: ok after a lot of research, it is very hard to change the terminal size, (from what i looked at not many people know/give a good enough answer for a beginner like me) from what i found, there’s a function that a lot of people use called resizeterm, but the point of the ncurses library allows for a window to project on top of the size of the terminal so you can manipulate it. So even if we have a set window to mess around with, it's pointless if the user has a smaller terminal because then it won't work properly. We want it to work under all condition correctly so the maxheight way is probably the only way we get

Je-min: Try and get the opening screen to work. 
Dan: Make the food/border pop up work more smoothly (implementing border).
Nick: Make a set screen

Goals: When you hit a certain score, it refreshes the screen and makes a new level and makes it harder (was thinking of making a block in the middle of the screen as a border for second level, and then the third level there’s like 6 uniform blocks evenly on the screen or maybe 4, anyways make it harder that way, we gotta manually input this).
an array of locations of the wall 

Figure out how to set the window to a static size.
Figure out how to make an opening screen.


3/12/2017 Meeting:

Completed: Got title screen working and instruction page. Added paused function. 
Dan: Working on higher score 

Nick: Working on snake speed for each stage 

Je: After Dan is done with his high score, will add function to go back to the main menu after the game is done
