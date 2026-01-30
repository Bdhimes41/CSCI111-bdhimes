CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
TARGET = program
SRC = main.cpp

build: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: build
	./$(TARGET)
clean:
	rm -f $(TARGET)
test: build
	@echo "Running tests..."
	@fail=0; \
	for infile in tests/input/*.txt; do \
		outfile="tests/output/$$(basename $$infile)"; \
		expected="tests/expected/$$(basename $$infile)"; \
		./$(TARGET) < $$infile > $$outfile; \
		if ! diff -q $$outfile $$expected > /dev/null; then \
			echo "Test failed for $$infile"; \
			fail=1; \
		else \
			echo "Test passed for $$infile"; \
		fi; \
	done; \
	exit $$fail

