cmake_minimum_required(VERSION 3.26)
project(needcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(needcode main.cpp
        ArraysHashing.cpp
        ArraysHashing.h
        TwoPointers.cpp
        TwoPointers.h
        Stack.cpp
        Stack.h
        SlidingWindow.cpp
        SlidingWindow.h
        BinaryTree.cpp
        BinaryTree.h)
