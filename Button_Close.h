#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H
#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>
#include"View.h"
class Button_Close:public QGraphicsPixmapItem
{
public:
    Button_Close( View *view);
private:
    View *view;
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CLOSEBUTTON_H
