//// Je Min Son. CIS330, Assignment 4. 02/09/2017

#ifndef GAME_H
#define GAME_H

#define WHITE -1
#define NONE 0
#define BLACK 1

using namespace std;

class Game{
    public:
        Game();
        void finalize();
        void playGame();
        void display();       // display the board
    private:
        int i, j, AI, m, n;
        int current = BLACK;
        int board_size;
        int** board;
        int getSize();
        int isReversible(const int m, const int n);
        int reverse(int m,int n);
        int winner();
        int AI_move();
};

#endif

