#ifndef PLANTS_WALL_H
#define PLANTS_WALL_H
#include"Plants.h"

class Plants_Wall:public Plants
{
public:
    Plants_Wall();
private slots:
    void checkColliding();
    void move();
};

#endif // PLANTS_WALL_H
