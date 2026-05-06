CXX = g++
CXXFLAGS = -Wall -std=c++17

PROGRAM = restaurant.exe
TEST_PROGRAM = doctest_runner.exe

SRC = src/main.cpp src/restaurant.cpp
TEST_SRC = tests/test_restaurant.cpp src/restaurant.cpp

all: build run

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(PROGRAM)

run:
	./$(PROGRAM)

doctest:
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST_PROGRAM)
	./$(TEST_PROGRAM)

clean:
	rm -f *.exe *.out