#include "gtest/gtest.h"
#include "student.h"
#include <vector>
#include <stdexcept>

// Тесты
TEST(StudentFunctionsTest, FindStudentMinGPA) {
    std::vector<Student> database = {
        {"Sasha", 21, "Math", 5.0},
        {"Andrew", 20, "Math", 4.2},
        {"Nikita", 22, "Math", 3.8}
    };
    Student result = findStudentMinGPA(database);
    EXPECT_EQ(result.name, "Nikita");
    EXPECT_DOUBLE_EQ(result.gpa, 3.8);
}

TEST(StudentFunctionsTest, FindStudentMaxGPA) {
    std::vector<Student> database = {
        {"Sasha", 21, "Math", 5.0},
        {"Andrew", 20, "Math", 4.2},
        {"Nikita", 22, "Math", 3.8}
    };
    Student result = findStudentMaxGPA(database);
    EXPECT_EQ(result.name, "Sasha");
    EXPECT_DOUBLE_EQ(result.gpa, 5.0);
}

TEST(StudentFunctionsTest, FindStudentMinGPA_EmptyDatabase) {
    std::vector<Student> database;
    EXPECT_THROW(findStudentMinGPA(database), std::runtime_error);
}

TEST(StudentFunctionsTest, FindStudentGPA_EmptyDatabase) {
    std::vector<Student> database;
    EXPECT_THROW(findStudentMaxGPA(database), std::runtime_error);
}

TEST(StudentFunctionsTest, FindStudentSameGPA) {
    std::vector<Student> database = {
        {"Sasha", 21, "Math", 5.0},
        {"Andrew", 20, "Math", 5.0},
        {"Nikita", 22, "Math", 5.0}
    };
    
    Student min_result = findStudentMinGPA(database);
    Student max_result = findStudentMaxGPA(database);
    
    EXPECT_EQ(min_result.name, "Sasha");
    EXPECT_EQ(max_result.name, "Sasha");
    EXPECT_DOUBLE_EQ(min_result.gpa, 5.0);
    EXPECT_DOUBLE_EQ(max_result.gpa, 5.0);
}