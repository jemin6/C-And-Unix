CXX = g++
CXXFLAGS = -g -std=c++11

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: snake

SNAKE_OBJECTS = main.o snake.o menu.o
snake: $(SNAKE_OBJECTS)
	$(CXX) -o $@ $(SNAKE_OBJECTS) -lncurses

## Define your own test-* targets here and then add them to the all: target
## For example, if you implement a Caesar cipher, define test-caesar as follows
## and then change the all: target above to "all: test-rot13cipher test-caesar"
## Do the same for test-date.
# CAESAR_OBJECTS = test-caesar.o caesar.o ioutils.o
# test-caesar: $(CAESAR_OBJECTS)
#       $(CXX) -o $@ $<

# Remove all objects and test- programs (TODO: add your own executables)
clean:
	$(RM) *.o snake

