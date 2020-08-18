#ifndef BUTTON_RELOAD_H
#define BUTTON_RELOAD_H

#include<QGraphicsPixmapItem>
#include"Controller.h"
#include<QGraphicsSceneMouseEvent>
class Button_Reload:public QGraphicsPixmapItem
{
public:
    Button_Reload(Controller *controller);
private:
    Controller *controller;
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUTTON_RELOAD_H
