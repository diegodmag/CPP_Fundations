# Establece la version de CMake utilizada
cmake_minimum_required(VERSION 3.24)

# cmake_minimum_required
# (VERSION major.minor[.patch[.tweak]])

# Cmake establece el valor de la variable PROJECT_NAME con "hello_cmake"
project(multiple_files_hello_cmake)

# project
#     (projectName
#     [VERSION major[.minor[.patch[.tweak]]]]
#     [LANGUAGES languageName ...]
#     )

# Archivos fuente
set(SOURCE_FILES
    Main.cpp
    Hello.cpp)


# Indica de donde se obtiene el codigo fuente para generar el executable (de Main.cpp)
# con el nombre PROJECT_NAME (hello_cmake)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# add_executable(${PROJECT_NAME}  Main.cpp
#                                 Hello.cpp )

# add_executable
# (targetName source1 [source2 ...])

