#ifndef _OFFTHEFIELD_H_
#define _OFFTHEFIELD_H_

class OffTheField{
public:
    OffTheField();

    std::string getError() const;

private:
    std::string m_error;
};

#endif //_OFFTHEFIELD_H_
