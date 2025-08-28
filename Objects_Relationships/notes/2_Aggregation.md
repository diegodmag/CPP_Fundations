## Aggregation

To qualify as an **aggregation relationship**, a whole object and its part must have the following relationship: 

- The part(memeber) can (if desired) belong to more than one object(class) at a time. 
- The part(member) does not have its existence managed by the object(class).
- The part(member) does not know about the existence of the object. 

Unlike composition, int the aggregation relationship, the parts can belong to more than one object at a time and the whole object is not responsible for the existence and lifespan of the parts  

### Summarizing composition and aggregation: 

- **Composition:**
    - Typically use normal member variables. 
    - Can use pointer member if the class handles object allocation/ deallocation. 
    - Responsible for creation/destruction of parts. 

- **Aggregation:**
    - Typically use pointer or reference members that point to a reference objects that live outside the scope of the aggregated class. 
    - Not responsible for creating or destroying parts. 

**REMINDER:** An aggregate type are data types that group multiple variables together. 

Consider the nex example: 

```cpp

#include <iostream>
#include <string>
#include <string_view>

class Teacher
{
private:
  std::string m_name{};

public:
  Teacher(std::string_view name)
      : m_name{ name }
  {
  }

  const std::string& getName() const { return m_name; }
};

class Department
{
private:
  const Teacher& m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers

public:
  Department(const Teacher& teacher) // Look that department is receiving a teacher from an outside scope 
      : m_teacher{ teacher }
  {
  }
};
```

And the main

```cpp
int main()
{
  // Create a teacher outside the scope of the Department
  Teacher bob{ "Bob" }; // create a teacher

  {
    // Create a department and use the constructor parameter to pass
    // the teacher to it.
    Department department{ bob };

  } // department goes out of scope here and is destroyed

  // bob still exists here, but the department doesn't

  std::cout << bob.getName() << " still exists!\n";

  return 0;
}
```

In the example, the constructor of `Department` only receives one reference to a `Teacher`, but what if a `Department` has multiple `Teachers`? We'd like to store those `Teachers` in a list of some kind (e.g. `std::vector`) but fixed arrays and the various standard library list can't hold references (because list elements must be assignable, and references can't be reassigned). 

Instead of reference we could use pointers but that would open the possibility to store or pass null pointers. To solve this, there's `std::reference_wrapper`. 

Essentially, `std::reference_wrapper` is a class that acts like a reference, but also allows assignment and copying, so it's compatible with litst like `std::vector`. 

All you need to know are three things: 

1. `std::reference_wrapper` lives in the `functional` header. 
2. When you create your `std::reference_wrapper` wrapped object, the object can't be anonymous object(since anonymous objects have expression scope, and this would leave the reference dangling).
3. When you whant to get your object back out of the `std::reference_wrapper`, you use the `get()` member function. 

```cpp 
#include <functional> // std::reference_wrapper
#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::string tom{ "Tom" };
  std::string berta{ "Berta" };

  std::vector<std::reference_wrapper<std::string>> names{ tom, berta }; // these strings are stored by reference, not value

  std::string jim{ "Jim" };

  names.emplace_back(jim);

  for (auto name : names)
  {
    // Use the get() member function to get the referenced string.
    name.get() += " Beam";
  }

  std::cout << jim << '\n'; // prints Jim Beam

  return 0;
}
```