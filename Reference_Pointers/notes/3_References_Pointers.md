## Referencias y Punteros


### Compound data types

Un *Compound data types* o un tipo de dato compuesto en C++, es un tipo que se define en terminos de otros tipos de datos existentes, como por ejemplo a partir de los tipos fundamentales de datos (float, double, bool, char, int ...).

`C++` soporta los siguientes tipos compuestos de datos:
- Funciones
- Punteros
- Referencias 
- Enumerated types
- Class types (`structs`, `classes` and `unions`)


### Introducción a paso por valor, paso por referencia y por dirección. 

Cuando un objeto es pasado por valor, el parametro de la funcion recibe una copia del argumento. Esto significa que cualquier cambio al valor del parametros es realizado a la copia del argumento, no al argumento mismo. 

*Ejemplo de paso por valor*
```cpp 
void prinInt(int num){
    std::cout << num << '\n';
}

int main(){

    int x {5}; 

    prinInt(x); // Se hace una copia de x=5 y se imprime la copia
}
```

Pasar un objeto por referencia permite pasar argumentos a funciones sin hacer copias de los argumentos cada vez que la funcion es ejecutada. 

*Ejemplo de paso por referencia*
```cpp 
void prinInt(int& num){
    std::cout << num << '\n';
}

int main(){

    int x {5}; 
    int& ref_to_x {x} ;

    prinInt(x); // El argumento es el objeto mismo (x) y no se realiza ninguna copia, la funcion opera sobre x
}
```

**[Ver función print_val_and_ref_address_example](../src/ReferencesPointers.cpp#L82)**

**Ejecutar función con**`./build/references_and_pointers print_val_and_ref_address_example`

**BES PRACTICE:** Un parametro declarado como referencia constante, tiene las mismas ventajas de acceder al objeto que se está referenciando a la vez que se impide que sea modificado. 


**[Ver función const_reference_bidings](../src/ReferencesPointers.cpp#L105)**

**Ejecutar función con**`./build/references_and_pointers const_reference_bidings`


## Paso por valor VS Paso por referencia 

- Los tipos de datos fundamentales y los `enumerated types` con *baratos* de copiar, por lo que típicamente son pasados por valor.

- Los tipos de datos de Clase pueden ser *caros* de copiar, por lo que típicamente son pasados por referencia constante (`const`).

## Punteros

Dada una dirección de memoria, podemos utilizar el operador de **desreferencia** *(dereference operator)* **(*)** paa obtener el valor en esa dirección (un lvalue). En este caso la identidad del objeto es el puntero. 

El operador **de address-of** (&) y el **dereference operator** actúan como opuestos, el *address-of* obtiene la dirección de memoria de un objeto (típicamente un valor hexadecimal), mientras que el *dereference operator* obtiene el objeto en esa dirección.

**PUNTERO:** Un puntero es un objeto que guarda la dirección de memoria (típicamente de otra variable) como su valor. Esto nos permite guadar la dirección de memoria de otro objeto para usarla después.

**RECORDATORIO:** El *address-of operator* (&) regresa un puntero.

**[Ver función intro_to_pointers](../src/ReferencesPointers.cpp#L178)**

**Ejecutar función con**`./build/references_and_pointers intro_to_pointers`

**WARNING!:** Las siguientes declaraciones son distintas:
- `int* ptr3, *ptr4;` tanto `ptr3` como `ptr4` son punteros a `int` .  
- `int* ptr1,, ptr2;` `ptr1` es un puntero a `int` pero `ptr` es solo un `int` no un puntero.

## Diferencias entre referencias y punteros 

- Las referencias **deben** ser inicializadas y los punteros no necesariamente (aunque deberían).
- Las referencias no son objetos, los punteros si son. 
- Las referencias no pueden ser reasignadas (cambiar para referenciar algo más), los punteros si pueden cambiar lo que están apuntando.
- Las referencias siempre deben estar vinculadas a un objeto, los punteros pueden apuntar a la nada. 


### Punteros y asignaciones

Podemos usar asignación de punteros en dos formas distintas: 
1. Para cambiar a lo que está apuntando en puntero. 

2. Para cambiar el valor al que está apuntando. 

```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr initialized to point at x

    std::cout << *ptr << '\n'; // print the value at the address being pointed to (x's address)

    int y{ 6 };
    ptr = &y; // // change ptr to point at y

    std::cout << *ptr << '\n'; // print the value at the address being pointed to (y's address)

    return 0;
}
```

`OUTPUT:`
```
5
6
```

**REMINDER:**
- Cuando usamos un puntero sin utilizar el `dereference operator (*)` sobre `ptr`, estamos accediendo a la dirección que contiene el puntero. Modificar esto (ptr = &y) cambia lo que el puntero está señalando, es decir, ahora almacena una nueva memoria de otro objeto. 

- Cuando usamos un puntero con el `dereference operator (*)`  `(*ptr)`, estamos accediendo al objeto apuntado. Modificar esto (*ptr = 6;) cambia el valor del objeto al que se apunta.

### Dangling pointers o punteros colgantes

Muy parecido a una *referencia colgante*, un *puntero colgante* (*dangling pointer*) es un puntero que contine una dirección de memoria que ya no es válida (por ejemplo, por que el objeto fue destruido). 

Utilizar el dereference operator `*` sobre un puntero colgante, llevará a `undefined behavior`.

**Ejemplo:**

```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    int* ptr{ &x };

    std::cout << *ptr << '\n'; // valid

    {
        int y{ 6 };
        ptr = &y;

        std::cout << *ptr << '\n'; // valid
    } // y goes out of scope, and ptr is now dangling

    std::cout << *ptr << '\n'; // undefined behavior from dereferencing a dangling pointer

    return 0;
}
```

### Null pointers 

Un **valor nulo** (*null value*), es un valor especial que significa que algo no tiene valor. Cuando un puntero apunta a un valor nulo, significa que no apunta a nada. Tal puntero se conoce como **puntero nulo**.

```cpp
    int* ptr {}; // ptr is now a null pointer, and is not holding an address
```

**REMINDER:**
A esta forma de inicializar `int* ptr {};` se le conoce como `value initialization`, la cual toma el valor por defecto del tipo, que en este caso sería null. 

**BEST PRACTICE:**
Acostumbra a inicializar tus punteros con `value initialization` (si quieres que sean punteros nulos), si no los estás inicializando con la dirección de un objeto válido.


### La palabra `nullptr`

La palbra reservada `nullptr` representa una iteral puntero nula. Podemos usar `nullptr` para explícitamente inicializar o asignar un puntero como un puntero nulo. 

```cpp
    int* ptr { nullptr }; // can use nullptr to initialize a pointer to be a null pointer

    int value { 5 };
    int* ptr2 { &value }; // ptr2 is a valid pointer
    ptr2 = nullptr; // Can assign nullptr to make the pointer a null pointer
```

**WARNING:**
Al usar punteros, es importante ser cuidadoso con no usar el `dereference operator` con punteros colgantes o punteros nulos, ya que esto causará `undefined behavior` (y la aplicación se romperá). 

Se puede realizar una verificación sobre si un puntero es nulo de la siguiente manera:

```cpp
    int x { 5 };
    int* ptr { &x };

    // pointers convert to Boolean false if they are null, and Boolean true if they are non-null
    if (ptr) // implicit conversion to Boolean
        std::cout << "ptr is non-null\n";
    else
        std::cout << "ptr is null\n";

    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr ? "non-null\n" : "null\n"); // implicit conversion to Boolean
```

**[Ver función intro_to_pointers](../src/ReferencesPointers.cpp#385)**

**Ejecutar función con**`./build/references_and_pointers pointer_verification_example`


**BEST PRACTICE:**
Un puntero debería o tener asignado un valor válido, es decir, una dirección de un objeto, o estar asignado con `nullptr`.

**WARNING:** Cuando un objeto es destruido, cualquier puntero que estuviera apuntando a ese objeto queda *colgando* (no se asignan a `nullptr`). Es responsabilidad del programador detectar estos casos y asegurarse que esos punteros sean asignados a `nullptr`.

**BEST PRACTICE:**
Favorece el uso de referencias sobre los punteros a menos que alguna de las capacidades adicionales de los punteros sea requerida.

