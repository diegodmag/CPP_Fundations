
project(opOverloading)

# Estándar de C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME}  ${PROJECT_SOURCE_DIR}/src/Main.cpp
                                ${PROJECT_SOURCE_DIR}/src/OpOverload.cpp
)