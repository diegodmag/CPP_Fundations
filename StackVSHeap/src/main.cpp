#include <iostream>


void modifiyArray(int * array, int length, int index, int new_value)
{
    if(!(index < length)) return ; 

    array[index] = new_value; 
    
}

void printArray(int * array, int length)
{
    std::ostream stream {''}; 
    for (int i = 0; i < length; i++)
    {
        std::cout<
    }
    
}

int main()
{
    // int * ptr {new int(5)};

    // int* ptr_2 {new int}; 

    int numbers[] = {1,2,3,4,5}; 




    // std::cout<<"Ptr :"<<ptr<<'\n';
    // std::cout<<"Ptr2 :"<<ptr_2<<'\n';
    


    return 0;
}