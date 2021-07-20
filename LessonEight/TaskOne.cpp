#include <iostream>
#include "TaskOne.h"

template <typename T>
double division(T a, T b){
    if(b == 0){
        throw "DivisionByZero";
    }

    return (a/b);
}

void TaskOne(){
    try{
        std::cout << "The division: " << division(5.0, 7.0) << std::endl;
    }
    catch(const char* exception){
        std::cerr << exception << std::endl;
    }
}
