cmake_minimum_required(VERSION 3.31)
project(instant36)

set(CMAKE_CXX_STANDARD 20)

add_executable(instant36 main.cpp
        app.cpp
        app.h
        LinkedList.cpp
)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -save-temps")
