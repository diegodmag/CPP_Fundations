## Input and Output (I/O) streams

Cuando se agrega el header de `iostream` ganamos acceso a una jerarquía de clases responsables de proveer funcionalidades de entrada y salida de datos. 

Un `stream` es una secuencia de bytes que pueden ser accedidos secuencialmente. Típicamente trabajamos con dos tipos de `streams`. Los `input streams` son usados para almacenar entrada de *data producers* como un teclado, un archivo o una red. Por otro lado los `output streams`son usados para almacenar la salida de consumidores particulares de datos, como un monitor, un archivo o una impresora. 

### Inputs and Outpust in c++

La clase `istream` es la principal clase para trabajar con `input streams`. Con `input streams`, el operador de extracción `(>>)` es usado para **remover valores del `stream`**. 
Por ejemplo, cuando un usuario presiona una tecla, el código de la tecla es puesto en un `input stream`. Después, el programa extrae el valor de `stream` para que pueda usarlo. 

La clase `ostream` es la principal clase para trabajar con `output stream`. El operador de inserción `(<<)` es utilizado para **agregar valores en el `stream`**. Por ejemplo, cuando insertamos valores (caractéres) en el `stream` y luego, el consumidor de datos (como el monitor) los usa. 

La clase `iostream` puede manejar tanto `input` como `output`. 

## Standard streams in c++ 

Un `standar stream` es un `pre-connected stream` que se provee a un programa de computadora por su ambiente. En el caso de `c++`, se proveen cuatro objetos standar de `stream`. 

1. `cin` -- un objeto `istream` dedicado al `standard input` (típicamente teclado)
2. `cout` -- un objeto `ostream` dedicado al `standard output` (típicamente teclado)
3. `cerr` -- un objeto `ostream` dedicado al `standard error` (típicament el monitor), que provee *unbuffered output*.
3. `clog` -- un objeto `ostream` dedicado al `standard error` (típicament el monitor), que provee *buffered output*.

**NOTA:** El *unbuffered output* típicamente es manejado de manera inmediata, mientras el *buffered output* típicamente es almacenado y escrito por completo como bloque. Aunque `clog` no es muy común. 

