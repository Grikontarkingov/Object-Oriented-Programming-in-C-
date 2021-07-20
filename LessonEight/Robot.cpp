#include <iostream>
#include "OffTheField.h"
#include "IllegalCommand.h"
#include "Field.h"
#include "Robot.h"

Robot::Robot(){
    m_pos.x = 0;
    m_pos.y = 0;
}

void Robot::right(Field& field){
    int temp = m_pos.x + 1;
    if(temp >= field.getXofField()){
        throw OffTheField();
    }

    field.swap(m_pos.x, m_pos.y, temp, m_pos.y);
    m_pos.x++;
}

void Robot::left(Field& field){
    int temp = m_pos.x - 1;
    if(temp < 0){
        throw OffTheField();
    }

    field.swap(m_pos.x, m_pos.y, temp, m_pos.y);
    m_pos.x--;
}

void Robot::up(Field& field){
    int temp = m_pos.y - 1;
    if(temp < 0){
        throw OffTheField();
    }

    field.swap(m_pos.x, m_pos.y, m_pos.x, temp);
    m_pos.y--;
}

void Robot::down(Field& field){
    int temp = m_pos.y + 1;
    if(temp >= field.getYofField()){
        throw OffTheField();
    }

    field.swap(m_pos.x, m_pos.y, m_pos.x, temp);
    m_pos.y++;
}

void Robot::movement(const std::string& command, Field& field){
    if(command == "right"){
        this->right(field);
    }
    else if(command == "left"){
        this->left(field);
    }
    else if(command == "up"){
        this->up(field);
    }
    else if(command == "down"){
        this->down(field);
    }
    else if(command != "abort"){
        throw IllegalCommand();
    }
}

int Robot::getX() const{
    return m_pos.x;
}

int Robot::getY() const{
    return m_pos.y;
}