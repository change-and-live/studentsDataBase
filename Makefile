CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -fprofile-arcs -ftest-coverage # Добавлены флаги покрытия
GTEST_LIBS = -lgtest -lgtest_main -pthread
LCOV_FLAGS = -fprofile-arcs -ftest-coverage # Флаги для lcov

all: program test

program: main.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) main.cpp student.cpp -o program.out

test: test.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) test.cpp student.cpp -o test.out $(GTEST_LIBS)

# Цель для генерации отчета покрытия
coverage: test
	./test.out
	lcov --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=1
	lcov --remove coverage.info '/usr/*' '*/test.cpp' --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report

clean:
	rm -f *.out *.gcno *.gcda *.info
	rm -rf coverage_report

run_test: test
	./test.out
