# Establece la version de CMake utilizada
cmake_minimum_required(VERSION 3.24)

# Cmake establece el valor de la variable PROJECT_NAME con "hello_cmake"
project(multiple_files_hello_cmake)

# Archivos fuente
set(SOURCE_FILES
    Main.cpp
    Hello.cpp)


# Indica de donde se obtiene el codigo fuente para generar el executable (de Main.cpp)
# con el nombre PROJECT_NAME (hello_cmake)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})