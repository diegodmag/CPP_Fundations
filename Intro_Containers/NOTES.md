# Move Semantic  

Se refiere a las reglas que determinan cómo los datos desde un objeto son movidos a otro objeto. Cuando se invoca el move semantic (por ejemplo al inicializar un `std::vector` con otro que es un `rvalue`), todo los objetos que se pueden mover de locación se mueven, y los que no pueden se copian. La operación de *mover* en vez de *copiar* puede hacer al movimiento de `move semantic` más eficiente en ciertos caos. 

**Move semantic** es una optimización que nos permite, bajo ciertas circunstancias, transferir "con poco costo" la propiedad de algunos data members de un objeto a otro en vez de realizar una copia. 

## Cuándo se invoca Move Semantic? 
Normalmente cuando inicializamos o asignamos un objeto con otro del mismo tipo. 

## Qué concluimos? 

En general los tipos de datos que son caros de copiar no debería ser pasados por valor, pero sin son capaces de usar `move semantic` pueden ser regresados por valor. 


## Range - Based Loops o Foreach 

### Cuando usamos `auto`, `auto&` y `const auto&`

- Usamos `auto` para copiar tipos *baratos de copiar*. 
- Usamos `auto&` cuando queremos modificar los elementos. 
- Usamos `const auto&` cuando tenemos tipos *caros* de copiar. 

Con el range based loop no podemos accder al índice del elemento en la estrutua, podemos declarar un contador adicional para llevar el control del índice que se está iterando. En `C++20` ahora se puede hacer un `foreach` en reversa. 