#include <iostream>
#include <vector>
#include <string>
#include <stdexpect>

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

Student findStudentMinGPA(const std::vector<Student>& database) {
    if (database.empty()){
        throw std::runtime_error("База данных пуста");
    }
    double min_gpa = 100.0;
    Student minStudent;
    for (const Student& student : database) {
        if (min_gpa > student.gpa) {
            min_gpa = student.gpa;
            minStudent = student;
        }
    }
    return minStudent;
}

// Реализация функции для поиска студента с наибольшим баллом
Student findStudentMaxGPA(const std::vector<Student>& database) {
    if (database.empty()){
        throw std::runtime_error("База данных пуста");
    }
    double max_gpa = 0.0;
    Student maxStudent;
    for (const Student& student : database) {
        if (max_gpa < student.gpa) {
            max_gpa = student.gpa;
            maxStudent = student;
        }
    }
    return maxStudent;
}

void displayStudentWithGPA(const std::vector<Student>& database, bool n) {
    if (!n) {
        Student minStudent = findStudentMinGPA(database);
        std::cout << "Студент с наименьшим баллом: " << minStudent.name << "\t балл = " << minStudent.gpa << "\n";
    }
    if (n) {
        Student maxStudent = findStudentMaxGPA(database);
        std::cout << "Студент с наибольшим баллом: " << maxStudent.name << "\t балл = " << maxStudent.gpa << "\n";
    }
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
                displayStudentWithGPA(database, 0);
                break;
            case 4:
                displayStudentWithGPA(database, 1);
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
