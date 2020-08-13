#ifndef PLANTS_SHOOTER_H
#define PLANTS_SHOOTER_H
#include"Plants.h"
class Plants_Shooter:public Plants
{
    Q_OBJECT
public:
    Plants_Shooter(Controller *controller);
private:
    Controller *controller;
private slots:
    void shot();
};

#endif // PLANTS_SHOOTER_H
