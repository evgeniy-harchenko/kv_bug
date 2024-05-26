# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(simpletreemodel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ECM ${KF6_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Test Widgets)
find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS XmlGui)

qt_standard_project_setup()

qt_add_executable(simpletreemodel
        main.cpp
        treeitem.cpp treeitem.h
        treemodel.cpp treemodel.h
        myqtreeview.h
        myqtreeview.cpp
)

target_link_libraries(simpletreemodel PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        KF6::XmlGui
)

# Resources:
set(simpletreemodel_resource_files
        "default.txt"
)

qt_add_resources(simpletreemodel "simpletreemodel"
        PREFIX
            "/"
        FILES
            ${simpletreemodel_resource_files}
)

install(TARGETS simpletreemodel
        BUNDLE  DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
