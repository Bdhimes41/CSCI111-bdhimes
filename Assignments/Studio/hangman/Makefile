#Compiler
CXX = g++
#Compiler Flags
CXXFLAGS = -Wall -g
#Target executable
TARGET = hangman
#Source Files
SRC = main.cpp
#Rule 1. Build
build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
#Rule 2. Clean
clean:
	rm -f $(TARGET)
#Rules 3. Run
run: build
	./$(TARGET)
#Test for makefile
test:
	@echo "makefile is working"
