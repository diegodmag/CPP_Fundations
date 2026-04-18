cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(smart_pointers)

include_directories(${PROJECT_SOURCE_DIR}/include/)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp   
                               ${PROJECT_SOURCE_DIR}/src/SmartPointer.cpp   )