CXX = g++
CXXFLAGS = -Wall -g
TARGET = Program
SRC = main.cpp
build:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)
clean:
	rm -f $(TARGET)
run: build
	./$(TARGET)

test:
	@echo "makefile is working"

