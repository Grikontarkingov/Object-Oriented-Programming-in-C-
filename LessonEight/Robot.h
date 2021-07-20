#ifndef _ROBOT_H_
#define _ROBOT_H_

class Robot{
public:
    Robot();

    void right(Field& field);
    void left(Field& field);
    void up(Field& field);
    void down(Field& field);

    void movement(const std::string& command, Field& field);

    int getX() const;
    int getY() const;

private:
    typedef struct pos{
        int x;
        int y;
    }Pos;

    Pos m_pos{};
};

#endif //_ROBOT_H_
