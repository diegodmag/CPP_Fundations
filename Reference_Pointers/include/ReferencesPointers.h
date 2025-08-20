#pragma once

#include <iostream>
#include <string>



/**
 * Un namespace (espacio de nombres) en C++ es una forma de agrupar identificadores 
 * (funciones, variables, clases, constantes, etc.) bajo un nombre común para evitar 
 * conflictos cuando diferentes partes del código usan el mismo identificador 
 */

namespace references_pointers{

    void introduction_to_references();

    void reference_exercise();

    void print_string_by_reference(const std::string& str);

    void print_val_and_ref_address(int val, int& ref);

    void print_val_and_ref_address_example();

    void print_const_ref(const int& ref);

    void const_reference_bidings();

    int& return_by_reference(int& ref);

    const int& return_by_const_reference(const int& ref);

    void return_by_ref_example();




    void intro_to_pointers();

    void init_pointers();

    void null_ptrs();

    void handling_const_pointers();

    void print_by_value(std::string val);

    void print_by_reference(const std::string& ref);

    void print_by_address(std::string const * ptr);

    void different_argument_passing();

    void showing_ptr_address(std::string * ptr_str);

    void showing_passing_value_pointers();

    void pointer_verification(int * ptr);

    void pointer_verification_example();

    void printIDNumber(const int* id=nullptr);

    // Passing by address 
    void passing_by_adress(int* ptr);

    void passing_by_adress_const(const int* ptr);

    void passing_by_address_example();

    // Returning by address 
    int* return_by_address(int* ptr);

    const int* return_by_address_const(const int* ptr);

    void return_by_address_example();



    void nullify( int*& refptr);

    const int& get_int_ref(const int& ref);

    void sort2(int& x_out, int& y_out);
};

