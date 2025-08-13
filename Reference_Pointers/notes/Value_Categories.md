# Categorias de Valor 

Definimos una **expresion** como una *combinación de literales, variables, operadores y llamadas a a función que pueden ser ejecutadas para producir un valor*.

```cpp
#include <iostream>

int main()
{
    int x { 5 };
    ++x; // This expression statement has the side-effect of incrementing x
    std::cout << x << '\n'; // prints 6

    return 0;
}
```

## Propiedades de una expresion 

Para determinar **cómo** una expresion deberia ser evaluada y **dónde** deberian poder ser usadas, todas las expresiones en C++ tienen dos propiedades: **tipo** y una **categoría de valor**. 

El tipo puede ser cualquier tipo *fundamental* o *computesto*. 

En cuanto a la **categoría de valor** de una expresion, consideremos el siguiente codigo: 

```cpp
int main()
{
    int x{};

    x = 5; // valid: we can assign 5 to x
    5 = x; // error: can not assign value of x to literal value 5

    return 0;
}
```
Cuál es una expresion válida?  Cómo sabe el compilador que expresion puede aparecer en cada lado de la asignación? 

La respuesta está en el `categoría de valor`. La categoría de valor de una expresion indica si una expresion se resuelve a `valor`, a `función` o algun `objeto`.

## Expresiones lvalue y rvalue (Lvalue and rvalue expressions)


### lvalue
Una expresion `lvalue` (short for left-value or locator value) es una expresion que se evalúa a un objeto **indentificable** o función. 

Una **entidad** (como un objeto o función) que tiene **identidad** puede ser diferenciada de otras entidades similares (típicamente comparando la dirección en memoria).

Las entidades con identidad puede ser accedida por medio de un **identificador**, **referencia** o **puntero** y típicamente tiene un tiempo de vida más largo durante el programa.

```cpp
int main()
{
    int x { 5 }; // x is an lvalue expression as it evaluates to variable x
    int y { x }; // x is an lvalue expression

    return 0;
}
```

Los `lvalues` pueden ser `modificables` o `no-modificables`. Un `lvalue no modificable` es típicamente `const`.

```cpp
int main()
{
    int x{};
    const double d{};

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression

    return 0;
}
```

### rvalue 

Una expresion `rvalue` (right value) es una expresion que no es `lvalue`. Las expresiones `rvalue` se evalúan a valores. Comúnmente las expresiones `rvalue` son literales o valores de retorno de funciones. Las expresiones `rvalue` no son **identificables** (eso quiere decir que deben de ser usadas inmediatamente) y sólo existen dentro del ámbito de la expresión en la que se utilizan.

```cpp
int return5()
{
    return 5;
}

int main()
{
    int x{ 5 }; // 5 is an rvalue expression
    const double d{ 1.2 }; // 1.2 is an rvalue expression

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression
    int z { return5() }; // return5() is an rvalue expression (since the result is returned by value)

    int w { x + 1 }; // x + 1 is an rvalue expression
    int q { static_cast<int>(d) }; // the result of static casting d to an int is an rvalue expression

    return 0;
}
```
Notemos que `return5()`, `x + 1`, y `static_cast<int>(d)` son `rvalues` ya que estas expresiones producen valores temporales que no son objetos identificables.

**RECORDATORIO:**
- Las expresiones lvalue se evalúan a un objeto  identificable.
- Las expresiones rvalue se evalúan a valores.

### Categorías de Valor y operadores 

A menos que sea especificado, los operadores esperan que sus operandos sean `rvalues`. En cuando a la operación de asignación `x=5` requiere que su operando izquierdo sea una expresión `lvalue` modificable. La asignación `(5=x)` falla por que el operando izquierdo `5` es un `rvalue`, no un `lvalue` modificable.

```cpp
int main()
{
    int x{};

    // Assignment requires the left operand to be a modifiable lvalue expression and the right operand to be an rvalue expression
    x = 5; // valid: x is a modifiable lvalue expression and 5 is an rvalue expression
    5 = x; // error: 5 is an rvalue expression and x is a modifiable lvalue expression

    return 0;
}
```

**TIP:**
- Las expresiones Lvalue son aquellas que evalúan funciones u objetos identificables (incluyendo variables) que persisten más allá del final de la expresión.

- Las expresiones rvalue son aquellas que evalúan a valores, incluyendo literales y objetos temporales que no persisten más allá del final de la expresión.


## Referencias 

En C++, una **referencia** es un alias para un objeto existente. Una vez que la referencia se ha definido, **cualquier operación hecha sobre la referencia se aplica al objeto que está referenciando**. Esto significa que podemos usar las referencias para modificar o leer el objeto que estamos referenciando.

### Referencia a un lvalue

Una referencia a un lvalue actúa como un alias para un objeto existente (como una variable). Las referencias lvalue se identifican por el uso del ampersand (&):

```cpp
    // regular types
    int        // a normal int type (not an reference)
    int&       // an lvalue reference to an int object
    double&    // an lvalue reference to a double object
    const int& // an lvalue reference to a const int object
``` 

#### Referencia lvalue de una variable 

Este tipo de referencia es una variable que actua como alias de una variable (otro lvalue).

```cpp
    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x
``` 

**BEST PRACTICE:** Cuando se define una referencia, es importante poner el ampersand al lado del tipo de la referencia (no al lado del nombre la referencia): `int& ref { x };`.

Todas las referencias deben ser inicializadas (como las constantes). Las referencias son inicializadas usando **reference initialization**.

```cpp
    int& invalidRef;   // error: references must be initialized

    int x { 5 };
    int& ref { x }; // okay: reference to int is bound to int variable
```

**WARNING:** Referencias lvalue no constantes (o modificables) solo pueden ser vinculadas a objetos no modificables.

```cpp
    int x { 5 };
    int& ref { x };         // okay: non-const lvalue reference bound to a modifiable lvalue

    const int y { 5 };
    int& invalidRef { y };  // invalid: non-const lvalue reference can't bind to a non-modifiable lvalue
``` 

**TIP:**
Si las referencias lvalue modificables (no-const) pudieran ser vinculadas a valores lvalue o rvalue no modificables (const), entonces pidríamos modificar esos valores a través de la referencia, lo cual iría en contra del valor constante.

**WARNING:** Una vez inicializada y vinculada una referencia, no puede ser reseteada, es decir, no puede cambiar para referenciar otro objeto.

**Ejercicio**

Qué imprime el siguiente programa? 

```cpp
#include <iostream>

int main()
{
    int x { 5 };
    int y { 6 };

    int& ref { x };

    ref = y; 
    std::cout << x << '\n'; 

    return 0;
}
```


<!-- Adicional -->

### Referencias y objetos tienen distintos tiempos de vida

Tanto el tiempo de vida de la referencia como el del objeto referenciado son independientes, en otras palabras:
- Una referencia puede ser destruida antes del objeto que está referenciando. 
- Un objeto siendo referenciado puede ser destruido antes que su referencia. 

Cuando una referencia es destruida antes que el objeto, el objeto no se ve afectado de ninguna manera.

#### Danggling References o *Referencias colgantes*

Cuando un objeto es destruido antes que su referencia, la referencia ahora está vinculada a un objeto que no existe. Esa refeencia se conoce como *danggling reference* o referencia colgante, la cual lleva a errores de `undefined behavior`.

**Ejercicio**

Determinar qué valores imprime el siguiente programa. 

```cpp
#include <iostream>

int main()
{
    int x{ 1 };
    int& ref{ x };

    std::cout << x << ref << '\n';

    int y{ 2 };
    ref = y;
    y = 3;

    std::cout << x << ref << '\n';

    x = 4;

    std::cout << x << ref << '\n';

    return 0;
}
```