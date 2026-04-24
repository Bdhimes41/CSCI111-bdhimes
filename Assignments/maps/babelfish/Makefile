CXX = g++
CXXFLAGS = -Wall -std=c++17
PROGRAM = babelfish.exe

all: build

build:
	$(CXX) $(CXXFLAGS) main.cpp -o $(PROGRAM)

run: build
	./$(PROGRAM)

unit_test: build
	./$(PROGRAM) test

kattis_test: build
	./$(PROGRAM) < input1.txt > actual1.txt
	diff actual1.txt output1.txt
	./$(PROGRAM) < input2.txt > actual2.txt
	diff actual2.txt output2.txt
	./$(PROGRAM) < input3.txt > actual3.txt
	diff actual3.txt output3.txt
	./$(PROGRAM) < input4.txt > actual4.txt
	diff actual4.txt output4.txt

clean:
	rm -f $(PROGRAM) actual*.txt