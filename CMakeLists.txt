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
        MainWindow.cpp
        MainWindow.h
)
set(test_resource_files
        "icon.svg"
)
qt_add_resources(test "test"
        PREFIX
        "/"
        FILES
        ${test_resource_files}
)
target_link_libraries(test
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

