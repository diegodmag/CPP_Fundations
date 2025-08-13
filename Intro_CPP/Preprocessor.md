## Preprocessor 

Antes de que el codigo fuente sea compilado, cada archivo `.cpp` pasa por una fase de preprocesamiento. En esta fase, un programa conocido como el `pre-procesador` realiza varios cambios al código. Realmente el procesador no modifica el condigo fuente, si no unas copias del codigo fuente que almacena temporalmente en memoria. 

Las directivas `#include` son las que le interesan al pre-procesador. Cuando el pre-procesador ha terminado de procesar un archivo, el resultado se conoce como `translation unit`. El proceso entero de *pre-procesar*, *compilar* y *enlazar(linking)* es conocido como traduccion. Las directivas que inician con un `#` y terminan con nueva linea (no con punto y como) se conocen como `Preprocessor directives`.

### Directiva #include

Cuando se agrega un `#include` a un archivo, el pre-procesador reemplaza la directiva con el contenido del archivo incluido, como las biblitecas. Después de esto, el archivo completo es pre-procesado. 

*Ejemplo*
```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, world!\n";
    return 0;
}
```
En este ejemplo, la directiva `#include <iostream>` es reemplazada con el contenido del archivo llamado `iostream`. 

### Definiciones de Macros 

**BUENA PRACTICA:** Los nombres de las macros deberían ser escritas en mayúsculas, con palabras separadas por guiones bajos. 

La directiva `#define` puede ser usada para crear una macro. En `C++` una **macro** es una regla que define como se convierte el texto de entrada en texto de salida de reemplazo. Hay dos tipos de macros: *object-like macros* y *function-like macros*.

- *object-like macros* pueden ser definindas de dos maneras:s
    ```cpp
        #define IDENTIFIER
        #define IDENTIFIER substitution_text
    ```

  
