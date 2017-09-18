cmake_minimum_required(VERSION 3.8)
project(DataStructure_SqList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SqList.h SqList.cpp)
add_executable(DataStructure_SqList ${SOURCE_FILES})