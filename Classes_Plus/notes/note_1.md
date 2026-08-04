## Templates

## Copy construtor and Copy Elision
Imagine: 
```cpp 
Something s { Something {5}}
```
In this case we are using the `copy constructor` for `1)` Copy the Value of `Something{5}` into s, but is a unneccesary copy, we would like just doing something reduced like `Something {5}`. We would like some way to tell the compiler not to do unnecesary work. When the compiler optimizes away a call to the copy constructor, we say the constructor has been **elided**.

## Static members 
A `static varible` is not attached to any scope, it means that the variable lifetime is the same as the program. Likewise/Similarly `static members` in a class, they do not depend on the class' instances lifetime, because they are not attached to any instance but attached to the class itself. Beacause all the instances shared the static members, if that member is modified then all the instances would reflect that modification. 
A static member can be initialized using either `constexpr` (on compiling time) or `inline` (initialized with some value and can be modified). Likewise, a `static member function` is not attached to any instance but to the class itself and can be called without the need of instantiating the class. 

## Friendship

Inside the body of a class, a friend declaration (using the friend keyword) can be used to tell the compiler that some other class or function is now a friend.In C++, a friend is a class or function (member or non-member) that has been granted full access to the private and protected members of another class. 

### Friend functions
A friend function is a function (member or non-member) that can access the private and protected members of a class as though it were a member of that class.


## Explicit
Imaginemos que tenemos la siguiente clase, la cual es solo un actor con un id, y a su constructor no le ponemos `explicit`, siendo una clase con un constructor con un solo parametro. 
```cpp
#pragma once

class Actor {
private:
    int m_id;
public:
    // 🚨 SIN EXPLICIT: Un peligro inminente
    Actor(int id) : m_id{id} {}
};

// Imagina que tienes una función para dañar personajes
void HacerDanio(const Actor& objetivo, int cantidad_danio);
```