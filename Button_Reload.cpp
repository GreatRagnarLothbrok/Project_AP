#include "Button_Reload.h"
#include"Season.h"
Button_Reload::Button_Reload(Controller *controller):QGraphicsPixmapItem(),controller{controller}
{
//set pic
    setPixmap(QPixmap(":/Background/BackGround/reload.png"));
}

void Button_Reload::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button()==Qt::LeftButton){
        controller->sea->start();
    }
}
