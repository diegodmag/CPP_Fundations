cmake_minimum_required(VERSION 3.24)

project(objects_relationship)

set(CMAKE_CXX_STANDARD 20)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/Main.cpp
                               ${PROJECT_SOURCE_DIR}/src/Aggregation.cpp
                               ${PROJECT_SOURCE_DIR}/src/Association.cpp
                                )