cmake_minimum_required(VERSION 3.12)
project(StudentsDatabase)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная программа
add_executable(program main.cpp student_functions.cpp)

# Тестовая программа с Google Test
add_executable(test_program test.cpp student_functions.cpp)

# Включаем директории Google Test
target_include_directories(test_program PRIVATE 
    ${CMAKE_SOURCE_DIR}/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/googletest/googletest
)

# Добавляем исходные файлы Google Test
target_sources(test_program PRIVATE
    ${CMAKE_SOURCE_DIR}/googletest/googletest/src/gtest-all.cc
    ${CMAKE_SOURCE_DIR}/googletest/googletest/src/gtest_main.cc
)

# Добавляем флаги компиляции
target_compile_options(test_program PRIVATE -pthread)