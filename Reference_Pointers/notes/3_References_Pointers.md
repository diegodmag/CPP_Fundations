## Referencias y Punteros


### Compound data types

Un *Compound data types* o un tipo de dato compuesto en C++ es un tipo que se define en terminos de otros tipos de datos existentes, como por ejemplo a partir de los tipos fundamentales de datos (float, double, bool, char, int ...).

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
