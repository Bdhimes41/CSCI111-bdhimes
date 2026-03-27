CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
PROGRAM = lineup

all: build

build: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(PROGRAM)

run: build
	./$(PROGRAM)

unit_test: build
	./$(PROGRAM) test

kattis_test: build
	@echo "Running Kattis-style tests..."
	@diff -q <(./$(PROGRAM) < tests/input1.txt) tests/output1.txt && echo "Test 1 passed" || echo "Test 1 failed"
	@diff -q <(./$(PROGRAM) < tests/input2.txt) tests/output2.txt && echo "Test 2 passed" || echo "Test 2 failed"
	@diff -q <(./$(PROGRAM) < tests/input3.txt) tests/output3.txt && echo "Test 3 passed" || echo "Test 3 failed"
	@diff -q <(./$(PROGRAM) < tests/input4.txt) tests/output4.txt && echo "Test 4 passed" || echo "Test 4 failed"

clean:
	rm -f $(PROGRAM)