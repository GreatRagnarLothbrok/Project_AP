#ifndef PLANTS_SUNFLOWER_H
#define PLANTS_SUNFLOWER_H
#include "Plants.h"
#include"Plants_Sun.h"
class Plants_Sunflower:public Plants
{
    Q_OBJECT
public:
    Plants_Sunflower(Controller *controller);
private:
    Controller *controller;
private slots:
    void buildSun();
};

#endif // PLANTS_SUNFLOWER_H
