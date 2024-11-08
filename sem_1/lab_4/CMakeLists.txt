cmake_minimum_required(VERSION 3.29)
project(NonOrientedAdjList)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -arch arm64")

add_subdirectory(googletest)

add_executable(NonOrientedAdjList main.cpp
        NonOrientedGraph.cpp
        NonOrientedGraph.h
        NonOrientedGraph.cpp
        NonOrientedGraph.h
        VertexIterator.cpp
        VertexIterator.h
        EdgeIterator.cpp
        EdgeIterator.h
        EdgeIncidentIterator.cpp
        EdgeIncidentIterator.h
        AdjacentVertexIterator.cpp
        AdjacentVertexIterator.h)

add_executable(NonOrientedAdjListTest
        tests/NonOrientedGraphTest.cpp
        NonOrientedGraph.h
        NonOrientedGraph.cpp
        tests/AdjacentVertexIteratorTest.cpp
        AdjacentVertexIterator.cpp
        AdjacentVertexIterator.h
        tests/EdgeIncidentIteratorTest.cpp
        EdgeIncidentIterator.cpp
        EdgeIncidentIterator.h
        tests/EdgeIteratorTest.cpp
        EdgeIterator.cpp
        EdgeIterator.h
        tests/VertexIteratorTest.cpp
        VertexIterator.cpp
        VertexIterator.h)

target_link_libraries(NonOrientedAdjListTest gtest gtest_main)

enable_testing()

add_test(NAME NonOrientedAdjListTest COMMAND NonOrientedAdjListTest)
