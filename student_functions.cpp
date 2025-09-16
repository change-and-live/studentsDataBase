#include "student.h"
#include <stdexcept>

// Реализация функции для поиска студента с наименьшим баллом
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