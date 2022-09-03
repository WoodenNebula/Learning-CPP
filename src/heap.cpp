#include <iostream>

using namespace std;

int main(){

    int val = 15;   //  Stack Declaration and Initialized
    std::cout << val << std::endl;

    int* h_val = new int;    //  Heap Declaration
    *(h_val) = 5;        //Heap initialzed

    std::cout << h_val << std::endl;
    std::cout << *(h_val) << std::endl;

    h_val = &val;    //  Pointer to val
    
    std::cout << h_val << std::endl;
    std::cout << *(h_val) << std::endl;

    int array[5];       //stack array declaration
    int* h_array = new int[5];      //heap array declaration

    /* Stack Initialization*/
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

    /* Heap Initialization */
    h_array[0] = 9;
    h_array[1] = 8;
    h_array[2] = 7;
    h_array[3] = 6;
    h_array[4] = 5;

    for (int i = 0; i < size(array); i++){
        std::cout << array[i];
    }
    
    std::cout << std::endl;

    for (int i = 0; i < 5; i++){
        std::cout << h_array[i];
    }

    h_array = array;

    std::cout << std::endl;

    for (int i = 0; i < 5; i++){
        std::cout << h_array[i];
    }
}