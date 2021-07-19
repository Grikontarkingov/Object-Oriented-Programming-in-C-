#include <iostream>
#include "TaskTwo.h"
#include "Bar.h"
#include "Ex.h"

void TaskTwo(){
    Bar bar;
    double n;
    while(true){
        std::cout << "Enter the number (0 is exit): ";

        try{
            std::cin >> n;

            if(n == 0){
                break;
            }

            bar.set(n);
            std::cout << "Bar.y = " << bar.GetY() << std::endl;
        }
        catch(Ex& ex){
            std::cerr << "Error! Ex.x = " << ex.GetX() << std::endl;
        }
    }
}