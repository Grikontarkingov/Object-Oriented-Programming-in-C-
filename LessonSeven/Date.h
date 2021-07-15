#ifndef _DATE_H_
#define _DATE_H_

class Date{
public:
    Date();
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    void SetDay(int day);
    void SetMonth(int month);
    void SetYear(int year);
    void SetDayMonthYear(int day, int month, int year);

    friend std::ostream& operator<< (std::ostream& out, const Date& date);

private:
    int m_day{};
    int m_month{};
    int m_year{};
};

#endif //_DATE_H_
