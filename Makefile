# Variables
CC = g++
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -Wdeprecated -Og -ggdb

# File Names
rand: rand.o

clean:
	rm rand *.o
