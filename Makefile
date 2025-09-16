CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.
GTEST_LIBS = -lgtest -lgtest_main -pthread

all: program test

program: main.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) main.cpp student.cpp -o program.out

test: test.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) test.cpp student.cpp -o test.out $(GTEST_LIBS)

clean:
	rm -f *.out

run_test: test
	./test.out
