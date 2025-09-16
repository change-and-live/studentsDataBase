CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.
GTEST_LIBS = -lgtest -lgtest_main -pthread
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage

all: program test

program: main.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) main.cpp student.cpp -o program.out

test: test.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) test.cpp student.cpp -o test.out $(GTEST_LIBS)

# Цель для сборки с покрытием
coverage: CXXFLAGS += $(COVERAGE_FLAGS)
coverage: test
	./test.out
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' '*/test.cpp' --output-file coverage.info
	genhtml coverage.info --output-directory coverage-report

clean:
	rm -f *.out *.gcno *.gcda *.info
	rm -rf coverage-report

run_test: test
	./test.out
