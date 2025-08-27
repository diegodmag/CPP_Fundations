### Example of nested types 

Cuando se requieren declarar tipos específicos para propósitos de nuestra implementación, se pueden declarar como *nested types*, considera el siguiente ejemplo: 

```cpp
#include <iostream>

class Fruit
{
public:
	// FruitType has been moved inside the class, under the public access specifier
        // We've also renamed it Type and made it an enum rather than an enum class
	enum Type
	{
		apple,
		banana,
		cherry
	};

private:
	Type m_type {};
	int m_percentageEaten { 0 };

public:
	Fruit(Type type) :
		m_type { type }
	{
	}

	Type getType() { return m_type;  }
	int getPercentageEaten() { return m_percentageEaten;  }

	bool isCherry() { return m_type == cherry; } // Inside members of Fruit, we no longer need to prefix enumerators with FruitType::
};

int main()
{
	// Note: Outside the class, we access the enumerators via the Fruit:: prefix now
	Fruit apple { Fruit::apple };

	if (apple.getType() == Fruit::apple)
		std::cout << "I am an apple";
	else
		std::cout << "I am not an apple";

	return 0;
}
```


## Destructors 

Clases que utilizan algín tipo de recurso (comúnmente memoria, archivos, bases de datos, conecciones a red, etc), típicamente tienen que ser explícitamente enviadas o cerradas antes de que el objeto de clase que está usando dicho recurso sea destruido. De otra manera, el recurso nunca sería liberado y estaría ocupando memoria u otro elemento. 

El término *clean-up* es comúnmente utilizado para referirse a cualquier conjunto de tareas que una clase debe realizar antes de que un objeto de esa clase sea destruido para tener el comportamiento esperado. Sin embargo, esperaríamos no tener que preocuparnos por este proceso de *clean-up*, debería existir alguna manera de automatizar los procesos pre-destructivo de una clase. 

**RECORDATORIO:** Los constructores (`constructors`) son un tipo especial de *member function* que son llamados cuando un objeto de clase es creado. Los constructores son utilizados para inicializar *member variables* y para hacer cualquier otra tarea de configuración para asegurarse de que el objeto esté listo para ser utilizado. 

De manera análoga a los `constructs`, las clases tienen otra función especial que es automáticamente ejecutada cuando un objeto de clase es detruido, llamada `destructor`. Los destructores están diseñados para permitirle a una clase realizar cualquier proceso de *clean-up* antes de que el objeto sea destruido. 

### Destructors naming

1. El destructor debe tener el mismo nombre que la clase precedido por una tilde (`~`).
2. El destructor no puede tener parámetros. 
3. El destructor no tiene valor de regreso. 

Una clase sólo puede tener un destructor. Considere el siguiente ejemplo: 

```cpp
#include <iostream>

class Simple
{
private:
    int m_id {};

public:
    Simple(int id)
        : m_id { id }
    {
        std::cout << "Constructing Simple " << m_id << '\n';
    }

    ~Simple() // here's our destructor
    {
        std::cout << "Destructing Simple " << m_id << '\n';
    }

    int getID() const { return m_id; }
};

int main()
{
    // Allocate a Simple
    Simple simple1{ 1 };
    {
        Simple simple2{ 2 };
    } // simple2 dies here

    return 0;
} // simple1 dies here
```

`Output`
```cpp
Constructing Simple 1
Constructing Simple 2
Destructing Simple 2
Destructing Simple 1
```

Notemos que cada vez que un objeto sale de un ámbito, este es destruido y por lo tanto se ejecuta el código del destructor. 