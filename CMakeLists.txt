cmake_minimum_required(VERSION 3.24)
project(Tic-Tac-Toe1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH /Users/local.user/Qt/6.5.0/macos/lib/cmake)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Tic-Tac-Toe1 main.cpp)

target_link_libraries(Tic-Tac-Toe1
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
