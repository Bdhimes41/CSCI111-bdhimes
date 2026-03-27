CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
PROGRAM = avion.exe
SRC = main.cpp

all: build

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(PROGRAM)

run: build
	./$(PROGRAM)

unit_test: build
	./$(PROGRAM) test

kattis_test: build
	@echo "Running Kattis-style tests..."
	@for i in 1 2 3 4; do \
		echo "Test $$i:"; \
		./$(PROGRAM) < input$$i.txt > actual$$i.txt; \
		diff -q actual$$i.txt output$$i.txt || true; \
	done

clean:
	rm -f $(PROGRAM) actual*.txt