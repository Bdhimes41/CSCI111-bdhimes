CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = main


build:
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)

test: build
	@echo "Running tests..."
	@pass=0; fail=0; \
	for i in 1 2 3 4 5 6; do \
		infile=tests/test$$i.in; \
		ansfile=tests/test$$i.ans; \
		outfile=tests/test$$i.out; \
		./$(TARGET) < $$infile > $$outfile; \
		if diff -q $$outfile $$ansfile >/dev/null; then \
			echo "test$$i: PASS"; \
			pass=$$((pass+1)); \
		else \
			echo "test$$i: FAIL"; \
			echo " expected: $$(cat $$ansfile)"; \
			echo " got:      $$(cat $$outfile)"; \
			fail=$$((fail+1)); \
		fi; \
	done; \
	echo "Passed: $$pass, Failed: $$fail"; \
	test $$fail -eq 0
