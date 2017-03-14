#include <stdio.h>
#include <stdlib.h> // malloc, free

#include "game.h"


int** board;


DISC_COLOR color;
struct Count c1;

void init(GAME *n){

    int i, j, np;
    np = n->size;

    board = (int **)malloc(sizeof(int *) * np);
    for(i = 0; i < np; i++){
        board[i] = (int *)malloc(sizeof(int) * np);
        for(j = 0; j < np; j++){
            board[i][j] = color;
        } // End nested for loop
    } // End for loop

    board[np/2-1][np/2-1] = color - 1;
  	board[np/2-1][np/2]   = color + 1;
  	board[np/2][np/2-1]   = color + 1;
  	board[np/2][np/2]	    = color - 1;

} // End void init()

void finalize(GAME *n){
	int i, np;
  np = n->size;
	for ( i=0; i < np; i++ ) {
		free(board[i]);
	}
	free(board);
} // End void finalize()

void display(GAME *n) {
  	int i, j, np;
    np = n->size;

  	printf("  ");
  	for ( i=0; i < np; i++ ) printf("%3d", i);
  	printf("\n");

  	printf("  ┌");
  	for ( i=0; i < np-1; i++ ) { printf("--┬"); }
  	printf("--┐\n");

  	for ( i=0; i < np; i++ ) {
  		printf("%2d|", i);
  		for ( j=0; j < np; j++ ) {
    			switch ( board[j][i] ) {
      				case BLACK:
                    printf("○ ");
      							break;
      				case WHITE:
                    printf("● ");
      							break;
      				case NONE :
                    printf("　");
      							break;
  			  } // End switch
  			  printf("|");
  		} // End nested for
  		printf("\n");

  		if ( i < np-1 ) {
  			printf("  ├");
  			for ( j=0; j < np-1; j++ ) {
  				printf("--+");
  			} // End nested for
  			printf("--┤\n");
  		} // End if statement
  	} // End for loop

  	printf("  └");
  	for ( i=0; i < np-1; i++ ) { printf("--┴"); }
  	printf("--┘\n");
} // End void display()

int isReversible ( const int m, const int n, GAME *s ) {
	int i, j, sp;
  sp = s->size;
  c1.result = 0;
	c1.count = 0;
  c1.current = color+1;

	if(m < 0 || sp <= m || n < 0 || sp <= n){
      return 0;
  }
	if(board[m][n] != color){
      return 0;
  }
	if(n > 1 && board[m][n-1] == -c1.current) {
		  for ( j=n-2; j >= 0; j-- ) {
			    if ( board[m][j] == c1.current ) {
              c1.result += 1;
              c1.count += n-j-1;
              break;
          }
			    if (board[m][j] == color) {
              break;
          }
		  }
	}

	if(n < sp-2 && board[m][n+1] == -c1.current) {
		  for ( j=n+2; j < sp; j++ ) {
    			if ( board[m][j] == c1.current ) {
              c1.result += 2;
              c1.count += j-n-1;
              break;
          }
    			if ( board[m][j] == color	) {
              break;
          }
		  }
	}

	if ( m > 1 && board[m-1][n] == -c1.current ) {
      for ( i=m-2; i >= 0; i-- ) {
    			if ( board[i][n] == c1.current ) {
              c1.result += 4;
              c1.count += m-i-1;
              break;
          }
    			if ( board[i][n] == color	) {
              break;
          }
		  }
	}

	if ( m < sp-2 && board[m+1][n] == -c1.current ) {
		  for ( i=m+2; i < sp; i++ ) {
    			if ( board[i][n] == c1.current ) {
              c1.result += 8;
              c1.count += i-m-1;
              break;
          }
    			if ( board[i][n] == color	) {
              break;
          }
		  }
	}


	if ( m > 1 && n > 1 && board[m-1][n-1] == -c1.current ) {
  		for ( i=m-2, j=n-2;  i>=0 && j>=0;  i--, j-- ) {
    			if ( board[i][j] == c1.current ) {
              c1.result += 16;
              c1.count += n-j-1;
              break;
          }
    			if ( board[i][j] == color	) {
              break;
          }
		  }
	}

	if ( m < sp-2 && n > 1 && board[m+1][n-1] == -c1.current ) {
      for ( i=m+2, j=n-2;  i<sp && j>=0;  i++, j-- ) {
    			if ( board[i][j] == c1.current ) {
              c1.result += 32;
              c1.count += n-j-1;
              break;
          }
    			if ( board[i][j] == color	) {
              break;
          }
		  }
	}

	if ( m > 1 && n < sp-2 && board[m-1][n+1] == -c1.current ) {
  	  for ( i=m-2, j=n+2;  i>=0 && j<sp;  i--, j++ ) {
    			if ( board[i][j] == c1.current ) {
              c1.result += 64;
              c1.count += j-n-1;
              break;
          }
    			if ( board[i][j] == color	) {
              break;
          }
		  }
	}

	if ( m < sp-2 && n < sp-2 && board[m+1][n+1] == -c1.current ) {
		  for ( i=m+2, j=n+2;  i < sp && j < sp;  i++, j++ ) {
    			if ( board[i][j] == c1.current ) {
              c1.result += 128;
              c1.count += j-n-1;
              break;
           }
    			if ( board[i][j] == color	) {
              break;
          }
		  }
	}
	return c1.result;
}

int reverse ( int m, int n, GAME *s ) {

	int i, j, sp;
  sp = s->size;
	c1.reversed = 0;
	int reversible = isReversible(m, n, s);

	if ( !reversible ) {
      return 0;
  }

	board[m][n] = c1.current;



	if ( reversible & 1 ) {
		for ( j=n-1;  board[m][j] == -c1.current;  j-- ) {
			board[m][j] = c1.current;
			c1.reversed++;
		}
	}
	reversible >>= 1;

		if ( reversible & 1 ) {
		for ( j=n+1;  board[m][j] == -c1.current;  j++ ) {
			board[m][j] = c1.current;
			c1.reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m-1;  board[i][n] == -c1.current;  i-- ) {
			board[i][n] = c1.current;
			c1.reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m+1;  board[i][n] == -c1.current;  i++ ) {
			board[i][n] = c1.current;
			c1.reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m-1, j=n-1;  board[i][j] == -c1.current;  i--, j-- ) {
			board[i][j] = c1.current;
			c1.reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m+1, j=n-1;  board[i][j] == -c1.current;  i++, j-- ) {
			board[i][j] = c1.current;
			c1.reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m-1, j=n+1;  board[i][j] == -c1.current;  i--, j++ ) {
			board[i][j] = c1.current;
			c1.reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m+1, j=n+1;  board[i][j] == -c1.current;  i++, j++ ) {
			board[i][j] = c1.current;
			c1.reversed++;
		}
	}
	reversible >>= 1;

	c1.current = -c1.current;


	for ( i=0; i < sp; i++ ) {
		for ( j=0; j < sp; j++ ) {
			if ( isReversible(i, j, s) ) {
				return c1.reversed;
      }
		}
	}


	c1.current = -c1.current;
	for ( i=0; i < sp; i++ ) {
		for ( j=0; j < sp; j++ ) {
			if ( isReversible(i, j, s) ) {
				return c1.reversed;
			}
		}
	}

	return -1;
}

int winner (GAME *s) {
	int i, j, sp;
  sp = s->size;
  c1.count = 0;
  c1.blank = 0;
	int t = 0;

	for ( i=0; i < sp; i++ ) {
  		for ( j=0; j < sp; j++ ) {
  			  t += board[i][j];
    			if(board[i][j]==color+1) {
              c1.count++;
          }
    			else if(board[i][j]==color) {
              c1.blank++;
          }
  		}
	}
	printf("Black: %d  V.S. White: %d \n", c1.count, sp*sp-c1.count-c1.blank);

	if( t < 0 ) {
      return color-1;
  }
	else if ( t > 0 ) {
      return color+1;
  }
	else{
    return color;
  }
} // End int winner()

int AI_move (GAME *s) {
	int i, j, sp, target, arrayi[100],arrayj[100];
  c1.check = 0;
  sp = s->size;
	c1.result = 1;

	if ( c1.current == color + 1 ) {
	  printf("AI black's turn。\n");
	}else {
	  printf("AI white's turn。\n");
	}

	if (isReversible(0,0,s)!=0){
		 c1.result=reverse(0,0,s);
	return c1.result;}
	if (isReversible(sp,sp,s)!=0){
		c1.result=reverse(sp,sp,s);
	return c1.result;}
	if (isReversible(sp,0,s)!=0){
		 c1.result=reverse(sp,0,s);
	return c1.result;}
	if (isReversible(0,sp,s)!=0){
		 c1.result=reverse(0,sp,s);
	return c1.result;}

	for ( i=0; i < sp; i++ ) {
		for ( j=0; j < sp; j++ ) {
			if (isReversible(i,j,s)!=0){
		 		//result=reverse(i,j,s);
		 		arrayi[c1.check]=i;arrayj[c1.check]=j;
		 	c1.check++;}
		 }
	}
	target=rand()%c1.check;
	c1.result=reverse(arrayi[target],arrayj[target], s);
	return c1.result;
}

