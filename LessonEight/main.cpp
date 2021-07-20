#include <iostream>
#include "TaskOne.h"
#include "TaskTwo.h"

class Robot{
public:
    Robot(){
        m_pos.x = 0;
        m_pos.y = 0;
    }

    void right(){
        m_pos.x++;
    }
    void left(){
        m_pos.x--;
    }
    void up(){
        m_pos.y--;
    }
    void down(){
        m_pos.y++;
    }

    void movement(const std::string& command){
        if(command == "right"){
            this->right();
        }
        else if(command == "left"){
            this->left();
        }
        else if(command == "up"){
            this->up();
        }
        else if(command == "down"){
            this->down();
        }
    }

private:
    typedef struct pos{
        int x;
        int y;
    }Pos;

    Pos m_pos{};
};

class Field{
public:
    Field(){
        field[0][0] = 1;
    }

    void printField() const{
        for(int i = 0; i < 10; ++i){
            std::cout << "\"" << "|";
            for(int j = 0; j < 10; ++j){
                std::cout << field[i][j] << "|";
            }
            std::cout <<"\"" << std::endl;
        }
    }

    void swap(, int& b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

private:
    int field[10][10]{0};
};

void TaskThree(){
    Field field{};
    field.printField();
    Robot robot;
    std::string command;
    do{
        std::cout << "Please enter command (right/left/up/down or abort to exit): ";
        std::cin >> command;
        std::cout << std::endl;
        robot.movement(command);

    }while(command != "abort");

}

int main() {
    /*TaskOne();
    TaskTwo();*/
    TaskThree();

    return 0;
}
