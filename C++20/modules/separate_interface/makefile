# precompile standard library module
# g++ -std=c++20 -fmodules -x c++-system-header iostream
#
# compile math module
# g++ -std=c++20 -fmodules -c math_utils.ixx -o math_utils.o
# g++ -std=c++20 -fmodules -c math_utils.cpp -o math_utils_impl.o
#
# compile main
# g++ -std=c++20 -fmodules -c main.cpp -o main.o
# link
# g++ math_utils.o math_utils_impl.o main.o -o main

CXX = g++
CXXFLAGS = -std=c++20 -fmodules

# Sources
MODULE_IFACE = math_utils.cxx
MODULE_IMPL  = math_utils.cpp
MAIN_SRC     = main.cpp

# Objects
MODULE_IFACE_OBJ = math_utils.iface.o
MODULE_IMPL_OBJ  = math_utils.impl.o
MAIN_OBJ         = main.o

TARGET = main

all: system-mods $(TARGET)

# Step 0: Precompile standard library module(s)
system-mods:
	$(CXX) $(CXXFLAGS) -x c++-system-header iostream

# Step 1: Module interface
$(MODULE_IFACE_OBJ): $(MODULE_IFACE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Step 2: Module implementation
$(MODULE_IMPL_OBJ): $(MODULE_IMPL)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Step 3: Main program
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Step 4: Link everything
$(TARGET): $(MODULE_IFACE_OBJ) $(MODULE_IMPL_OBJ) $(MAIN_OBJ)
	$(CXX) $^ -o $@

clean:
	rm -f $(MODULE_IFACE_OBJ) $(MODULE_IMPL_OBJ) $(MAIN_OBJ) $(TARGET)
	rm -rf gcm.cache
