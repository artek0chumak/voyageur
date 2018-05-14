cmake_minimum_required(VERSION 3.10)
project(voyageur)

set(CMAKE_CXX_STANDARD 17)

add_executable(voyageur main.cpp FlatSpace.cpp FlatSpace.h Graph.cpp Graph.h SetOnTree.cpp SetOnTree.h PathFinder.cpp PathFinder.h Test.cpp Test.h)