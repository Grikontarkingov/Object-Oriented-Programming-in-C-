#include <iostream>
#include "Field.h"

Field::Field(int y, int x) : m_y(y), m_x(x) {
    createField();
    setField();
    m_field[0][0] = 1;
}

Field::~Field(){
    for(int i = 0; i < m_y; ++i){
        delete [] m_field[i];
    }
    delete [] m_field;
}

void Field::printField() const{
    for(int i = 0; i < 10; ++i){
        std::cout << "\"" << "|";
        for(int j = 0; j < 10; ++j){
            std::cout << m_field[i][j] << "|";
        }
        std::cout <<"\"" << std::endl;
    }
}

int Field::getYofField() const{
    return m_y;
}
int Field::getXofField() const{
    return m_x;
}

void Field::swap(int curPosX, int curPosY, int nextPosX, int nextPosY){
    int temp;
    temp = m_field[curPosY][curPosX];
    m_field[curPosY][curPosX] = m_field[nextPosY][nextPosX];
    m_field[nextPosY][nextPosX] = temp;
}

void Field::createField(){
    m_field = new int* [m_y];
    for(int i = 0; i < m_y; ++i){
        m_field[i] = new int[m_x];
    }
}

void Field::setField(){
    for(int i = 0; i < m_y; ++i){
        for(int j = 0; j < m_x; ++j){
            m_field[i][j] = 0;
        }
    }
}