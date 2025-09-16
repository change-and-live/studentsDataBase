#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функции поиска
Student findStudentMinGPA(const std::vector<Student>& database);
Student findStudentMaxGPA(const std::vector<Student>& database);

// Функции для работы с консольным интерфейсом
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
void displayStudentWithGPA(const std::vector<Student>& database, bool n);

#endif