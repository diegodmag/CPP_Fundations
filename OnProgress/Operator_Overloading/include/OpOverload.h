#ifndef OPOVERLOAD_h
#define OPOVERLOAD_h

namespace op_overloading{
    
    // 1. Introduction to function overloading
    
        // Function Overloading permite crear multiple funciones con el mismo nombre 
        // pero con distinto tipo de parametros. 
        // Para que se pueda hacer el overloading laas funciones tienen que poder 
        // ser diferenciables para el compilador
    int add(int x, int y); 
    double add(double x, double y);
    void FunctionOverloadingExample();

    // 2. Operator Overloading
        // En C++ los operadores (+,=,-) son implementados como funciones, por medio de usar
        // sobrecarga de funciones podemos cambiar el comportamiento de un operador que funcionen
        // con los distintos tipos de dato.

    // Overloading operadores aritmeticos (+,-,*,/)

    class Cents{
        private: 
            int m_cents{};
        public:
            Cents(int cents)
            :   m_cents{cents}{

            }
            
            int getCents() const {return m_cents;}

            // Se sobrecarga el operador de suma para la clase de Cents  
            // Es una funcion miembro 
            Cents operator+(Cents& c2) const; 
            
            void operator+(Cents& c2); 

            void operator-(Cents& c2);


        };
        
        // This is not a member function 
        Cents operator+(const Cents& c1, const Cents& c2);

        // Ejemplo 
        void OperatorAsMemberFunction();


}

#endif