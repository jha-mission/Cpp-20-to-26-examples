BIN=main

CC=g++
CFLAGS=-I. -std=c++20 -fmodules

# Build main
$(BIN): math_interface.o math_impl.o
	$(CC) $(CFLAGS) main.cpp math_impl.o math_interface.o -o $(BIN)

# Compile the module interface unit
math_interface.o: math_interface.cxx
	$(CC) $(CFLAGS) -c math_interface.cxx -o math_interface.o

# Compile the implementation of the module
math_impl.o: math_impl.cpp math_interface.o
	$(CC) $(CFLAGS) -c math_impl.cpp -o math_impl.o

clean:
	rm -f *.o $(BIN)
