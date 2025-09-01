## Basic file I/O 

Hay trees principales clases de lectura y escritura de archivo: 

- `ifstream`(derivada de `istream`) para **entrada**(**input**) de archivo. 
- `ofstream`(derivada de `ostream`) para **salida**(**output**) de archivo.
- `fstream` (derivada de `iostream`) para **entrada/salida** de archivo.

Para utilizar las clases es necesario incluir el header `fstream `.

Para poder confiigurar las clases de lectura o escritura de archivos, el flujo es el siguiente:

1. Abrir el archivo que se busca leer/escribir. 
2. Instanciar el objeto apropiado para lectura/escritura de archivos del header `fstream` con el nombre del archivo como parámetro. 
3. Usar el operador de inserción`(<<)` o extracción`(>>)` para escribir o leer datos del archivo. 
4. Cerrar el archivo. 


### Buffered output

En C++, el output es buffereado, es decir, los datos no se escriben de inmediato en disco, sino que primero se guardan en un buffer de memoria para luego descargarse en bloque (lo que mejora el rendimiento).

Vaciar ese buffer se llama flushing, y ocurre al cerrar el archivo, cuando el buffer se llena, o manualmente con `ostream::flush` o `std::flush`.

Si el programa termina abruptamente (por un `crash` o `exit()`), los destructores de los file streams no se ejecutan, el archivo no se cierra y los datos en el buffer se pierden. Por eso es buena práctica cerrar explícitamente los archivos abiertos.


Ejemplo
```cpp
#include <fstream>
#include <iostream>

int main() {
    std::ofstream file("output.txt");

    file << "Hello"; // Se guarda en el buffer, pero puede que NO esté en el archivo aún
    // file.flush(); // <- aquí forzarías a escribir ya en disco

    // Si el programa se cierra aquí abruptamente, "Hello" puede perderse
    file.close(); // <-- aquí se vacía el buffer y se garantiza que se escriba
}

```

Finalmente, `std::endl` no solo agrega un salto de línea, también fuerza un flush. Usarlo en exceso puede afectar el rendimiento, así que conviene preferir `\n` cuando no se requiera un flush inmediato.


### File modes 

Los construtores de `file stream` pueden tomar parametros adicionales para especificar información sobre cómo debería ser abierto el archivo. Este parámetro es llamado modo. 

| Flag   | Descripción                                              |
|--------|----------------------------------------------------------|
| app    | Abre el archivo en modo append (escribe al final).       |
| ate    | Sitúa el puntero al final del archivo al abrir.           |
| binary | Abre el archivo en modo binario (en lugar de texto).      |
| in     | Abre el archivo en modo lectura (default de `ifstream`).  |
| out    | Abre el archivo en modo escritura (default de `ofstream`).|
| trunc  | Borra el contenido si el archivo ya existe.               |


```cpp 
int main()
{
    // We'll pass the ios:app flag to tell the ofstream to append
    // rather than rewrite the file. We do not need to pass in std::ios::out
    // because ofstream defaults to std::ios::out
    std::ofstream outf{ "Sample.txt", std::ios::app };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    outf << "This is line 3\n";
    outf << "This is line 4\n";

    return 0;

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}
```

Cerrando explicitamente el programa 

```cpp
std::ofstream outf{ "Sample.txt" };
outf << "This is line 1\n";
outf << "This is line 2\n";
outf.close(); // explicitly close the file

// Oops, we forgot something
outf.open("Sample.txt", std::ios::app);
outf << "This is line 3\n";
outf.close();
```




