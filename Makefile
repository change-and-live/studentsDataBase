CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -fprofile-arcs -ftest-coverage
GTEST_LIBS = -lgtest -lgtest_main -pthread
LCOV = lcov
GENHTML = genhtml

all: program test

program: main.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) main.cpp student.cpp -o program.out

test: test.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) test.cpp student.cpp -o test.out $(GTEST_LIBS)

test-coverage: test
	./test.out
	$(LCOV) --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=1
	$(LCOV) --remove coverage.info '/usr/*' '*/main.cpp' --output-file test-coverage.info
	$(GENHTML) test-coverage.info --output-directory test-coverage-report
	@echo "Отчет покрытия тестов сгенерирован в test-coverage-report/"

clean:
	rm -f *.out *.gcno *.gcda *.info
	rm -rf coverage-report test-coverage-report

run_test: test
	./test.out
