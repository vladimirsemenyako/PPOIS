cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/lib")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        Gui
        REQUIRED)

add_executable(untitled
        dvdwindow.cpp
        dvdwindow.h
        main.cpp
        resources.qrc)
target_link_libraries(untitled
        Qt6::Core Qt6::Widgets Qt6::Gui
)

