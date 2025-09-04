BIN=main

CC=g++
CFLAGS=-I. -pthread -std=c++20 -lboost_system -lboost_coroutine -lboost_context

$(BIN): *.cpp
	$(CC) -g -o $@ *.cpp $(CFLAGS)
