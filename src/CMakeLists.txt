cmake_minimum_required(VERSION 3.16)

project(attribute_packed_breaks_deserialization LANGUAGES CXX DESCRIPTION "How to overload the QDataStream &operator << and >> Example" VERSION 0.1.0.0)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

qt_add_executable(${PROJECT_NAME}
    main.cpp MainClass.cpp MainClass.h
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt::Core
)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})



