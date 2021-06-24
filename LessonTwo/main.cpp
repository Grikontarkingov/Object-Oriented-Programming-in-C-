#include <iostream>


enum gender{MALE = 'M', FEMALE = 'F', UNKNOWN = 'U'};

class Person{
protected:
    std::string m_name;
    int m_age;
    gender m_gender;
    int m_weight;

public:
    Person(std::string name = "Noname", int age = 0, gender a = UNKNOWN, int weight = 0)
    : m_name(name), m_age(age), m_gender(a), m_weight(weight){

    }
    void setName(std::string name){ m_name = name; }
    void setAge(int age){ m_age = age; }
    void setWeight(int weight){ m_weight = weight; }
};

class Student : public Person{
private:
    int m_yearOfStudy;
    inline static int m_counter = 0;

public:
    Student(std::string name = "Noname", int age = 0, gender a = UNKNOWN, int weight = 0, int yearOfStudy = 0)
    : Person(name, age, a, weight), m_yearOfStudy(yearOfStudy){}

    void setYearOfStudy(int yearOfStudy){ m_yearOfStudy = yearOfStudy; }

    void increaseYearOfStudy(){ m_yearOfStudy++; }

    void increaseCounter(){ m_counter++; }

    static int getCounter(){ return  m_counter; }

    friend void getStudent(const Student &s);

    ~Student(){ m_counter--; }
};

void getStudent(const Student &s){
    std::cout << "Name: " << s.m_name << ", age: " << s.m_age << ", gender: " << (char)s.m_gender
              << ", weight:" << s.m_weight << ", year of study: " << s.m_yearOfStudy << std::endl;
}

void TaskOne(){
    Student list[10];

    Student first;
    list[0] = first;
    first.increaseCounter();

    Student second;
    list[1] = second;
    second.increaseCounter();

    Student third("Ivan", 20, MALE, 89, 1);
    list[2] = third;
    third.increaseCounter();

    Student fourth;
    list[3] = fourth;
    fourth.increaseCounter();

    Student fifth;
    list[4] = fifth;
    fifth.increaseCounter();

    std::cout << "Count of students: " << Student::getCounter() << std::endl;
    getStudent(second);

    second.setName("Petr");
    second.setAge(19);
    second.setWeight(100);
    second.setYearOfStudy(1);
    second.increaseYearOfStudy();

    getStudent(second);
    getStudent(third);

    std::cout << "Введите номер студента, которого вы хотите отобразить (всего студентов: " << Student::getCounter() << " )" << std::endl;
    int request;
    std::cin >> request;
    getStudent(list[request - 1]);
}

class Fruit{
protected:
    std::string m_color;
    std::string m_name;
public:
    Fruit(std::string color = "No color", std::string name = "Noname")
    : m_name(name), m_color(color){}

    std::string getName(){
        return m_name;
    }

    std::string getColor(){
        return m_color;
    }
};

class Apple : public Fruit{
public:
    Apple(std::string color = "green", std::string name = "apple")
    : Fruit(color, name){}
};

class Banana : public Fruit{
public:
    Banana(std::string color = "yellow", std::string name = "banana")
            : Fruit(color, name){}
};

class GrannySmith : public Apple{
public:
    GrannySmith(std::string color = "green", std::string name = "Granny Smith apple")
    : Apple(color, name){}
};

void TaskTwo(){
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

}

int main() {
    TaskOne();
    TaskTwo();

    return 0;
}
