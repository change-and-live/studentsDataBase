# Основная цель по умолчанию - компиляция программы
all:
	g++ -std=c++20 main.cpp -lgtest -lgtest_main -pthread -o program.out

# Цель для запуска тестов - сначала компилирует, потом запускает
run_test: all
	./program.out

# Очистка - удаление скомпилированной программы
clean:
	rm -f program.out
