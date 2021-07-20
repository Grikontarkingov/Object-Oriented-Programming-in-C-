#ifndef _ILLEGALCOMMAND_H_
#define _ILLEGALCOMMAND_H_

class IllegalCommand{
public:
    IllegalCommand();

    std::string getError() const;

private:
    std::string m_error;
};

#endif //_ILLEGALCOMMAND_H_
