# Cmake 

## Primeros pasos

Cmake es un *cross platform meta build system* que genera los scripts nativos para cualquiera que sea el compilador que se está usando para después, usar esos archivos para generar el build. La idea es que, al escribir un archivo CMake, este se encarga de generar la configuración para la plataforma en la que se está usando. Esto significa que es posible construir los proyectos de C++ en Linux, Windows, Mac, etc usando el mismo `CmakeLists.txt. 

A grandes rasgos, el trabajo de Cmake es **generar instrucciones para el build** para el compilador y para la plataforma. 

### Configurando el ambiente de trabajo


- Instalar el compilador `GCC`(GNU Compiler Collection) para Debia, Ubuntu: 
```bash
    sudo apt-get install build-essential 
```
```bash
    sudo apt-get install build-essential gdb cmake
```
- Instalación de `Cmake`: 
```bash 
    sudo apt install cmake
```

### Mi primer proyecto con Cmake 

Cualquier proyecto requiere al menos dos items:

1. Al menos un archivo fuente que contenga el código del programa. 
2. Un *build script* que contenga las instrucciones de como construir el proyecto. 

En general hay dos fases para construir el proyecto: 

1. Configuración: En esta fase Cmake lee el archivo `CMakeLists.txt` y genera una carpeta `build` con las reglas establecidas en `CMakeLists.txt`. 
2. Generación: Se generan los binarios del proyecto entre ellos el archivo ejecutable a partir de `build`. 

```bash
├── CMakeLists.txt
├── build
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   │   ├── 3.30.0-rc4
│   │   │   ├── CMakeCCompiler.cmake
│   │   │   ├── CMakeCXXCompiler.cmake
│   │   │   ├── CMakeDetermineCompilerABI_C.bin
│   │   │   ├── CMakeDetermineCompilerABI_CXX.bin
│   │   │   ├── CMakeSystem.cmake
│   │   │   ├── CompilerIdC
│   │   │   │   ├── CMakeCCompilerId.c
│   │   │   │   ├── a.out
│   │   │   │   └── tmp
│   │   │   └── CompilerIdCXX
│   │   │       ├── CMakeCXXCompilerId.cpp
│   │   │       ├── a.out
│   │   │       └── tmp
│   │   ├── CMakeConfigureLog.yaml
│   │   ├── CMakeDirectoryInformation.cmake
│   │   ├── Makefile.cmake
│   │   ├── Makefile2
│   │   ├── TargetDirectories.txt
│   │   ├── cmake.check_cache
│   │   ├── pkgRedirects
│   │   ├── progress.marks
│   │   └── project_organization.dir
│   │       ├── DependInfo.cmake
│   │       ├── build.make
│   │       ├── cmake_clean.cmake
│   │       ├── compiler_depend.make
│   │       ├── compiler_depend.ts
│   │       ├── depend.make
│   │       ├── flags.make
│   │       ├── link.txt
│   │       ├── progress.make
│   │       └── src
│   ├── Makefile
│   ├── cmake_install.cmake
│   ├── compile_commands.json
│   └── project_organization
├── include
│   └── Hello.h
└── src
    ├── Hello.cpp
    └── Main.cpp
```

#### Escribiendo el primer `CMakeLists.txt`

Considera el siguiente programa `Main.cpp` en `C++`

```cpp
/** Hello CMake
 * 
 * A simple hello world program.
 */
 
#include <cstdio>
#include <cstdlib>
 
int main(int argc, const char **argv) {
    printf("Hello CMake!\n");
 
    return EXIT_SUCCESS;
}
```

Ahora, se crea el archivo `CMakeLists.txt`:
```cmake 
# Establece la version de CMake utilizada
cmake_minimum_required(VERSION 3.24)


# Cmake establece el valor de la variable PROJECT_NAME con "hello_cmake"
project(hello_cmake)


# Indica de donde se obtiene el codigo fuente para generar el executable 
# con el nombre PROJECT_NAME (hello_cmake)
add_executable(${PROJECT_NAME} Main.cpp)
```

#### Construyendo y Ejecutando el primer programa con CMake 

Primero es necesario construir el directorio para `build` y configurarlo, lo que se hace con: 

```bash 
cmake -B build 
```

Después se indica que realice la "construcción"

```bash
cmake --build build/ --parallel 
```

La opción `--parallel` permite construir en paralelo. Esto acelera la compilación en sistemas con múltiples núcleos, ya que se pueden utilizar todos los núcleos para compilar código en lugar de solo uno.

Finalmente se ejecuta el programa con `./build/hello_cmake `. 

## Compilando multiples archivos en un programa 

Conforme los programas crecen, se agregan más archivos `.cpp`, `.h` entre otros, por lo que es importante indicarle a `Cmake` qué archivos considerar para construir el ejecutable. Considera tres archivos: 

- `Hello.h`
- `Hello.cpp`
- `Main.cpp`

Ahora hay que avisarle a`Cmake` que tiene dos archivos fuentes en vez de uno `Hello.cpp` y `Main.cpp`. Por lo que vamos a declarar la variable `SOURCE_FILES`: 

```cmake 
set(SOURCE_FILES
    Main.cpp
    Hello.cpp)
```
Por lo que la nueva versión del `CmakeLists.txt` se vería como: 

```cmake
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
```

## Enlazando Third-Party Libraries 

Para enlazar librerias usando `CMake` lo mas usual es utilizar `find_package()`, el cual busca por bibliotecas en la computadora y regresa error en caso de no encontrarlo. En el curso usaremos `find_package()` por que requerimos configurar el mismo entorno de trabajo para todos. Sin embargo, es posible utilizar `FetchContent`, lo que realizara una busqueda de la dependencia primero, en caso de no encontrarla, la instalara automaticamente.

Este ultimo caso es conveniente por motivos ilustrativos aunque no se realizará de este modo por que queremos más control sobre las bibliotecas que estamos enlazando. 

### Linkeando Raylib

Raylib is an easy to use game/multimedia library. It’s great for beginners because you can do a lot with a few lines of code.



