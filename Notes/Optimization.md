# Optimizaiton 

### The as-if-rule 

It says that the compiler can modify a program however it likes in order to produce more optimized code, so long those modifications don't affect a program's "observable behavior". 

### An Optimization Opportunity 
Consider the following short program 
```cpp
#include <iostream>

int main()
{
	int x { 3 + 4 };
	std::cout << x << '\n';

	return 0;
}
```
The expression `x{3+4}` is evaluated at runtime, first it computes `3+4` and then initializes `x` after evaluating `3+4`. This happens at run-time, therefore, if we were to execute that code a thausand times (using a loop for example), that expression would be evaluated and assigned a thausand times, even if the result (printing 7) never changes, as a result the program would evaluate that expression without knowing that the result is the same.  
<!-- Prepositions like after requiere a gerund (-ing) when followed by a verb -->

### Compile-time evaluation 
Modern c++ compilers are capable of fully or partially evaluating certain expressions at compile-time (rather tna at runtime). When a compiller **fully** or **partially** evaluates an expression at compile-time, this is called  *compile-time evaluation*. 
 
The key aspect of compile-time evaluation is that allows compiller do work on compile-time that would otherwise be done at run-time. Because such expressions no longer need to be evaluated at run-time. The resulting executables are faster and smaller (at the cost of slightly slower compilation times).  


<!-- that would otherwise be done: que de otra manera seria hecho--> 
<!-- I no longer play videogames (I used to play videogames at some moment in the past) -->
<!-- She no longer live in Paris -->