#include <iostream>
#include "OffTheField.h"
#include "IllegalCommand.h"
#include "Field.h"
#include "Robot.h"
#include "TaskThree.h"

void TaskThree(){
    Field field(10, 10);
    Robot robot;
    std::string command;
    do{
        try{
            field.printField();
            std::cout << "Please enter command (right/left/up/down or abort to exit): ";
            std::cin >> command;
            std::cout << std::endl;
            robot.movement(command, field);
        }
        catch(OffTheField& exception) {
            std::cerr << exception.getError() << "\nCurrent position - [" << robot.getY()
                      << "," << robot.getX() << "] and command - " << command << std::endl;
        }
        catch(IllegalCommand& exception) {
            std::cerr << exception.getError() << "\nCurrent position - [" << robot.getY()
                      << "," << robot.getX() << "] and command - " << command << std::endl;
        }
    }while(command != "abort");
}
