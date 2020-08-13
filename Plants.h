#ifndef PLANTS_H
#define PLANTS_H
#include"Animation.h"

class Plants:public Animation
{
public:
    Plants();
private slots:
    virtual void checkLiving();
};

#endif // PLANTS_H
