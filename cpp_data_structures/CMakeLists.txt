cmake_minimum_required(VERSION 3.17)
project(cpp_data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_data_structures main.cpp Queue.cpp Queue.h Stack.cpp Stack.h Blob.h Utils.h Utils.cpp Blob.cpp)