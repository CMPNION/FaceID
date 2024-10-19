cmake_minimum_required(VERSION 3.29)

project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        /Users/cmpnion/CLionProjects/FaceID/includes/errorHandler.hpp)

find_package(OpenCV REQUIRED)

# Подключение директорий OpenCV и библиотек
target_include_directories(untitled PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(untitled PRIVATE ${OpenCV_LIBS})
