BIN=main

CC=g++
CFLAGS=-I. -std=c++20 -fmodules

# Build main
$(BIN): math.o main.cpp
	$(CC) $(CFLAGS) main.cpp math.o -o $(BIN)

math.o: math.cpp
	$(CC) $(CFLAGS) -c math.cpp

clean:
	rm -rf *.o $(BIN) gcm.cache
