#ifndef PASSRETURNVECTOR_H
#define PASSRETURNVECTOR_H

#include <iostream>

class PassReturnVector{

public:

    static void passByReference(const std::vector<int>& arr){
        std::cout<<"Element 0: "<<arr[0]<<std::endl;
    }


};


#endif