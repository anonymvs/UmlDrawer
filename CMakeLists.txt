cmake_minimum_required(VERSION 3.9)
project(umldrawer)

set(CMAKE_CXX_STANDARD 17)

add_executable(umldrawer main.cpp DotWriter.cpp DotWriter.h Class.cpp Class.h Function.cpp Function.h Field.cpp Field.h Visibility.h)