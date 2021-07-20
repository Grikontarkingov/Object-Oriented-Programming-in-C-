#ifndef _FIELD_H_
#define _FIELD_H_

class Field{
public:
    Field(int y, int x);

    ~Field();

    void printField() const;

    int getYofField() const;
    int getXofField() const;

    void swap(int curPosX, int curPosY, int nextPosX, int nextPosY);

private:
    int m_y;
    int m_x{};
    int** m_field{};

    void createField();

    void setField();
};

#endif //_FIELD_H_
