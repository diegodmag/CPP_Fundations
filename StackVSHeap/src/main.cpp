#include <iostream>

// Paso de parametro por valor
// -> Los parametros van a copiarse dentro de la funcion
int fun(int x, int y)
{
    return x + y;
}

struct Vector2D
{
    float m_x{0.0f};
    float m_y{0.0f};

    Vector2D() = default;

    Vector2D(float x, float y)
        : m_x{x}, m_y{y}
    {
    }

    void print()
    {
        std::cout << "Vector2D x: " << m_x << " y: " << m_y << '\n';
    }
    // suma , resta ,etc
};

class Character
{
public:
    Vector2D *position{nullptr};

    Character()
    {
        std::cout << "Character initialization" << '\n';
    }

    ~Character()
    {
        delete position;
        std::cout << "Character destruction" << '\n';
    }

    void setPosition(Vector2D *ptr)
    {
        position = ptr;
    }
};

int main()
{

    // Memory Leak
    {
        Vector2D *u{new Vector2D{2.0f, 2.0f}};
        u->print();
        delete u;
    }

    // int *p = new int[5];
    // p[10] = 1;

    {
        // std::cout<<"Allocating dynamic memory for an array or length 100\n";
        Vector2D * ptr_to_arr {new Vector2D[100]};

        delete[] ptr_to_arr;
        // int * ptr_to_some_int {new int{5}};
        // delete ptr_to_arr;
    }

    // // std::cout << "--- DEMO DANGLING POINTER ---\n";
    // Vector2D *danglingPtr = nullptr;

    // {
    //     // Creamos un Character en el stack dentro de un ámbito temporal
    //     Character hero;
    //     hero.setPosition(new Vector2D(5.0f, 5.0f));

    //     // Guardamos la dirección de la memoria en 'danglingPtr'
    //     danglingPtr = hero.position;

    //     std::cout << "El héroe está en: ";
    //     danglingPtr->print(); // Funciona correctamente aquí
    // }
    // // Al salir de este bloque, 'hero' se destruye automáticamente.
    // // Su destructor '~Character()' ejecuta 'delete position;' liberando la memoria en el Heap
    
    // danglingPtr->print(); // Undefined Behavior
}