CC = g++
CFLAGS = -std=c++11 -g

all: reversi

reversi: reversi.o game.o
	$(CC) $(CFLAGS) -o reversi reversi.o game.o

reversi.o: reversi.cpp
	$(CC) $(CFLAGS) -c reversi.cpp

game.o: game.cpp game.h
	$(CC) $(CFLAGS) -c game.cpp

clean:
	$(RM) reversi *.o *~

