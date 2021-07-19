#include "Bar.h"
#include "Ex.h"

Bar::Bar(double y) : m_y(y) {};

void Bar::set(double a){
    if(m_y + a > 100){
        throw Ex(a * m_y);
    }
    else{
        m_y = a;
    }
}

double Bar::GetY() const{
    return m_y;
}