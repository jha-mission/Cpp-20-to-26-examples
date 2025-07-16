BIN=main

CC=g++
CFLAGS=-I. -pthread -std=c++23 -fmodules -lstdc++exp

$(BIN): *.cpp
	$(CC) -g -o $@ *.cpp $(CFLAGS)