#include <algorithm>
#include "ReferencesPointers.h"

// using namespace std; 


// Before this topic is lvalues and rvalues 
// -->   https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/


// Lvalues and Rvalues

void references_pointers::introduction_to_references(){
    int x { 5 }; // < lvalue 
    int y { 6 }; //< - lvalue 

    y+= 1; //<- 

    int& ref { x }; // ref is now an  alias for x

    ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref)
    // The above line does NOT change ref into a reference to variable y!

    std::cout << x << '\n'; // user is expecting this to print 5
}

void references_pointers::reference_exercise(){
    int x{ 1 }; // El objeto al que se referencia tiene que ser un lvalue 
    int& ref{ x }; 
    
    const int z {5};    
    const int& ref_to_z {z}; 

    int w {40};
    const int& refet_to_w {w}; // <-- 

    //std::cout << x 
    std::cout << x << ref << '\n';

    int y{ 2 };
    ref = y; 
    // ref = x 
    // ref = y -> x = y -> x = 2 
    // ref = x = 2 
    y = 3;
    

    std::cout << x << ref << '\n';

    ref = 6;

    std::cout << x << ref << '\n';
}


/**
 * Introduction to passing by value, reference and address 
 * 
 */

/**
 * 
 * When an object is passed by value, the function parameter receives a copy of the argument. 
 * This means that any changes to the value of the parameter are made to the copy of the argument, 
 * not the argument itself
 * 
 */

/**
 * Pass by reference allows us to pass arguments to a function without 
 * making copies of those arguments each time the function is called. 
*/

/**
 * Parameter as reference type , so each reference parameter is bind as an alias to the appropiate argument 
 * No copy of the argument is made
 * Binding a reference to a lvalue is always inexpensive , beacuse a reference acts as an alias for the object 
 */

void references_pointers::print_string_by_reference(const std::string& str){

    std::cout << str << '\n';
}//str is destroyed here 


/**
 * CHECK:
 * This function shows the difference betwwen the pass by reference and pass by valu
*/
void references_pointers::print_val_and_ref_address(int val, int& ref){
    std::cout << "The address of the value parameter is : " << &val << '\n';
    std::cout << "The address of the reference parameter is : " << &ref << '\n';

    std::cout << ((&val == &ref)? "true" : "false") << '\n';
}

void references_pointers::print_val_and_ref_address_example(){
    int num_value = 10;

    int& num_ref {num_value};

    
    std::cout << "The address of the value parameter is : " << &num_value << '\n';
    std::cout << "The address of the reference parameter is : " << &num_ref << '\n';
    
    std::cout << ((&num_value == &num_ref)? "true" : "false") << '\n';
    
    std::cout << '\n';

    print_val_and_ref_address(num_value, num_ref);
}

void references_pointers::print_const_ref(const int& ref){
    std::cout << "Printing a const ref : " << ref << '\n';
}


/**
 * BESTPRACTICE:
 * Passing by const reference offers the same primary benefits ass pass by non const reference 
 * (avoiding making a copy of the argument), while also guaranteeing that the function can not change the value being referenced
*/
void references_pointers::const_reference_bidings(){
        
    int x {6}; 
    //We can bind a const ref to a non const (or modifiable) lvalue 
    const int& ref_to_non_const {x};

    const int y{56};
    //Also we can bind a const ref to a const lvalue  
    const int& ref_to_const {y};

    // This is a strange behavior because it is valid bind a const ref to a rvalue 
    const int& ref_to_rvalue {5+10};

    
    print_const_ref(x);

    print_const_ref(ref_to_const);

    print_const_ref(ref_to_rvalue);

}

int& references_pointers::return_by_reference(int& ref){
    return ref; 
}

const int& references_pointers::return_by_const_reference(const int& ref){
    return ref; 
}

void references_pointers::return_by_ref_example(){

    int num {45};

    std::cout << "Value: " << num << " Address: "<< &num << '\n';

    std::cout << "Ref Value: "<< return_by_reference(num) <<" Address: "  << &return_by_reference(num) << '\n';

    return_by_reference(num) +=10; 

    std::cout << "Const Ref Value: "<< return_by_const_reference(num) <<" Address: "  << &return_by_const_reference(num) << '\n';

    std::cout << ((&num == &return_by_reference(num) && &return_by_reference(num) == &return_by_const_reference(num))? "true" : "false" )<< '\n';

    // (bool) ? true : false

}

/**
 * WARNING:
 * Once a reference has been asigned, it cannot be changed
 */


/**
 * BESTPRACTICE: 
 * 
 * Favor passing by const reference over passing by non-const reference 
 * unless you have a specific reason to do otherwise (e.g. the function needs to change the value of an argument).
 */


// WHEN TO PASS BY VALUE vs PASS BY REFERENCE
/**
 * Fundamental types and enumerated types are cheap to copy, 
 * so they are typically passed by value. 
 * 
 * Class types can be expensive to copy (sometimes significantly so), 
 * so they are typically passed by const reference.
 */




/**
 * POINTERS:
 */
// (PASS BY ADREESS)


/**
 * 
 * Given a memory address, we can use the dereference operator (*) 
 * to get the value at that address (as an lvalue). It returns the memory address of its operand.
 * 
 * 
 * The address-of operator (&) and dereference operator (*) 
 * work as opposites: address-of gets the address of an object, 
 * and dereference gets the object at an address.
 */

 /**
  * POINTER:
  * A pointer is an object that holds a memory address (typically of another variable) as its value.
  * This allows us to store the address of some other object to use later.
  */

/**
 * REMINDER:
 * The address-of operator (&) returns a pointer.
 */


void references_pointers::intro_to_pointers(){

    int y{50};

    int& ref_y {y}; //a reference 

    int* ptr_y {&y}; //pointer

    std::cout << "The reference to the variable " << ref_y << '\n';
    
    std::cout << "The address of the variable " << &y << '\n';

    std::cout << "The de-refered value of the variable's address " << *(&y) << '\n';
    
    std::cout << "The pointer that stores the value's address: " << ptr_y << '\n';

    std::cout << "The de-refered value from the pointer : " << *ptr_y << '\n';

    // Could be a good example
    //null_ptrs();

}

/**
 * WARNING:
 * int* ptr3, * ptr4; // correct: ptr3 and ptr4 are both pointers to an int
 * int* ptr1, ptr2;   // incorrect: ptr1 is a pointer to an int, but ptr2 is just a plain int!
 */

/**
 * DIFFERENCES:
 * 
 * References must be initialized, pointers are not required to be initialized (but should be).
 * References are not objects, pointers are.
 * References can not be reseated (changed to reference something else), pointers can change what they are pointing at.
 * References must always be bound to an object, pointers can point to nothing.
 * /


/**
 * WARNING: 
 * 
 * Dereferencing an invalid pointer will lead to undefined behavior. 
 * Any other use of an invalid pointer value is implementation-defined.
 */

void references_pointers::null_ptrs(){
    int* ptr_to_int_0; 
    std::cout << *ptr_to_int_0  << '\n';
    std::cout << "--------" << '\n';
    int* ptr_to_int_1 {};
    std::cout << *ptr_to_int_1 << '\n';
    std::cout << "--------" << '\n';
    int* ptr_to_int_2 {nullptr};
    std::cout << *ptr_to_int_2 << '\n';
    std::cout << "--------" << '\n';
}

void references_pointers::init_pointers(){
    int x{ 5 };

    int* ptr;        // an uninitialized pointer (holds a garbage address)
    int* ptr2{};     // a null pointer (we'll discuss these in the next lesson)
    int* ptr3{ &x }; // a pointer initialized with the address of variable x

 }


void references_pointers::handling_const_pointers(){

    int x {5}; 
    std::cout << "x = " << x << '\n';

    int* ptr_to_x {&x};
    
    *ptr_to_x = 45;

    std::cout << "x = " << x << '\n';

    // int * ptr {&x}; //<< This is not valid 

    // POINTER TO CONST 
    
    const int y = 8; 

    const int* ptr_to_y {&y}; 
 
    std::cout<< "Ptr_to_y derefered value " << *ptr_to_y << '\n';

    int z {50}; 

    ptr_to_y = &z; 

    std::cout<< "Ptr_to_y derefered value " << *ptr_to_y << '\n';

    //CONST POINTER 
    //A const pointer is a pointer whose address can not be changed after initialization.

    int * const conts_ptr {&z}; 


    const int * const conts_ptr_const {&z}; 

}

//PASS BY ADRESS != PASS BY REFERENCE 
/**
 * instead of providing an object as an argument, the caller provides an object’s address (via a pointer).
 * This pointer (holding the address of the object) is copied into a pointer parameter of the called function
 * (which now also holds the address of the object).
 * The function can then dereference that pointer to access the object whose address was passed.
 */


//Different kind of passing 

void references_pointers::print_by_value(std::string val){
    std::cout << val << '\n'; // Print the value copying it into val 
}

void references_pointers::print_by_reference(const std::string& ref){
    std::cout << ref << '\n'; // The function parameter is a reference that binds to str
}

/**
 * REMINDER:
 * a parameter is the actual signature in the method or fucntion,
 * while the argument is the value that is pass to that function when is called
 */

void references_pointers::print_by_address(const std::string * ptr){ // The function parameter is a pointer that holds the address of str
     
    //REMEMBER THERE ARE 

    // Pointers to const values (lvalues) std::string const * ptr_to_const 
    // It means, the pointer cannot modify the value which is pointint at 

    //AND
    
    // Const pointers std::string * const const_ptr 
    // It means, the pointer is pointing to a value and it cannot point to other value 

    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

void references_pointers::different_argument_passing(){
    std::string hello {"Hello World"};

    std::string* conts_ptr {&hello};

    print_by_value(hello);

    print_by_reference(hello);

    print_by_address(conts_ptr);

    //Or we could use 
    //print_by_address(&hello);
}

/**
 * REMINDER:
 * When we pass the address of a variable as an argument using the address-of (&) operator
 * we say the variable is passed by address.
 */

/**
 * When we have a pointer variable holding the address of an object, 
 * and we pass the pointer as an argument to a parameter of the same type, 
 * WE SAY THE OBJECT IS PASSED BY ADRESS AND THE POINTER BY VALUE.
 * This means, that we are copying the pointer (passing by value the pointer)
 * holding the address of an object. But the address is the same.
 * 
 */

void references_pointers::showing_ptr_address(std::string * ptr_str){
    std::cout << "Pointer derefered value is: "<<*ptr_str << '\n';
    std::cout << "Pointer value is: "<<ptr_str<<'\n';
    std::cout << "Pointer Address: " << &ptr_str << '\n';
}

void references_pointers::showing_passing_value_pointers(){
    std::string hello = "Hello World!";

    std::string * ptr_hello {&hello}; 

    std::cout << "Pointer derefered value is: "<<*ptr_hello << '\n';
    std::cout << "Pointer value is: "<<ptr_hello<<'\n';
    std::cout << "Pointer Address: "<<&ptr_hello << '\n';

    std::cout << '\n';
    
    showing_ptr_address(ptr_hello);

}

/**
 * When passing a parameter by address, 
 * care should be taken to ensure the pointer is not a null pointer before you dereference the value. 
 */

void references_pointers::pointer_verification(int * ptr){
    if (ptr) // if ptr is not a null pointer
    {
        std::cout << *ptr << '\n';
    }
    else if(ptr == nullptr){
        std::cout << "El puntero es nullptr" << '\n';
    }
    else{
        std::cout<< "El puntero es nulo o no tiene contenido" << '\n';
    }
}



void references_pointers::pointer_verification_example()
{
    int x {5}; 
    int * ptr_int = &x; 

    int * ptr_int_2 {};

    int * ptr_int_3 {nullptr};


    pointer_verification(ptr_int);

    pointer_verification(ptr_int_3);

}

/**
 * REMINDER:
 * Pass by reference has the same benefits as pass 
 * by address without the risk of inadvertently dereferencing a null pointer.
 */

 /**
  * BESTPRACTICE:
  * Best practice: Prefer pass by reference to pass by address 
  * unless you have a specific reason to use pass by address.
  */

/**
 * REMINDER:
 * Pointers must hold the address of an object, and references aren’t objects
 */

/**
 * REMINDER:
 * AN OBJECT ONLY IS THE SAME OBJECT IF IT HAS THE SAME MEMORY ADDRESS
 */


//Passing by adress PT 2 << MAYBE THIS PART COULD BE OPTIONAL FOR THE VISUALIZATION COURSE 


/**
 * Passing by adress allows function to receive a optional argument
 */

 /**
  * In this exampleg, the only parameter is defaulted to nullptr so, without an argument, the parameter is 
  * passed with its default value to the function
  */
void references_pointers::printIDNumber(const int* id){
    if(id)
        std::cout << "Your ID NUMBER is " << *id << '\n';
    else
        std::cout << "Your ID number is unknown  " << '\n';      
    
}


void references_pointers::nullify( int*& refptr)
{
    refptr = nullptr; // Make the function parameter a null pointer
}

//pointers must hold the address of an object, and references aren’t objects

// >>> IMPORTANT -> nullptr has type std::nullptr_t 



// >>> RETURN BY REFERENCE 

/**
 * Return by reference returns a reference that is bound to the object being returned,
 *  which avoids making a copy of the return value.
 */

// std::string&       returnByReference(); // returns a reference to an existing std::string (cheap)
// const std::string& returnByReferenceToConst(); // returns a const reference to an existing std::string (cheap)

// const std::string& getProgramName()
// {
//     const std::string programName { "Calculator" }; // now a non-static local variable, destroyed when function ends

//     return programName;
// }


/**
 * WARNING:
 * 
 * Objects returned by reference must live beyond the scope of the function returning the reference, 
 * or a dangling reference will result. Never return a (non-static) local variable or temporary by reference.
 */

const int& references_pointers::get_int_ref(const int& ref){
    return ref; 
}
/**
 * If a parameter is passed into a function by reference, it’s safe to return that parameter by reference. 
 * This makes sense: in order to pass an argument to a function, the argument must exist in the scope of 
 * the caller. When the called function returns, that object must still exist in the scope of the caller.
 */


//IN and OUT parameters 

//In-parameters are typically passed by value or by const reference.

//Out-parameters 

/**
 * A function argument passed by non-const reference (or by pointer-to-non-const) 
 * allows the function to modify the value of an object passed as an argument. 
 * This provides a way for a function to return data back to the caller in cases 
 * where using a return value is not sufficient for some reason.
 */

 /**
  * A function parameter that is used only for the purpose of returning 
  * information back to the caller is called an out parameter.
  */

/**
 * Write a function named sort2 which allows the caller to pass 2 int variables as arguments. 
 * When the function returns, the first argument should hold the lesser of the two values, 
 * and the second argument should hold the greater of the two values.
 * 
 * Hint: The std::swap() function (in the <algorithm> header) can be used to swap the values of two variables.
 *  e.g. std::swap(x, y) swaps the values of the variables x and y. 
 */

// int& max(int &x, int &y) { return x > y ? x : y; }

void references_pointers::sort2(int& x_out, int& y_out){

    if(y_out < x_out)
        std::swap(x_out,y_out);

}

// Passing by Address 

void references_pointers::passing_by_adress(int* ptr){
    //El parametro de la funcion es un puntero a constante 
    std::cout << "Value: "<<*ptr <<'\n';
    std::cout << "Value address: "<<&(*ptr) <<'\n';
    std::cout << "Pointer: "<<ptr <<'\n';
    *ptr += 100; 
}

void references_pointers::passing_by_address_example(){

    int x {50};
    int* ptr_to_x{&x}; 

    std::cout << "Value: "<<x <<'\n';
    std::cout<< "X Address: " << &x << '\n';
    std::cout << "Pointer: "<<ptr_to_x <<'\n';
    std::cout<< "------"  << '\n';

    passing_by_adress(ptr_to_x);
    std::cout<< "------"  << '\n';

    std::cout << "Value: "<<x <<'\n';
    std::cout<< "X Address: " << &x << '\n';

}

// Return by Address 

int* references_pointers::return_by_address(int* ptr){
    return ptr; 
}

const int* references_pointers::return_by_address_const(const int* ptr){
    return ptr;
}

void references_pointers::return_by_address_example(){

    int some_number {50};

    int * ptr_to_num = &some_number; 

    std::cout<< "Ptr value: "<<ptr_to_num<<'\n';
    std::cout<< "Ptr dereferenced value "<<*ptr_to_num<<'\n';

    std::cout<< '\n';
    std::cout<< "Returning by address and modifying" << '\n';

    int * ptr_2 {return_by_address(ptr_to_num)};

    std::cout<< "Ptr_2 value: "<<ptr_2<<'\n';
    std::cout<< "Ptr_2 dereferenced value "<<*ptr_2<<'\n';

    std::cout<< '\n';
    //Como la funcion regresa un puntero modificable es posible modificar el valor por medio de llamar la funcion
    *return_by_address(ptr_2) = 355; 
    std::cout << "After modifying dereferenced value " << '\n';
    

    //Ambos punteros modifican el mismo objeto 
    std::cout<< "Ptr dereferenced value "<<*ptr_2<<'\n';
    std::cout<< "Ptr_2 dereferenced value "<<*ptr_2<<'\n';

    //Ahora con punteros constantes 
    std::cout<< '\n';
    std::cout << "Using pointer to const " << '\n';
    const int* ptr_to_const {return_by_address_const(ptr_2)}; 

    std::cout << "Ptr to const  value "<<ptr_to_const<<'\n';
    std::cout << "Ptr to const dereferenced value "<<*ptr_to_const<<'\n';

    // No es posible por que es un constante
    // *return_by_address_const(ptr_2)=0;
    
}

// int main()
// {

//     // int x = 6666; 
//     // int y = 222; 
//     // std::cout << "X :" << x << '\n';
//     // std::cout << "Y :" << y << '\n';


//     // sort2(x,y);

//     // std::cout << "Applying sort" << '\n';

//     // std::cout << "X :" << x << '\n';
//     // std::cout << "Y :" << y << '\n';

//     int x { 5 };
//     ++x; // This expression statement has the side-effect of incrementing x
//     std::cout << x << '\n'; // prints 6

//     return 0;

// }

//But the majority of times, overloading is a better alternative 

// void printIDNumber()
// {
//     std::std::cout << "Your ID is not known\n";
// }

// void printIDNumber(int id)
// {
//     std::std::cout << "Your ID is " << id << "\n";
// }

// >> Changing what a pointer parameter points at
/**
 * Remember that a pointer is passed by value and thats is fast, but what happend if we want to 
 * change what a pointer is pointing at ? 
 * 
 * Consider : 
 */

// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
// void nullify([[maybe_unused]] int* ptr2)
// {
//     //AN OBJECT ONLY IS THE SAME OBJECT IF IT HAS THE SAME MEMORY ADDRESS 
//     std::cout << "ptr2 address :" << &ptr2 << '\n';
//     ptr2 = nullptr; // Make the function parameter a null pointer
// }

// On order to modify our pointer we do Pass by address… by reference?
//Just like we can pass a normal variable by reference, we can also pass pointers by reference.

