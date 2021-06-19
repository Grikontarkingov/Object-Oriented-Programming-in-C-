#include <iostream>
#include <cmath>
#include <cstdint>

class Power{
private:
    double m_first = 2.0;
    double m_second = 3.0;

public:
    void setTaskOne(double x, double y){
        m_first = x;
        m_second = y;
    }

    void calculate(){
        std::cout << "Number " << m_first << " pow of " << m_second << " is " << pow(m_first, m_second) << std::endl;
    }
};

void CallPower(){
    Power taskOne;
    taskOne.calculate();
    taskOne.setTaskOne(3.0, 5.0);
    taskOne.calculate();
}

class RGBA{
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;

public:
    RGBA(){}

    RGBA(int red, int green, int blue, int alpha)
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha){}

    void print(){
        std::cout << "Red is " << m_red + 0 << "\nGreen is " << +m_green << "\nBlue is "
        << (unsigned)m_blue << "\nAlpha is " << +m_alpha << std::endl; //не понял как лучше использовать для вывода числа...
    }
};

void CallRGBA(){
    RGBA rgbaDefault;
    rgbaDefault.print();

    RGBA rgbaSet(12, 25, 34, 45);
    rgbaSet.print();
}

class Stack{
private:
    int m_arr[10] = {0};
    int m_index = -1;

public:
    void reset(){
        while(m_index >= 0){
            m_arr[m_index] = 0;
            --m_index;
        }
    }

    bool push(int num){
        if(m_index + 1 >= (sizeof (m_arr) / sizeof(m_arr[0]))){
            return  false;
        }
        else{
            m_index++;
            m_arr[m_index] = num;

            return true;
        }
    }

    void pop(){
        if(m_index >= 0){
            m_arr[m_index] = 0;
            m_index--;
        }
        else{
            std::cout << "Array is empty" << std::endl;
        }
    }

    void print(){
        std::cout << "(";
        for(int i = 0; i <= m_index; i++){
            std::cout << " " << m_arr[i] << " ";
        }

        std::cout << ")" << std::endl;
    }
};

void CallStack(){
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
}

int main() {
    CallPower();
    CallRGBA();
    CallStack();

    return 0;
}
