#ifndef _BAR_H_
#define _BAR_H_

class Bar{
public:
    Bar(double y = 0.0);

    void set(double a);

    double GetY() const;

private:
    double m_y;
};

#endif //_BAR_H_
