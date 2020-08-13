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
    void addItem(QGraphicsItem *item);
private:
    QGraphicsScene * scene;
    QGraphicsRectItem * holder;
    QList<Movable*> movables;

};

#endif // CONTROLLER_H
