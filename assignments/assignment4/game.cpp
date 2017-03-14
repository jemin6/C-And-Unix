//// Je Min Son. CIS330, Assignment 4. 02/09/2017

#include <iostream>
#include <cstdlib>

#include "game.h"

using namespace std;

Game::Game(){
    board_size = getSize();
    board = new int*[board_size];
    for(int i = 0; i < board_size; i++){
        board[i] = new int[board_size];
        for(int j = 0; j < board_size; j++){
            board[i][j] = NONE;
        } // End nested for loop
    } // End for loop

    board[board_size/2-1][board_size/2-1] = WHITE;
    board[board_size/2-1][board_size/2] = BLACK;
    board[board_size/2][board_size/2-1] = BLACK;
    board[board_size/2][board_size/2] = WHITE;
} // End Game()
void Game::finalize(){
    for(i = 0; i< board_size; i++){
        delete []board[i];
    }
    delete []board;
}
void Game::playGame(){
  int result = 1;

  while ( result > 0 ){
      display();
      if (current == AI){
          result = AI_move();
      } // End if
      else
      {
    		  if(current == BLACK) {
    				  cout << "Player Black's turn\n";
    			} // End if
    			else
          {
    				  cout << "Player White's turn\n";
    			} // End else
          while(1) {
              cout << "enter column, then row=> ";
              cin >> m >> n;
              cout << endl;
              if(m < 0 || n < 0){
                  cout << "Input is wrong。\n";
                  cout << "enter again、";
              } // End nested if
              result = reverse(m, n);
              if(result == 0){
        					cout << m  <<" " << n << "you can't place a stone here。\n";
        					cout << "place again、";
              } // End nested if
              else
              {
                break;
              } // End nested else
          } // End nested while
      } // End else
    } // End while
    cout << "\nResult: \n";
    switch ( winner() ) {
        case BLACK:
            cout <<"\n\n&&& Black won! &&&\n\n";
            break;
        case WHITE:
            cout << "\n\n&&& White won!&&&\n\n";
            break;
        case NONE :
            cout << "\n\nNo winner!\n\n";
            break;
    } // end switch

    finalize();
} // End playGame()
void Game::display(){
    cout << " ";
    for(i = 0; i < board_size; i++){
        cout << "  " << i;
    } // end for loop
    cout << endl;
    cout << "  ┌";
    for(i = 0; i < board_size-1; i++){
        cout << "--┬";
    } // End for loop
    cout << "--┐\n";

    for(i = 0; i < board_size; i++){
        cout << i << " |";
        for(j = 0; j < board_size; j++){
            switch (board[j][i]) {
                case BLACK:
                    cout << "○";
                    break;
                case WHITE:
                    cout << "●";
                    break;
                case NONE:
                    cout << " ";
                    break;
            } // End switch
            cout << " |";
        } // End nested for loop
        cout << endl;

        if(i < board_size-1){
            cout << "  ├";
            for(j = 0; j < board_size -1; j++){
                cout << "--+";
            } // End nested for
            cout << "--┤\n";
        } // End if statement
    } // End for loop

    cout << "  └";
    for(i = 0; i < board_size -1; i++){
        cout << "--┴";
    } // End for loop
    cout << "--┘\n";
} // End display()
int Game::getSize(){
    bool isInputBad = true;

    while(isInputBad == true){
        cout << "Enter the size: ";
        cin >> board_size;

        if(board_size < 3 || board_size % 2 == 1 || board_size > 10){
            cout << "Invaild size! Enter even number between 4-10\n";
        } // End if statement
        else{
            isInputBad = false;
        } // End else statement
    } // End while loop
    return board_size;
} // End getSize()

int Game::isReversible(const int m, const int n){
    int result = 0;
    int count = 0;

    if ( m < 0 || board_size <= m || n < 0 || board_size <= n ){
        return 0;
    } // End if
    if ( board[m][n] != NONE ) {
        return 0;
    } // End if

    if ( n > 1 && board[m][n-1] == -current) {
        for ( j=n-2; j >= 0; j-- ) {
            if ( board[m][j] == current) {
                result += 1;
                count += n-j-1;
                break;
            } // End nested if
            if ( board[m][j] == NONE) {
                break;
            } // End nested if
        } // End for
    } // End if
    if ( n < board_size-2 && board[m][n+1] == -current ) {
        for ( j=n+2; j < board_size; j++ ) {
            if ( board[m][j] == current ) {
                result += 2;
                count += j-n-1;
                break;
            } // End nested if
            if ( board[m][j] == NONE	) {
                break;
            } // End nested if
        } // End for
    } // End if

    if ( m > 1 && board[m-1][n] == -current ) {
        for ( i=m-2; i >= 0; i-- ) {
			      if ( board[i][n] == current ) {
                  result += 4;
                  count += m-i-1;
                  break;
            }
			      if ( board[i][n] == NONE	) {
                  break;
            }
		    }
	  }
    if ( m < board_size-2 && board[m+1][n] == -current ) {
  		  for ( i=m+2; i < board_size; i++ ) {
  			      if ( board[i][n] == current ) {
                  result += 8;
                  count += i-m-1;
                  break;
              }
  			      if ( board[i][n] == NONE	) {
                  break;
              }
  		  }
  	}

    if ( m > 1 && n > 1 && board[m-1][n-1] == -current ) {
  		  for ( i=m-2, j=n-2;  i>=0 && j>=0;  i--, j-- ) {
  			      if ( board[i][j] == current ) {
                  result += 16;
                  count += n-j-1;
                  break;
              }
  			      if ( board[i][j] == NONE	) {
                  break;
              }
  		  }
  	}

    if ( m < board_size-2 && n > 1 && board[m+1][n-1] == -current ) {
      	  for ( i=m+2, j=n-2;  i<board_size && j>=0;  i++, j-- ) {
  			       if ( board[i][j] == current ) {
                  result += 32;
                  count += n-j-1;
                  break;
               }
  			       if ( board[i][j] == NONE	) {
                  break;
              }
  		    }
  	}

    if ( m > 1 && n < board_size-2 && board[m-1][n+1] == -current ) {
      		  for ( i=m-2, j=n+2;  i>=0 && j<board_size;  i--, j++ ) {
  			          if ( board[i][j] == current ) {
                      result += 64;
                      count += j-n-1;
                      break;
                  }
  			          if ( board[i][j] == NONE	) {
                      break;
                  }
  		      }
  	}

    if ( m < board_size-2 && n < board_size-2 && board[m+1][n+1] == -current ) {
      		  for ( i=m+2, j=n+2;  i < board_size && j < board_size;  i++, j++ ) {
                if ( board[i][j] == current ) {
                    result += 128;
                    count += j-n-1;
                    break;
                } // End nested if
                if ( board[i][j] == NONE	) {
                    break;
                } // End nested if
            } // End for
    } // End if

    return result;
} // End int isReversible()

int Game::reverse(int m,int n){

	int i, j;
	int reversed = 0;
	int reversible = isReversible(m, n);

	if ( !reversible ) return 0;

	board[m][n] = current;



	if ( reversible & 1 ) {
		for ( j=n-1;  board[m][j] == -current;  j-- ) {
			board[m][j] = current;
			reversed++;
		}
	}
	reversible >>= 1;

		if ( reversible & 1 ) {
		for ( j=n+1;  board[m][j] == -current;  j++ ) {
			board[m][j] = current;
			reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m-1;  board[i][n] == -current;  i-- ) {
			board[i][n] = current;
			reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m+1;  board[i][n] == -current;  i++ ) {
			board[i][n] = current;
			reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m-1, j=n-1;  board[i][j] == -current;  i--, j-- ) {
			board[i][j] = current;
			reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m+1, j=n-1;  board[i][j] == -current;  i++, j-- ) {
			board[i][j] = current;
			reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m-1, j=n+1;  board[i][j] == -current;  i--, j++ ) {
			board[i][j] = current;
			reversed++;
		}
	}
	reversible >>= 1;


	if ( reversible & 1 ) {
		for ( i=m+1, j=n+1;  board[i][j] == -current;  i++, j++ ) {
			board[i][j] = current;
			reversed++;
		}
	}
	reversible >>= 1;

	current = -current;


	for ( i=0; i < board_size; i++ ) {
		for ( j=0; j < board_size; j++ ) {
			if ( isReversible(i, j) ) {
				return reversed;					  }
		}
	}


	current = -current;
	for ( i=0; i < board_size; i++ ) {
		for ( j=0; j < board_size; j++ ) {
			if ( isReversible(i, j) ) {
				return reversed;
			}
		}
	}


	return -1;
}

int Game::winner(){
	int t = 0, count=0, blank=0;

	for ( i=0; i < board_size; i++ ) {
		for ( j=0; j < board_size; j++ ) {
			t += board[i][j];
			if(board[i][j]==BLACK) count++;
			else if(board[i][j]==NONE) blank++;
		}
	}
  cout << "Black: " << count << " vs White: " << board_size*board_size-count-blank << endl;

	if( t < 0 ){
      return WHITE;
  } // End if
	else if( t > 0 ){
      return BLACK;
  }
	else{
      return NONE;
  }
}

int Game::AI_move(){
  int i, j, check=0, target, arrayi[100],arrayj[100];
  int result = 1;

  if ( current == BLACK ) {
	  cout << "AI black's turn。\n";
	}else {
	  cout << "AI white's turn。\n";
	}



  if (isReversible(0,0)!=0){
		 result=reverse(0,0);
	return result;}
	if (isReversible(board_size,board_size)!=0){
		result=reverse(board_size,board_size);
	return result;}
	if (isReversible(board_size,0)!=0){
		 result=reverse(board_size,0);
	return result;}
	if (isReversible(0,board_size)!=0){
		 result=reverse(0,board_size);
	return result;}

	for ( i=0; i < board_size; i++ ) {
		for ( j=0; j < board_size; j++ ) {
			if (isReversible(i,j)!=0){
		 		//result=reverse(i,j);
		 		arrayi[check]=i;arrayj[check]=j;
		 	check++;}
		 }
	}
	target=rand()%check;
	result=reverse(arrayi[target],arrayj[target]);
	return result;


}

