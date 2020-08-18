#ifndef ZOMBI_H
#define ZOMBI_H
#include "Animation.h"
class Zombi:public Animation
{
    Q_OBJECT
public:
    Zombi();
    void damage();
private:
    int lifePoint;
private slots:
    void move();
    void checkLiving();
};

#endif // ZOMBI_H
