cmake_minimum_required(VERSION 3.27)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(test main.cpp
        MenuBar.cpp
        MenuBar.h
        ToolBar.cpp
        ToolBar.h
        MainWindow.cpp
        MainWindow.h
        SearchField.cpp
        SearchField.h
)
target_link_libraries(test
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

