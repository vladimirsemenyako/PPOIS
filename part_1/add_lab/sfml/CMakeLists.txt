cmake_minimum_required(VERSION 3.29)
project(dvdWindowVanilla)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(dvdWindowVanilla main.cpp)

target_link_libraries(dvdWindowVanilla sfml-graphics sfml-window sfml-system)