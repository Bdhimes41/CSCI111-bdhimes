CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
TARGET   := prog
SRC      := main.cpp

.PHONY: build run clean test

build: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)

test: 
	@echo "the makefile is working"

