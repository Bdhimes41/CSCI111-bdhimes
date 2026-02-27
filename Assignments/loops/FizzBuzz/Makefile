# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Program name
PROGRAM = main.exe

# Source and object files
CPPFILES = main.cpp
OBJFILES = main.o

# Default target
all: build

# Build executable
build: $(PROGRAM)

$(PROGRAM): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(PROGRAM)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Run normally (manual input)
run: build
	./$(PROGRAM)

# Run unit tests
unit_test: build
	./$(PROGRAM) test

# Run Kattis-style tests and compare with expected output
kattis_test: build
	./$(PROGRAM) < input1.txt > test1_out.txt
	diff output1.txt test1_out.txt

	./$(PROGRAM) < input2.txt > test2_out.txt
	diff output2.txt test2_out.txt

	./$(PROGRAM) < input3.txt > test3_out.txt
	diff output3.txt test3_out.txt

	./$(PROGRAM) < input4.txt > test4_out.txt
	diff output4.txt test4_out.txt

# Clean up build files
clean:
	rm -f $(PROGRAM) $(OBJFILES) test*_out.txt