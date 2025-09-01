## Input with stream , el operador de extracción >> 

Como hemos visto, el operador de extracción `cin` sirve para leer información de un `input stream`. Mientras se leen cadenas, un problema común con el operador de extracción es cómo guardar el input antes de que se limpie el buffer. 

Considermos: 

```cpp
char buf[10]{};
std::cin>>buf;
```
Qué pasa si el usuario introduce 18 caractéres, el buffer se desborda. Una forma de mamejar este problema es através de **manipuladores** . Un **manipulador** es un objeto que es utilizado para modificar un `stream` cuando se utiliza el operador de extracción `>>` o el operador de `inserción` `<<`. Por ejemplo, un manipulador que ya hemos usando es `std::endl`, el cual imprime un caractér de nueva linea y limpia cualquier `buffered` `output`. C++ provee un manipulador conocido como `setw` (dentro del header de `iomanip`) que puede ser usado para limitar el número de caractéres leídos de un `stream`. 

```cpp
#include <iomanip>
char buf[10]{};
std::cin >> std::setw(10) >> buf; //Maximun 10 characters to be read 
``` 

**REMINDER:** El operador de extracción se salta espacios blancod (*blanks, tabs y newlines*)
Considera: 
```cpp
int main()
{
    char ch{};
    while (std::cin >> ch)
        std::cout << ch;

    return 0;
}
```
`User input`: ``Hello my name is Alex`` 
`Ouput: HellomynameisAlex`

Algunas veces, cuando no se quieren descartar los `whitespace` se puede usar la función `get()`, que lo único que hace es obtener 

Una de las funciones más útiles es `get()`, el cual simplemente obtiene un caractér del `input stream`. Ejemplo: 
```cpp 
int main(){
    char ch{}; // caracter que se va a reasignar cada que extraigamos algo de stream y lo guardemos en ch 

    // Mientras podamos leer un caracter de std::cin
    while (std::cin.get(ch)) {
        std::cout << "Leí: " << ch << '\n';
    }
}
```

`Ooutput ->>`

```bash
Hello World
Leí: H
Leí: e
Leí: l
Leí: l
Leí: o
Leí:  
Leí: W
Leí: o
Leí: r
Leí: l
Leí: d
Leí: 
```

La función `get()` también tiene  una versión en string que toma el máximo número de caractéres a leer: 

```cpp
int main()
{
    char strBuf[11]{};
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';

    return 0;
}

```