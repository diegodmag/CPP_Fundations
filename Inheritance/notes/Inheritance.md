## Herencia 

Heredar de una clase base significa que no tenemos que redefinir la información de la clase base o padre en nuestra clase derivada. 

La herencia nos permite reutilizar clases por medio de heredar los `members` a otras clases. 


### Orden de construcción de las clases derivadas 

Considera las siguientes clases: 

```cpp
class Base
{
public:
    int m_id {};

    Base(int id=0)
        : m_id { id }
    {
    }

    int getId() const { return m_id; }
};

class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0)
        : m_cost { cost }
    {
    }

    double getCost() const { return m_cost; }
};
```

Se podría suponer que los *members* de `Base` con copiados en `Derived`. Sin embargo esto no es verdad, en vez de eso, se puede considerar a `Derived` como una clase de dos partes, una parte es `Base` y otra parte es `Derived`. 


Qué es lo que ocurre con esto ? 

```cpp
int main()
{
    Derived derived;

    return 0;
}
```

Cuando `C++` construye `derived` lo hace en fases; Primero la clase más base(al tope del árbol de herencia) es construido. Después cada clase derivada es construida hacia abajo. Entonces cuando se instancia `derived`, primero se construye la parte de  `Base`y luego la parte de `Derived`. 

En conclusión, `C++` construye clases derivadas en fases, empezando con la clase *más base* (la que está en el tope del árbol de herencia). Conforme una clase es construida, el constructor apropiado de esa clase es llamado para inicializar esa parte de la clase. 

Ejemplo final: 

```cpp
#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A\n";
    }
};

class B: public A
{
public:
    B()
    {
        std::cout << "B\n";
    }
};

class C: public B
{
public:
    C()
    {
        std::cout << "C\n";
    }
};

class D: public C
{
public:
    D()
    {
        std::cout << "D\n";
    }
};
```

```cpp
int main()
{
    std::cout << "Constructing A: \n";
    A a;

    std::cout << "Constructing B: \n";
    B b;

    std::cout << "Constructing C: \n";
    C c;

    std::cout << "Constructing D: \n";
    D d;
}
```

```bash
Constructing A:
A
Constructing B:
A
B
Constructing C:
A
B
C
Constructing D:
A
B
C
D
```

### Constructores e inicializacion de clases derivadas


Condiremos de nuevo nuestra clase de `Base`, como **RECORDATORIO** el proceso al instanciar un objeto `Base` es: 

```cpp
int main()
{
    Base base{ 5 }; // use Base(int) constructor

    return 0;
}
```

1. Se aparta la memoria necesaria. 
2. El constructor apropiado de la clase Base es llamado.
3. La lista *member initializer list* inicializa las variables. 
4. Se ejecuta el cuerpo del constructor.
5. Se regresa el control al *caller* para continuar con el resto del programa.

Con las clases derivadas, las cosas son más complicadas. Consideremos: 

```cpp
int main()
{
    Derived derived{ 1.3 }; // use Derived(double) constructor

    return 0;
}
```

Esto es lo que pasa cuando se instancia a las clase `Derived`:

1. Se aparta memoria para la instancia (considerando memoria para la porción de `Base` y la porción de ``Derived`)

2. El constructor apropiado de `Derived` es llamado. 

3. El objeto `Base` es construido primero usando el constructor apropiado de `Base`. Si no hay constructor especificado de `Base`, se toma el `default`. 

4. La lista *member initializer list* inicializa las variables.

5. El cuerpo de construtor se ejcutad. 

6. Se regresa el control al `caller`. 

La única diferencia substancial es que, antes de que la clase derivada `Derived` pueda hacer algo, el constructor de `Base` es llamado primero.

### Inicializando `member variables`

Si se quisieran inicializar *member variables* de una clase padre desde una clase derivada qué se podría hacer? 

El problema es que, el valor de una `member variable` sólo puede ser configurada en la `initiaizer list` de un constructor perteneciente a la clase de la variable. 

La manera correcta de hacerlo seria: 

```cpp
class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0, int id=0)
        : Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
}; 
```

```cpp
#include <iostream>

int main()
{
    Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';

    return 0;
}
```

En más detalle esto es lo que ocurre: 

1. Se aparta la memoria. 
2. El constructor `Derived(double, int)` es llamado, donde `cost=1.3` y `id=5`. 
3. El compilador verifica si hemos solicitado un constructor específico de `Base`. Lo hemos hecho, entonces llama a `Base(int)` con `id=5`. 
4. La `member initializer list` del constuctor de la clase padre asigna a `m_id=5`.
5. El cuerpo del constructor de la clase padre ejecuta su cuerpo. 
6. El constructor de la clase padre `returns`. 
7. La `member initializer list` del constuctor de la clase derivada asigna a `m_cost=1.3`.
8. El cuerpo del constructor de la clase derivada se ejecuta. 
9. El constructor de la clase derivada `returns`.


Ahora que ya sabemos cómo inicializar una clase derivada con un constructor específico de la clase padre, podemos hacer las `member variables` privadas de nuevo. 
