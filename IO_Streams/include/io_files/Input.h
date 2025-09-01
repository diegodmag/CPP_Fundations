#include <fstream>
#include <iostream>
#include <string>

#include <vector>

namespace input{

    int basic_example(){

        int x; 

        std::cout<<sizeof(x)<<'\n';

        std::cin>>x; 

        std::cout<<sizeof(x)<<'\n'; 

        std::cout << x <<'\n'; 

        return 0;
    }

    int example_get(){
        char ch{}; // caracter que se va a reasignar cada que extraigamos algo de stream y lo guardemos en ch 

        // Mientras podamos leer un caracter de std::cin
        while (std::cin.get(ch)) {
            std::cout << "Leí: " << ch << '\n';
        }

        return 0; 
            
    }

    // Importante para explicar la extraccion del stream 
    int example_get_2(){
        char strBuf[11]{};
        
        // cin.get lee hasta que encuentra un salto de linea 
        // Read up to 10 characters
        std::cout << "First get " << '\n';
        std::cin.get(strBuf, 11);
        std::cout << strBuf << '\n';
        std::cout << std::cin.gcount() << " characters were read" << '\n';

        // Read up to 10 more characters
        std::cout << "Second get " << '\n';
        std::cin.get(strBuf, 11);
        std::cout << strBuf << '\n';
        std::cout << std::cin.gcount() << " characters were read" << '\n';
        return 0;

        //Para saber cuantos caracteres se extrajeron desde la ultima llamada a getline
        // usamos gcount()
        
    }

    // FILE READING 

    int example_extraction(){

        /**
         * ifstream es utilizado para leer archivos 
         */
        std::ifstream inf{"files/output.txt"};

        if(!inf){
            std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
            return 1;
        }

        std::string strInput{};
        //
        while (inf >> strInput) //Mientras se extraiga del stream, almacenamos lo que sea que sea que se extraiga en strInput
            //Recordemos que el operador de extraccion rompe cada espacio en blanco , para poder
            //leer toda la linea tenemos que usar getline 
            std::cout << strInput << '\n';

        return 0;

    }

    int example_getline(){

        /**
         * ifstream es utilizado para leer archivos 
         */
        std::ifstream inf{"files/output.txt"};

        if(!inf){
            std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
            return 1;
        }

        std::string strInput{};
        while (std::getline(inf, strInput))
            //La funcion manipulador obtiene un caracter del input stream 

            //Recordemos que el operador de extraccion rompe cada espacio en blanco , para poder
            //leer toda la linea tenemos que usar getline 
            std::cout << strInput << '\n';

        return 0;

    }


}
