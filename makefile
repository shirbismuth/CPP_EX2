CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
VALGRIND = valgrind --leak-check=full --track-origins=yes

all: Main

Main: SquareMat.cpp Main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test: SquareMat.cpp SquareMat_doctest.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	./$@

valgrind: test
	$(VALGRIND) ./test

clean:
	rm -f Main test
