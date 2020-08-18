#ifndef ZOMBI_H
#define ZOMBI_H
#include "Animation.h"
class Zombi:public Animation
{
    Q_OBJECT
public:
    Zombi(int lifPoint,int row);
    void damage();
    int getRow() const;
    void setRow(int value);

private:
    int lifePoint;
    int row;
private slots:
    void move();
    void checkLiving();
};

#endif // ZOMBI_H
