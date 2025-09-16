CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread

all: program test

program: main.cpp student.h
	$(CXX) $(CXXFLAGS) main.cpp -o program.out

test: test.cpp student.h
	$(CXX) $(CXXFLAGS) test.cpp -o test.out $(GTEST_FLAGS)

clean:
	rm -f *.out

run_test: test
	./test.out
