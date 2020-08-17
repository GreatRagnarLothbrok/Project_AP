#ifndef PLANTS_CHERRYBOMB_H
#define PLANTS_CHERRYBOMB_H
#include"Plants.h"
#include"Controller.h"
class Plants_CherryBomb:public Plants
{
    Q_OBJECT
public:
    Plants_CherryBomb();
private:
    QTimer* bobmTimer;
    void customStop();
    void customStart();
private slots:
    void explosion();
    void checkColliding();
};

#endif // PLANTS_CHERRYBOMB_H
