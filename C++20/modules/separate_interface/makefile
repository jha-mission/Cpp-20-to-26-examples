CXX = g++
CXXFLAGS = -std=c++20 -fmodules

# Sources
MODULE_IFACE = math_utils.ixx
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
