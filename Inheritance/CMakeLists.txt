cmake_minimum_required(VERSION 3.24)

project(inheritance)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} 
                                ${PROJECT_SOURCE_DIR}/src/Main.cpp
                               )                               
