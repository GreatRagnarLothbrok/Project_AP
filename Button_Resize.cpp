#include "Button_Resize.h"

Button_Resize::Button_Resize(View *view):QGraphicsPixmapItem()
{
//set pic
    setPixmap(QPixmap(":/Background/BackGround/resize.png"));
    this->view=view;
}

void Button_Resize::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(view->isFullScreen())
            view->showNormal();
        else
            view->showFullScreen();
    }
}
