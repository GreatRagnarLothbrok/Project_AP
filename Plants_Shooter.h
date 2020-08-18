#ifndef PLANTS_SHOOTER_H
#define PLANTS_SHOOTER_H
#include"Plants.h"
#include "Controller.h"
class Plants_Shooter:public Plants
{
    Q_OBJECT
public:
    Plants_Shooter();
    void customFunctionality();
private:
    void customStop();
    void customStart();
    Controller *controller;
    QTimer* shooter_Timer;
private slots:
    void shot();
};

#endif // PLANTS_SHOOTER_H
