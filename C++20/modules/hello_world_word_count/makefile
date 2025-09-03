
BIN=main
GCM_IOSTREAM=gcm.cache/iostream.gcm

CC=g++
CFLAGS=-I. -std=c++20 -fmodules

# Build main (depends on iostream module)
$(BIN): $(GCM_IOSTREAM) *.cpp
	$(CC) $(CFLAGS) *.cpp -o $(BIN)

# Build module
$(GCM_IOSTREAM):
	$(CC) $(CFLAGS) -xc++-system-header iostream

clean:
	rm -f *.o $(BIN) gcm.cache/iostream.gcm
