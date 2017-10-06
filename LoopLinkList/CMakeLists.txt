cmake_minimum_required(VERSION 3.8)
project(LoopLinkList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LoopLinkList.h LoopLinkList.cpp)
add_executable(LoopLinkList ${SOURCE_FILES})