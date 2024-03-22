cmake_minimum_required(VERSION 3.10)
project(DataSructure VERSION 1.0)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES
Leetcode/Problem_150_EvaluateReversePolishNotation.cpp
)

add_executable(main ${SOURCES})
