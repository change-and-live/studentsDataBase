#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    if (database.empty()){
        std::cout << "База данных пуста";
        return;
    }
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Функция для поиска студента с наименьшим баллом
void findStudentsMinGPA(const std::vector<Student>& database) {
    if (database.empty()){
        std::cout << "База данных пуста";
        return;
    }
    double min_gpa = 100.0;
    std::string student_name = "";
    for (const Student& student : database) {
        if (min_gpa > student.gpa) {
            min_gpa = student.gpa;
            student_name = student.name;
        }
    }
    std::cout << "Студент с наименьшим баллом: " << student_name << "\t балл = " << min_gpa << "\n";
}

// Функция для поиска студента с наибольшим баллом
void findStudentsMaxGPA(const std::vector<Student>& database) {
    if (database.empty()){
        std::cout << "База данных пуста";
        return;
    }
    double max_gpa = 0.0;
    std::string student_name = "";
    for (const Student& student : database) {
        if (max_gpa < student.gpa) {
            max_gpa = student.gpa;
            student_name = student.name;
        }
    }
    std::cout << "Студент с наибольшим баллом: " << student_name << "\t балл = " << max_gpa << "\n";
}

int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Вывести студента с наименьшим баллом\n";
        std::cout << "4. Вывести студента с наибольшим баллом\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3:
                findStudentsMinGPA(database);
                break;
            case 4:
                findStudentsMaxGPA(database);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
