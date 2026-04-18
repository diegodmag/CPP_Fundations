## The Rule of three 

Si se implementa el copy constructor, assignment operator o destructor, debes implementar el resto. 


### Un recurso
Podemos pensar que un recurso es: 
- Cualquier cosa que exista en oferta limitada 
- Algo que tienes que **adquirir**  y **liberar**
Ejemplos: memoria, open files, sockets, puertos, etc. 


## RAII (Resource Acquisition Is Initialization)

Cuando se **inicializa** un objeto, debería de haber **adquirido** cualquier recurso que vaya a necesitar (en el constructor). Cuando un objeto sale de ámbito, debería **liberar** cada recurso que está usando (usando el destructor). En este contexto, el recurso podría ser la memoria por ejemplo. 

### Puntos claves 
- Nunca debería haber objetos *medio listos* *medio muertos*. 
- Cuando un objeto es creado, debería estar en un estado de **listo**.
- Cuando un objeto sale de ámbito, debería **liberar** sus recursos. 

Consideremos el ejemplo de lectura de archivos en C para ver cómo no se respeta el RAII. Consideremos la función escrita en C: 

```cpp
void printFile(const char* name){
    // ACQUIRE FILE RESOURCE 
    FILE* f = fopen(name, "r");
    
    // print contents of f 

    // RELEASE FILE RESOURCES 
    fclose(f);
}
```
Si olvidamos hacer el *release* `fclose`, entonces cuando el objeto `f` sale de ámbito, nunca libera sus recursos.  
```cpp
void printFile(const char* name){
    // ACQUIRE FILE RESOURCE 
    FILE* f = fopen(name, "r");
    
    // print contents of f 

    // RELEASE FILE RESOURCES 
    // fclose(f); <-- Never released its resources 
}
```

Cual sería una solución con RAII (Resource Adquisition Is Initialization)? 
```cpp
    //C file I/O + RAII
    class FileObj{
    public: 
        FILE * ptr; 
        FileObj(char* name)
            : ptr(fopen(name, "r")){}
        ~FileObj(){
            fclose(ptr);
        }
    };

```

Un mejor nombre para RAII sería **Constructor Adquires, Destructor Releases** o **Scope Based Resource Managment**.

## Recordando Stack Allocation y Heap Allocation 

### Stack Allocation 
Se refiere al proceso de **asignar memoria** a *variables locales* y *llamadas a función* en la pila de ejecución o *call stack*. También sucede automáticamente cuando una función es llamada y es liberada inmediatamente cuando la función termina. Ya que la memoria es administrada por el sistema, es rápida y eficiente pero tiene **espacio limitado** comparada con el *heap allocation*. Si demasiadas llamadas a función exceden la capacidad del stack, resulta en un *stack overflow error*. 

### Cómo funciona el stack 
- La memoria se asigna en bloques contiguos dentro de la pila de llamadas.
- El tamaño de la memoria es conocido antes de la ejecución. 
- Cuando la función es llamada, sus variables locales son asignadas en la stack. 
- Una vez que la función termina su ejecución, la memoria alojada es automáticamente liberada. 
- El programador no tiene que manejar asigación o liberaciónd e memoria. 
- Como la memoria en el stack es liberada cuando una función se completa, también se conoce como *temporary memory allocation.*

### Heap Allocation

La *Heap Memory* es asignada dinámicamente **durante** la ejecución del programa. A diferencia de la *Stack Memory* el heap no es liberado automáticamente cuando la función termina. Requiere liberación manual de memoria.  



## Smart Pointers 

Los *smart pointers* son objetos que se comportan como punteros pero añaden gestión automática de memoria. En lugar de llamar a `new` o `delete`, el puntero gestiona cuando ya no se necesita.  

Para entender las ventajas, primero recordemos a los *raw pointers*:
```cpp
void funcion() {
    MiClase* ptr = new MiClase();
    // ... código ...
    delete ptr; // ¿Qué pasa si hay una excepción o un return antes?
}
```

Algunos riesgos de los punteros son:
- Memory Leaks
- Dangling pointer 
- Double delete
- Excepciones no capturadas 

### Te presento al principio RAII (Resource Acquisition Is Initialization)

Los smart pointers implementan el principio RAII: 
- **Adquirir** el recurso en el constructor. 
- **Liberar** el recurso en el destructor

Cuando el objeto smart_pointer sale del ámbito (por fin de bloque, excepción, etc), su destructor se ejecuta **automáticamente liberando la memoria**.

### Tipos de smart pointers 

| Tipo | Descripción | Propiedad | Uso típico | 
| :----------- | :----------: | -----------: | -----------: |
| `std::unique_ptr`    | Propiedad exclusiva (no copiable)    | Único dueño    | Recurso que no se comparte | 
| `std::shared_ptr`    | Propiedad compartida    | Varios dueños    | Recurso usado en múltiples contextos |
| `std::weak_ptr`    | Referencia débil (sin propiedad)    | Observador    | Romper ciclos en shared_ptr |


