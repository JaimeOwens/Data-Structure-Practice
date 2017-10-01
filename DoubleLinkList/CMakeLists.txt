cmake_minimum_required(VERSION 3.8)
project(DoubleLinkList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DoubleLinkList.h DoubleLinkList.cpp)
add_executable(DoubleLinkList ${SOURCE_FILES})