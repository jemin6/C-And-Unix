SOURCES = reversi.c game.c
HEADERS = game.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c %(DEPS)
		$(CC) -c $(CFLAGS) $<

reversi: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

