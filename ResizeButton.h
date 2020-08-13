#ifndef RESIZEBUTTON_H
#define RESIZEBUTTON_H
#include<QGraphicsPixmapItem>
#include"View.h"
#include<QGraphicsSceneMouseEvent>
class ResizeButton:public QGraphicsPixmapItem
{
public:
    ResizeButton(View *view);
private:
    View *view;
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // RESIZEBUTTON_H
