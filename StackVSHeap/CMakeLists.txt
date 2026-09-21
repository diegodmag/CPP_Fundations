cmake_minimum_required(VERSION 3.16)
project(stackVSheap)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

# 1 - Declarar el ejecutable primero
add_executable(${PROJECT_NAME} src/main.cpp)

# 2 - Aplicar las banderas de ASan DIRECTAMENTE al ejecutable si es Debug
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address -g -O1)
#     target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address)
# endif()