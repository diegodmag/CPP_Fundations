# Establece la version de CMake utilizada
cmake_minimum_required(VERSION 3.24)

# Cmake establece el valor de la variable PROJECT_NAME con "hello_cmake"
project(project_organization)

set(CMAKE_CXX_STANDARD 17)

# include_directories es un comando de CMake que indica al compilador dónde buscar archivos .h cuando compile
include_directories(
    # ${PROJECT_SOURCE_DIR} es una variable automática de CMake que apunta a la carpeta raíz del proyecto
    ${PROJECT_SOURCE_DIR}/include
)

# Add source files from src/
# file(GLOB ...) es un comando que busca archivos en el sistema según un patrón.
# Aquí busca todos los archivos con extensión .cpp dentro de la carpeta src de la raíz del proyecto (${PROJECT_SOURCE_DIR}/src/)
# Todos esos archivos .cpp encontrados se guardan en la variable SOURCES
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# CONFIGURE_DEPENDS 

# Indica de donde se obtiene el codigo fuente para generar el executable (de Main.cpp)
# con el nombre PROJECT_NAME (hello_cmake)
add_executable(${PROJECT_NAME} ${SOURCES})

