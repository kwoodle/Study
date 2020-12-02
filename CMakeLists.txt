cmake_minimum_required(VERSION 3.8)
project(Study)

set(CMAKE_CXX_STANDARD 14)

#set(SOURCE_FILES Node.h Rand_int.h Utils.cpp Utils.h pearls.cpp)
set(SOURCE_FILES main.cpp Node.h Rand_int.h Utils.cpp Utils.h)
add_executable(Study ${SOURCE_FILES})

add_executable(Pearls pearls.cpp Rand_int.h)