#ifndef PLANTS_PEA_H
#define PLANTS_PEA_H
#include"Plants.h"
#include "Controller.h"
class Plants_Pea:public Plants
{
public:
    Plants_Pea();
    ~Plants_Pea();

protected slots:
    void checkColliding();
    void move();
};

#endif // PLANTS_PEA_H
