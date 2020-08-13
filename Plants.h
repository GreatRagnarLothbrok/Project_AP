#ifndef PLANTS_H
#define PLANTS_H
#include"Animation.h"

class Plants:public Animation
{
    Q_OBJECT
public:
    Plants();
private slots:
    virtual void checkLiving();
    void move();
};

#endif // PLANTS_H
