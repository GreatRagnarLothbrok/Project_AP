#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H
#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>
#include"View.h"
class CloseButton:public QGraphicsPixmapItem
{
public:
    CloseButton(View *view);
private:
    View *view;
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CLOSEBUTTON_H
