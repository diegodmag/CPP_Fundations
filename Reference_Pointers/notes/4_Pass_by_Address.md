## Paso por direccion 

**REMINDER:**
- Cuando en una función pasamos un parámetro por valor, el parámetro recibe una copia del argumento. Cualquier cambio hecho al valor es hecho sobre la copia, no al argumento original.
- Cuando pasamos por referencia `(p.e. int&)`, la referencia está vinculada al argumento. No se copia nada. Si el parámetro no es `const`, cualquier cambio realizado al argumento se aplican al objeto.

Con el paso por **dirección**, en ves de pasar un objeto como argumento, se pasa la dirección de un objeto (por medio de un puntero). El puntero es **copiado** entonces en el parámetro de tipo puntero de la función que está siendo llamada. La función puede usar el `dereference operator` para acceder al objeto de la dirección que guarda el puntero.

**[Ver función different_argument_passing](../src/ReferencesPointers.cpp#323)**

**Ejecutar función con**`./build/references_and_pointers pointer_verification_example`

Consideremos la siguiente función que realiza un paso por dirección: 

```cpp
#include <iostream>
#include <string>
void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

int main()
{
    std::string str{ "Hello, world!" };
    printByAddress(&str); // pass str by address, does not make a copy of str
    return 0;
}
``` 

Debido a que `str` es de tipo `std::string`y la función `printByAddress` requiere un parámetro  `const std::string* ptr`, basta con usar el operador `address-of` para obtener un puntero a esa la variable `str`, de aquí que `printByAddress(&str)`.

Al momento de pasar el argumento `&str` al parámetro `const std::string* ptr`, en `ptr` guardamos una **copia** del puntero `&str`. Es decir, el paso por referencia es un paso por valor de punteros más sin embargo la dirección a la que apuntan no se copia, sigue siendo la misma. 

Al pasar por dirección, a menos que sea un **puntero a valor constante**, podemos utilizar el `dereference operator` para modificar el valor, tal como lo haríamos por paso por referencia.

**BEST PRACTICE:**
Es preferible pasar por referencia que pasar por dirección a menos que haya alguna razón específica para pasar por dirección.

### Return by reference

Return by reference devuelve una referencia que está vinculada al objeto devuelto, lo que evita hacer una copia del valor de retorno. Para devolver por referencia, simplemente definimos el valor de retorno de la función como un tipo de referencia:

```cpp
std::string&       returnByReference(); // returns a reference to an existing std::string (cheap)
const std::string& returnByReferenceToConst(); // returns a const reference to an existing std::string (cheap)
```

El uso del retorno por referencia tiene una advertencia importante: el programador debe estar seguro de que el objeto referenciado sobreviva a la función que devuelve la referencia. De lo contrario, la referencia que se devuelve quedará colgada.


**WARNING:**
Los objetos devueltos por referencia deben vivir más allá del alcance de la función que devuelve la referencia, o se producirá una referencia colgante. Nunca devuelve una variable (no estática) local o temporal por referencia.