#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Movable.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QList>
#include"Show_Sun_Score.h"

class Controller
{
    friend class View;
public:
    Controller();
    ~Controller();
    void addItem(QGraphicsItem *item);
    void addSun();
private:
    QGraphicsScene * scene;
    QGraphicsRectItem * holder;
    QList<Movable*> movables;
Show_Sun_Score *score;
};

#endif // CONTROLLER_H
