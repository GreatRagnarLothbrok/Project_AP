#include "ResizeButton.h"

ResizeButton::ResizeButton(View *view):QGraphicsPixmapItem()
{
//set pic
    setPixmap(QPixmap(":/Background/BackGround/resize.png"));
    this->view=view;
}

void ResizeButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(view->isFullScreen())
            view->showNormal();
        else
            view->showFullScreen();
    }
}
