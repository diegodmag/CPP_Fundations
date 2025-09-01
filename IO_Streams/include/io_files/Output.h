#include <fstream>
#include <iostream>

#ifndef OUTPUT_H
#define OUTPUT_H

namespace output{
    
    

    int example(){
        /**
         * ofstream es usando para escribir en archivos 
         * si no existe lo crea 
         */
        std::ofstream outf{"files/created_output.txt"};

        // Si no se logró abrir existosamente nos salimos 
        if(!outf){
            std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
            return 1;
        }

        // Escribimos dos lineas en el archivo
        outf<<"This is line 1\n";
        outf<<"This is line 2\n";

        return 0; 

        
        /**
         * cuando outf sale del ambito de la funcion, 
         * el destructor de ofstream cerrara el archivo.
         */
    }

}


#endif