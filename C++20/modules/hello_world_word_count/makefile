BIN=main

CC=g++
CFLAGS=-I. -std=c++20 -fmodules

# Build main
$(BIN): *.cpp
	$(CC) $(CFLAGS) *.cpp -o $(BIN)

clean:
	rm -f *.o $(BIN)
