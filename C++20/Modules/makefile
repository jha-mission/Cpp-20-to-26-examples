BIN=main

CC=g++
CFLAGS=-I. -std=c++2a -fmodules

# Link everything
$(BIN): main.o math.o math_impl.o
	$(CC) $(CFLAGS) main.o math_impl.o math.o -o $(BIN)

# Compile the module interface unit
math.o: math.cxx
	$(CC) $(CFLAGS) -c math.cxx -c -o math.o

# Compile the implementation of the module
math_impl.o: math.cpp
	$(CC) $(CFLAGS) -c math.cpp -o math_impl.o

# Compile the main file, importing the module
main.o: main.cpp math.o
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o $(BIN)
