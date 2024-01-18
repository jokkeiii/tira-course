# Example Makefile for C++
# This Makefile compiles multiple source files into a single program.
CXX = g++
CXXFLAGS = -Wall

# Define source files
SRC_FILES = main.cpp life.cpp utility.cpp

# Define the target executable
TARGET = lifev2.out

# Compilation rule
$(TARGET): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC_FILES)

clean:
	rm -f $(TARGET)
