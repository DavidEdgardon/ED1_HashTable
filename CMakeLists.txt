cmake_minimum_required(VERSION 3.7)
project(ED1Hashtable)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp hashtable.cpp hashtable.h)
add_executable(ED1Hashtable ${SOURCE_FILES})