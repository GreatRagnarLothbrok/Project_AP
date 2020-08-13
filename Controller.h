#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Movable.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QList>


class Controller
{
    friend class View;
public:
    Controller();
    ~Controller();
private:
    QGraphicsScene * scene;
    QGraphicsRectItem * container;
    QList<Movable*> movables;

};

#endif // CONTROLLER_H
