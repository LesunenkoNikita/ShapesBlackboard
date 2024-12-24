cmake_minimum_required(VERSION 3.29)
project(ShapesBlackboard)

set(CMAKE_CXX_STANDARD 20)



add_executable(ShapesBlackboard main.cpp
        IShape.cpp
        IShape.h
        Board.cpp
        Board.h
        Triangle.cpp
        Triangle.h
        Rectangle.cpp
        Rectangle.h
        CLI.cpp
        CLI.h)
