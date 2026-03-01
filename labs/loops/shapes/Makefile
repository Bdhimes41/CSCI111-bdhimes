CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = shapes.exe
TEST_RUNNER = doctest_runner.exe


SRC = shapes.cpp main.cpp
TEST_FILES = testshapes.cpp

all: build doctest run clean

build:
	$(CXX) $(CXXFLAGS) $(SRC)
	$(CXX) -o $(PROGRAM) *.o

run: build
	./$(PROGRAM)

doctest:
	$(CXX) -std=c++17 $(TEST_FILES) shapes.cpp -o $(TEST_RUNNER)
	./$(TEST_RUNNER)

clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete
	find . -name "*.pch" -delete