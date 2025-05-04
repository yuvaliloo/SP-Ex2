CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

TARGET = main
TEST_TARGET = test
SRC = SquareMat.cpp main.cpp
TEST_SRC = SquareMat.cpp test.cpp

# Object files
OBJ = SquareMat.o main.o
TEST_OBJ = SquareMat.o test.o

.PHONY: all clean valgrind test

# Default target
all: $(TARGET)

# Build the main program by linking object files
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Build the test program by linking object files
test: $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)
	./$(TEST_TARGET)

# Build object files
SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp

main.o: main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test.o: test.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

# Valgrind analysis
valgrind: $(TARGET)
	valgrind ./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJ) $(TEST_OBJ)
