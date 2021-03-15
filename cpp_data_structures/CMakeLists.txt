cmake_minimum_required(VERSION 3.17)
project(cpp_data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_data_structures main.cpp Queue.cpp Queue.h Stack.h Blob.h Log.h Log.cpp Blob.cpp CommonTypes.h CollectionsCommon.h CommonExceptions.cpp CommonExceptions.h)