#include <iostream>
#include <memory>
#include "Date.h"
#include "TaskTwo.h"
#include "Funcs.h"

void TaskTwo() {
    auto date1 = std::make_shared<Date>();
    auto date2 = std::make_shared<Date>();

    date1->SetDayMonthYear(11, 7, 2021);
    date2->SetDayMonthYear(23, 6, 2021);

    std::cout << "Greater date is: " << *GreaterDateFirst(date1, date2) << std::endl;
    swapPtr(date1, date2);

    std::cout << "Greater date is: " << *GreaterDateSecond(date1, date2) << std::endl;
    swapPtr(date1, date2);

    std::cout << "Greater date is: " << *GreaterDateThird(date1, date2) << std::endl;
}