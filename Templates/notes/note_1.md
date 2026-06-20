### Templates

## Copy construtor and Copy Elision
Imagine: 
```cpp 
Something s { Something {5}}
```
In this case we are using the `copy constructor` for `1)` Copy the Value of `Something{5}` into s, but is a unneccesary copy, we would like just doing something reduced like `Something {5}`. We would like some way to tell the compiler not to do unnecesary work. When the compiler optimizes away a call to the copy constructor, we say the constructor has been **elided**.