CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
PROGRAM = grading.exe
SOURCE = grading.cpp


all: build run

build:
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(PROGRAM)

run:
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM)