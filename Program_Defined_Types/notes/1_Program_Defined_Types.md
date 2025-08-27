## Program/User defined Types 


C++ cuenta con dos categorías de tipos compuestos que pueden ser usados para crear **program-defined type**: 

- `Enumerated types` o `Enumerations`
- `Class types` (incluye `structs`, `classes` y `unions`)

Cuaquier  *program-defined type* debe tener un nombre y una definición antes de que pueda ser usado. 

Para *propagar* las definiciones de los tipos en los archivos en donde son usados, los *program-defined type* son típicamente definidos en una archivo `header` (`.h`) y después se utiliza la directiva `#include` para usar dicho tipo. 

**BEST PRACTICE:**
- Un *program-defined type* utilizado en un solo archivo de código debe definirse en ese archivo de código lo más cerca posible del primer punto de uso.

- Un *program-defined type* utilizado en múltiples archivos de código debe ser definido en un archivo de cabecera con el mismo nombre que el tipo definido por el programa y luego #incluido en cada archivo de código según sea necesario.

## Structs 

Los `structs` son tipos de dato compuestos y definidos por el programa que generalmente van a definir una lógica "secilla" y contener pocas variables miembro. 

Consideremos el ejemplo de `Fraction.h`

```cpp
#ifndef FRACTION_H
#define FRACTION_H

// Define a new type named Fraction
// This only defines what a Fraction looks like, it doesn't create one
// Note that this is a full definition, not a forward declaration
struct Fraction
{
	int numerator {};
	int denominator {};
};

#endif
```
 
Y ahora en el archivo `Fraccion.cpp`

```cpp 
#include "Fraction.h" // include our Fraction definition in this code file

// Now we can make use of our Fraction type
int main()
{
	Fraction f{ 3, 4 }; // this actually creates a Fraction object named f

	return 0;
}
```

**RECORDATORIO:**
En C++ un *miembro(member data or member function)* es una variable, funcion o tipo que pertenece a una strcut o una clase. Todos los miembros (datos y funciones) deben ser definidos dentro de la struct o clase.

### Objetos clase `const` y `const` member functions

Cuando una instancia de un *program-defined type* (struct o clase) es declarado como `const`, no es posible modificar ni los atributos ni las funciones pueden modificar atributos. Consideremos el siguiente `struct`

**[Ver función intro_classes::const_struct_example](../src/IntroClasses.cpp#3)**

**Ejecutar función con**`./build/intro_classes const_struct_example`


### Public and Private members and access specifiers 

Los `members` de un `struct` se pueden acceder desde cualquier archivo ya que por defecto tienen el modificador de acceso `public`.     


## Clases 

Una clase es un *program-defined type* que puede tener *member variables* con diferentes tipos. Desde un punto de vista técnico, `structs` y `classes` son casi identicos, por lo tanto cualquier ejemplo que es implementado usando una struct puede ser implementado con una clase, sin embargo hay algunas diferencias de uso que veremos más adelante. 

Los miembros de una clase (atributos y funciones) son `private` por defecto, esto quiere decir que sólo pueden ser accedidos por otros miembros de la misma clase. 

**CONVENTION:** Se acostumbra a nombrar los atributos de una clase con el prefijo `m_`. Se recomienda usar el prefijo `s_` para variables locales estáticas y `g_` como prefijo para variables globales. 


```cpp
class DateClass // now a class instead of a struct
{
    // class members are private by default, can only be accessed by other members
    int m_year {};     // private by default
    int m_month {};    // private by default
    int m_day {};      // private by default

    void print() const // private by default
    {
        // private members can be accessed in member functions
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};
```

### Funciones de acceso 

Una función de acceso es una *member function* cuyo trabajo es recuperar o modificar el valor de un atributo privado. 

- `Getters`: (también llamados *accessors*) son *public member functions* que regresan el valor de un *private member variable*.

- `Setters`: (también llamados *mutators*) son *public member functions* que modifican el valor de un *private member variable*. 


**BESTPRACTICE:** Es común regresar una referencia constante (`const`) o una referencia (dependiendo del caso) de un atributo de una clase. Está bien regresar la referencia por que sabemos que mientras el objeto exista, la referencia regresara un objeto válido. 

**RECORDATORIO:** Cuando se regresa un atributo de una clase, no importa si es un tipo fundamental o compuesto, se suele regresar por referencia. 

**WARNING!:** Recordemos que un objeto **rvalue** es destruido al final de la expresión en la que es creado. Por lo que cualquier referencia a un miembro de un objeto **rvalue** queda colgando en este punto. 

Consideremos el siguiente caso: 

**[Ver función intro_classes::cases_for_data_members_for_rvalue](../src/IntroClasses.cpp#29)**

**Ejecutar función con**`./build/intro_classes cases_for_data_members_for_rvalue`


### `Contructors`

Un constructor es una member function especial que es automáticamente llamada después de que un objeto de una clase es creado. Cuando se define una clase, el compilador busca pra encontrar un constructor que matchee con los valores de inicialización que se proveen. 

Si un constructor acorde a los valores de inicialización es encontrado, entonces se aloja la memoria correspondiente para ese objeto y después el constructor es llamado. 

Los constructores realizan dos operaciones principalmente:

- Inicialización de cualquier *member variable* (por medio de *member initialization list*)

- Otras operaciones de verificación o configuración. Como por ejemplo, verificar que los argumentos, hacer llamadas a bases datos, etc. 

### Member initializer list vs default member initializers

```cpp
class Foo
{
private:
    int m_x {};    // default member initializer (will be ignored)
    int m_y { 2 }; // default member initializer (will be used)
    int m_z;      // no initializer

public:
    Foo(int x)
        : m_x { x } // member initializer list
    {
        std::cout << "Foo constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }
};

int main()
{
    Foo foo { 6 };
    foo.print();

    return 0;
}
```

Otro ejemplo de *member initializer list* :

```cpp
class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    Fraction(int numerator, int denominator):
        m_numerator { numerator }, m_denominator { denominator }
    {
    }
};
```
La inicialización por medio de *member initializer list* siempre ocurre en el orden en el que está definido dentro de la clase, no en el orden que está definido en la lista. 


### Constructores por defecto (default constructor)


<!-- OPCIONAL PERO INTERESANTE -->

### The copy constructor 

Un `copy constructor` es usado para inicializar un objeto con un objeto existente del mismo tipo. Después de que que el `copy constructor` se ejecute el recién creado objeto debería ser una copia del objeto pasado como inicializador. 

Si no se establece un constructor copia eplícito, `C++` creará un `implicit copy constructor`. El cuál hara una copia con *memberwise initialization*. Esto siginifica que cada miembro de la copia será inicializado usando el miembro correspondiente the la clase pasada para inicializar. 

Definiendo constructor copia propio, ejemplo: 

```cpp
class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    // Copy constructor
    Fraction(const Fraction& fraction)
        // Initialize our members using the corresponding member of the parameter
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction fCopy { f }; // Calls Fraction(const Fraction&) copy constructor

    f.print();
    fCopy.print();

    return 0;
}
```

**REMINDER:**If you write your own copy constructor, the parameter should be a const lvalue reference.

Los principales tipos de inicialización para objetos clases: 

```cpp
#include <iostream>

class Foo
{
public:

    // Default constructor
    Foo()
    {
        std::cout << "Foo()\n";
    }

    // Normal constructor
    Foo(int x)
    {
        std::cout << "Foo(int) " << x << '\n';
    }

    // Copy constructor
    Foo(const Foo&)
    {
        std::cout << "Foo(const Foo&)\n";
    }
};

int main()
{
    // Calls Foo() default constructor
    Foo f1;           // default initialization
    Foo f2{};         // value initialization PREFERED

    // Calls foo(int) normal constructor
    Foo f3 = 3;       // copy initialization (non-explicit constructors only)
    Foo f4(4);        // direct initialization
    Foo f5{ 5 };      // direct list initialization PREFERED
    Foo f6 = { 6 };   // copy list initialization (non-explicit constructors only)

    // Calls foo(const Foo&) copy constructor
    Foo f7 = f3;      // copy initialization
    Foo f8(f3);       // direct initialization
    Foo f9{ f3 };     // direct list initialization PREFERED
    Foo f10 = { f3 }; // copy list initialization

    return 0;
}
```

    There are three key differences between the initialization forms:

List initialization disallows narrowing conversions.
Copy initialization only considers non-explicit constructors/conversion functions. We’ll cover this in lesson 14.16 -- Converting constructors and the explicit keyword.
List initialization prioritizes matching list constructors over other matching constructors. We’ll cover this in lesson 16.2 -- Introduction to std::vector and list constructors.