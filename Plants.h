#ifndef PLANTS_H
#define PLANTS_H
#include"Animation.h"

class Plants:public Animation
{
    Q_OBJECT
public:
    Plants();
protected slots:
    virtual void checkColliding();
private slots:
    void move();
};

#endif // PLANTS_H
