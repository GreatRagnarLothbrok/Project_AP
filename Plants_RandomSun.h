#ifndef PLANTS_RANDOMSUN_H
#define PLANTS_RANDOMSUN_H
#include"Controller.h"
class Plants_RandomSun:public QObject
{
Q_OBJECT
public:
    Plants_RandomSun(Controller *controller);
private:
    Controller *controller;
private slots:
    void buildSun();
};

#endif // PLANTS_RANDOMSUN_H
