BIN=main

CC=g++
CFLAGS=-I. -pthread -std=c++2a -lboost_system -lboost_coroutine -lboost_context

$(BIN): *.cpp
	$(CC) -g -o $@ *.cpp $(CFLAGS)
