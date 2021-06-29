#include <iostream>
#include <cmath>

class Figure{
public:
    virtual double area() = 0;
};

class Parallelogram : public Figure{
protected:
    int m_length;
    int m_height;

public:
    Parallelogram(int length, int height)
    : m_length(length), m_height(height){}

    virtual double area() override{ return m_length * m_height; }

};

class Circle : public Figure{
private:
    int m_radius;

public:
    Circle(int radius)
    : m_radius(radius){}

    double area() override { return M_PI * pow(m_radius, 2); }
};

class Rectangle : public Parallelogram{
public:
    Rectangle(int length, int width)
    : Parallelogram(length, width){}

    virtual double area() override{ return m_length * m_height; }
};

class Square : public Parallelogram{
public:
    Square(int length)
    : Parallelogram(length, length){}

    double area() override { return  pow(m_length, 2); }
};

class Rhombus : public Parallelogram{
public:
    Rhombus(int length, int height)
    : Parallelogram(length, height){}

    double area() override { return m_length * m_height; }
};

void TaskOne(){
    Parallelogram parallelogram(3,5);
    Circle circle(4);
    Rectangle rectangle(4,7);
    Square square(5);
    Rhombus rhombus(7,3);

    Figure *figure = &parallelogram;
    std::cout << "Area of parallelogram: " << figure->area() << std::endl;

    figure = &circle;
    std::cout << "Area of circle: " << figure->area() << std::endl;

    figure = &rectangle;
    std::cout << "Area of rectangle: " << figure->area() << std::endl;

    figure = &square;
    std::cout << "Area of square: " << figure->area() << std::endl;

    figure = &rhombus;
    std::cout << "Area of rhombus: " << figure->area() << std::endl;
}

class Car{
protected:
    std::string m_company;
    std::string m_model;

public:
    Car(std:: string company, std::string model)
    : m_company(company), m_model(model){ std::cout << "Class \"Car\" - company: " << m_company << " and model: " << m_model << std::endl; }
};

class PassengerCar : virtual public Car{
public:
    PassengerCar(std:: string company, std::string model)
    : Car(company, model){ std::cout << "Class \"PassengerCar\" - company: " << m_company << " and model: " << m_model << std::endl; }
};

class Bus : virtual public Car{
public:
    Bus(std:: string company, std::string model)
    : Car(company, model){ std::cout << "Class \"Bus\" - company: " << m_company << " and model: " << m_model << std::endl; }
};

class Minivan : virtual public PassengerCar, virtual public Bus{
public:
    Minivan(std:: string company, std::string model)
    : Car(company, model), PassengerCar(company, model), Bus(company, model){
        std::cout << "Class \"Virtual Minivan\" - company: " << m_company << " and model: " << m_model << std::endl;
    }

};

void TaskTwo(){
    Car car("\"company\"", "\"model\"");
    PassengerCar passengerCar("Lada", "Niva Chevrolet");
    Bus bus("PAZ", "4234");
    Minivan("Citroen", "Evasion");
}

class Fraction{
private:
    int m_numerator;
    int m_denominator;

    int checkDenominator(int denominator){
        int a;
        if(denominator == 0){
            std::cout << "Denominator cannot be 0! Re-enter denominator, please: ";
            std::cin >> a;
            return checkDenominator(a);
        }
        else{
            return denominator;
        }
    }
    int NOD(int x, int y){
        int a = abs(x);
        int b = abs(y);

        if(a == b){
            return  a;
        }
        else if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }

        return NOD(a, b - a);
    }

public:
    Fraction(int numerator = 1, int denominator = 1){
        if(numerator < 0 && denominator < 0){
            m_numerator = -numerator;
            m_denominator = checkDenominator(-denominator);
        }
        else if(numerator > 0 && denominator < 0){
            m_numerator = -numerator;
            m_denominator = checkDenominator(-denominator);
        }
        else{
            m_numerator = numerator;
            m_denominator = checkDenominator(denominator);
        }
    }

    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);

    Fraction operator-()const{ return Fraction(-m_numerator, m_denominator); }

    friend bool operator>(Fraction f1, Fraction f2);
    friend bool operator<(Fraction f1, Fraction f2);
    friend bool operator>=(Fraction f1, Fraction f2);
    friend bool operator<=(Fraction f1, Fraction f2);
    friend bool operator==(Fraction f1, Fraction f2);
    friend bool operator!=(Fraction f1, Fraction f2);

    void getFraction() const{ std::cout << m_numerator << "/" << m_denominator << std::endl; }
    int getNumerator() const { return m_numerator; }
    int getDenominator() const { return m_denominator; }
};

Fraction operator+(const Fraction &f1, const Fraction &f2)  {
    Fraction fracSum;
    fracSum.m_denominator = f1.m_denominator * f2.m_denominator;
    fracSum.m_numerator = (f1.m_numerator * f2.m_denominator) + (f2.m_numerator * f1.m_denominator);

    int nod = fracSum.NOD(fracSum.m_numerator, fracSum.m_denominator);
    fracSum.m_numerator /= nod;
    fracSum.m_denominator /= nod;

    return  fracSum;
}

Fraction operator-(const Fraction &f1, const Fraction &f2) {
    Fraction fracMinus;
    fracMinus.m_denominator = f1.m_denominator * f2.m_denominator;
    fracMinus.m_numerator = (f1.m_numerator * f2.m_denominator) - (f2.m_numerator * f1.m_denominator);

    int nod = fracMinus.NOD(fracMinus.m_numerator, fracMinus.m_denominator);
    fracMinus.m_numerator /= nod;
    fracMinus.m_denominator /= nod;

    return  fracMinus;
}

Fraction operator*(const Fraction &f1, const Fraction &f2) {
    Fraction fracComposition;
    fracComposition.m_numerator = f1.m_numerator * f2.m_numerator;
    fracComposition.m_denominator = f1.m_denominator * f2.m_denominator;

    int nod = fracComposition.NOD(fracComposition.m_numerator, fracComposition.m_denominator);
    fracComposition.m_numerator /= nod;
    fracComposition.m_denominator /= nod;

    return fracComposition;
}

Fraction operator/(const Fraction &f1, const Fraction &f2) {
    Fraction fracQuotient;
    fracQuotient.m_numerator = f1.m_numerator * f2.m_denominator;
    fracQuotient.m_denominator = f1.m_denominator * f2.m_numerator;

    int nod = fracQuotient.NOD(fracQuotient.m_numerator, fracQuotient.m_denominator);
    fracQuotient.m_numerator /= nod;
    fracQuotient.m_denominator /=nod;

    return fracQuotient;
}

bool operator>(Fraction f1, Fraction f2) {
    f1.m_numerator *= f2.m_denominator;
    f2.m_numerator *= f1.m_denominator;

    return f1.m_numerator > f2.m_numerator;
}

bool operator<(Fraction f1, Fraction f2) {
    f1.m_numerator *= f2.m_denominator;
    f2.m_numerator *= f1.m_denominator;

    return f1.m_numerator < f2.m_numerator;
}

bool operator>=(Fraction f1, Fraction f2) { return !(f1 < f2); }

bool operator<=(Fraction f1, Fraction f2) { return !(f1 > f2); }

bool operator==(Fraction f1, Fraction f2) {
    f1.m_numerator *= f2.m_denominator;
    f2.m_numerator *= f1.m_denominator;

    return (f1.m_numerator == f2.m_numerator);
}

bool operator!=(Fraction f1, Fraction f2) { return !(f1 == f2); }

void TaskThree(){
    Fraction fractionOne(3, 5);
    std::cout << "Fraction one: ";
    fractionOne.getFraction();

    Fraction fractionTwo(4, 6);
    std::cout << "Fraction two: ";
    fractionTwo.getFraction();

    std::cout << "Sum of two fraction: ";
    Fraction fracSum = fractionOne + fractionTwo;
    fracSum.getFraction();

    std::cout << "Subtraction of two fraction: ";
    Fraction fracSub = fractionOne - fractionTwo;
    fracSub.getFraction();

    std::cout << "Composition of two fraction: ";
    Fraction fracComp = fractionOne * fractionTwo;
    fracComp.getFraction();

    std::cout << "Quotation of two fraction: ";
    Fraction fracQuot = fractionOne / fractionTwo;
    fracQuot.getFraction();

    Fraction fracUnary(-3, -5);
    std::cout << "Opposite fraction: " << -fracUnary.getNumerator() << "/" << fracUnary.getDenominator() << std::endl;

    Fraction fracFour(3,5);
    Fraction fracFive(4,6);
    Fraction fracSix(3,5);

    if(fracFive > fracFour){ std::cout << "First fraction more then second" << std::endl; }
    if(fracFour < fracFive){ std::cout << "First fraction less then second" << std::endl; }
    if(fracFive >= fracFour){ std::cout << "First fraction more or equal then second" << std::endl; }
    if(fracFour <= fracFive){ std::cout << "First fraction less or equal then second" << std::endl; }
    if(fracFour == fracSix){ std::cout << "First fraction equal second" << std::endl; }
    if(fracFour != fracFive) { std::cout << "First fraction not equal second" << std::endl; }

}

enum suit {DIAMONDS = 'D', HEARTS = 'H', CLUBS = 'C', SPADES = 'S'};
enum value {SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10, ACE = 1};

class Card{
private:
    suit m_suit;
    value m_value;
    bool position;

public:
    void Flip(){
        if(!position){
            position = true;
        }
    }

    int GetValue(){
        return m_value;
    }
};

int main()
{
    TaskOne();
    TaskTwo();
    TaskThree();

    return 0;
}
