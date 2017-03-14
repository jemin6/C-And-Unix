CXX = g++
CXXFLAGS = -g -std=c++11

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: snake

SNAKE_OBJECTS = main.o snake.o menu.o highscore.o
snake: $(SNAKE_OBJECTS)
	$(CXX) -o $@ $(SNAKE_OBJECTS) -lncurses

# Remove all objects and test- programs (TODO: add your own executables)
clean:
	$(RM) *.o snake

