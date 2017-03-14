#ifndef GAME_H
#define GAME_H

struct Count{
    int count;
    int result;
    int current;
    int reversed;
    int blank;
    int check;
};

typedef struct _GAME{
    int row, col;
    int size;
} GAME;

typedef enum _DISC_COLOR{
    WHITE = -1,
    NONE,
    BLACK
} DISC_COLOR;

void init(GAME *n);
void finalize(GAME *n);
void display(GAME *n);

int isReversible(const int m,const int n,GAME *s);
int reverse ( int m, int n, GAME *s );
int winner (GAME *s);
int AI_move (GAME *s);

#endif

