#include <iostream>
#include <memory>
#include "TaskOne.h"
#include "Date.h"
#include "Funcs.h"

void TaskOne(){
    auto date = std::shared_ptr<Date>();
    auto today = std::make_shared<Date>();
    today->SetDayMonthYear(10, 7, 2021);
    std::cout << "Day: " << today->GetDay() << " Month: " << today->GetMonth() << " Year: " << today->GetYear() << std::endl;
    std::cout << *today << std::endl;
    swapPtr(today, date);
    std::cout << *date << std::endl;

    if(today){
        std::cout << "today_ptr is not NULL" << std::endl;
    }
    else{
        std::cout << "today_ptr is NULL" << std::endl;
    }

    if(date){
        std::cout << "date_ptr is not NULL" << std::endl;
    }
    else{
        std::cout << "date_ptr is NULL" << std::endl;
    }
}