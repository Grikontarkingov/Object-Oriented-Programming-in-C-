#include <memory>
#include "Date.h"
#include "Funcs.h"

void swapPtr(std::shared_ptr<Date>& a, std::shared_ptr<Date>& b) {
    auto temp = std::shared_ptr<Date> ();
    temp = a;
    a = b;
    b = temp;
}

std::shared_ptr<Date>& GreaterDateFirst(std::shared_ptr<Date>& a, std::shared_ptr<Date>& b){
    if(a->GetYear() == b->GetYear()){
        if(a->GetMonth() == b->GetMonth()){
            return (a->GetDay() > b->GetDay()) ? a : b; // если будут равны вывести b;
        }
        else{
            return (a->GetMonth() > b->GetMonth()) ? a : b;
        }
    }
    else{
        return (a->GetYear() > b->GetYear()) ? a : b;
    }
}

std::shared_ptr<Date>& GreaterDateSecond(std::shared_ptr<Date>& a, std::shared_ptr<Date>& b){
    int first = a->GetDay() + a->GetMonth()*31 + a->GetYear()*365;
    int second = b->GetDay() + b->GetMonth()*31 + b->GetYear()*365;
    return (first > second) ? a : b; //если равны, вывести b;
}

std::shared_ptr<Date>& GreaterDateThird(std::shared_ptr<Date>& a, std::shared_ptr<Date>& b){
    int first = a->GetYear()*10000 + a->GetMonth()*100 + a->GetDay();
    int second = b->GetYear()*10000 + b->GetMonth()*100 + b->GetDay();

    return (first > second) ? a : b; //если равно, вернуть b;
}