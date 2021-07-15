#include <iostream>
#include "Date.h"

Date::Date() {}

int Date::GetDay() const { return m_day; }
int Date::GetMonth() const { return m_month; }
int Date::GetYear() const { return m_year; }

void Date::SetDay(int day) { m_day = day; }
void Date::SetMonth(int month) { m_month = month; }
void Date::SetYear(int year) { m_year = year; }
void Date::SetDayMonthYear(int day, int month, int year) {
    m_day = day;
    m_month = month;
    m_year = year;
}

std::ostream& operator<< (std::ostream& out, const Date& date){
    out << date.m_day << "." << date.m_month << "." << date.m_year;

    return out;
}