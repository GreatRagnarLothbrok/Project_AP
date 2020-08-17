#ifndef RESIZEBUTTON_H
#define RESIZEBUTTON_H
#include<QGraphicsPixmapItem>
#include"View.h"
#include<QGraphicsSceneMouseEvent>
class Button_Resize:public QGraphicsPixmapItem
{
public:
    Button_Resize(View *view);
private:
    View *view;
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // RESIZEBUTTON_H
