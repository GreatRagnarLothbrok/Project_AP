#ifndef PLATNS_SUN_H
#define PLATNS_SUN_H
#include <Animation.h>
#include <QGraphicsSceneMouseEvent>
#include "Controller.h"
class Plants_Sun:public Animation
{
    Q_OBJECT
public:
    Plants_Sun(Controller *controller,bool check);
private:
    Controller *controller;
    bool checkMove;
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void move();
    void destroy();
};

#endif // PLATNS_SUN_H
