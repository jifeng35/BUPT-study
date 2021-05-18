cmake_minimum_required(VERSION 3.19)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm exp exp.h  Huffman_Coding.cpp)
add_executable(BinaryTree BinaryTree.cpp)
add_executable(test test.cpp)
add_executable(huffman_tree huffman_tree.cpp)