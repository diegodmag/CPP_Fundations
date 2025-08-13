# Establece la version de CMake utilizada
cmake_minimum_required(VERSION 3.24)


# Cmake establece el valor de la variable PROJECT_NAME con "hello_cmake"
project(hello_cmake)


# Indica de donde se obtiene el codigo fuente para generar el executable 
# con el nombre PROJECT_NAME (hello_cmake)
add_executable(${PROJECT_NAME} Main.cpp)