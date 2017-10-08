cmake_minimum_required(VERSION 3.8)
project(SqQueue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SqQueue.h)
add_executable(SqQueue ${SOURCE_FILES})