# Lvalue References

**RECORDATORIO:** Una referencia lvalue solo puede ser vinculada a un objeto modificable (no-`const`). Recordemos que si lo permitiera, entonces podríamos modificar la variable `const` `x` a través de `ref`, lo cual no es permitido.

```cpp
    const int x { 5 }; // x is a non-modifiable (const) lvalue
    int& ref { x }; // error: ref can not bind to non-modifiable lvalue
``` 

Sin embargo si podemos vincular una **referencia lvalue constante** a un objeto constante. 
```cpp
    const int x { 5 };    // x is a non-modifiable lvalue
    const int& ref { x }; // okay: ref is a an lvalue reference to a const value
```

Esto quiere decir que a patir de la referencia constante `ref` puedo acceder a `x` pero no puedo modificarlo.

### Inicializando una referencia constante lvalue con un objeto no-constante

Las referencias lvalue constantes pueden ser vinculadas a objetos modificables. En tal caso el objeto siendo referenciado es tratado como `const` cuando es accedido a través de la referencia, incluso cuando el objeto es no-constante.

```cpp
    int x { 5 };          // x is a modifiable lvalue
    const int& ref { x }; // okay: we can bind a const reference to a modifiable lvalue

    std::cout << ref << '\n'; // okay: we can access the object through our const reference
    ref = 7;                  // error: we can not modify an object through a const reference

    x = 6;                // okay: x is a modifiable lvalue, we can still modify it through the original identifier
```

**BEST PRACTICE:** Prioriza `lvalue references to const` o referencias a constantes sobre `lvalue references to non-const`, a menos que sea necesario modificar el objeto mismo.

Las referencias constantes lvalues pueden vincularse a rvalues: 

```cpp
    sconst int& ref { 5 }; // okay: 5 is an rvalue

    std::cout << ref << '\n'; // prints 5

``` 
Cuando esto ocurre, un objeto temporal es creado e inicializado con el rvalue, y la referencia constante es vinculada a ese objeto.
