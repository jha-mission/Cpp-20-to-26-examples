BIN=run_tests

CC=g++
CFLAGS=-I. -lgtest -lgtest_main -pthread -std=c++2a

$(BIN): *.cpp *.h
	$(CC) -g -o $@ *.cpp $(CFLAGS)