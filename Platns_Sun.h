#ifndef PLATNS_SUN_H
#define PLATNS_SUN_H
#include <Animation.h>
#include <QGraphicsSceneMouseEvent>

class Platns_Sun:public Animation
{
public:
    Platns_Sun(Controller *controller);
private:
    Controller *controller;
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void move();
};

#endif // PLATNS_SUN_H
