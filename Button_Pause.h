#ifndef BUTTON_PAUSE_H
#define BUTTON_PAUSE_H
#include<QGraphicsPixmapItem>
#include"View.h"
class Button_Pause:public QGraphicsPixmapItem
{
public:
    Button_Pause(View *view);
private:
    View *view;
    QGraphicsScene *scenePause;
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUTTON_PAUSE_H
