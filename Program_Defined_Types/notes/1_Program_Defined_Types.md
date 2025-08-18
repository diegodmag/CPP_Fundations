## Program/User defined Types 


C++ cuenta con dos categorías de tipos compuestos que pueden ser usados para crear **program-defined type**: 

- `Enumerated types` o `Enumerations`
- `Class types` (incluye `structs`, `classes` y `unions`)

Cuaquier  *program-defined type* debe tener un nombre y una definición antes de que pueda ser usado. 

Para *propagar* las definiciones de los tipos en los archivos en donde son usados, los *program-defined type* son típicamente definidos en una archivo `header` (`.h`) y después se utiliza la directiva `#include` para usar dicho tipo. 

**BEST PRACTICE:**
- Un *program-defined type* utilizado en un solo archivo de código debe definirse en ese archivo de código lo más cerca posible del primer punto de uso.

- Un *program-defined type* utilizado en múltiples archivos de código debe ser definido en un archivo de cabecera con el mismo nombre que el tipo definido por el programa y luego #incluido en cada archivo de código según sea necesario.

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