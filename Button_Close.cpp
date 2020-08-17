#include "Button_Close.h"

Button_Close::Button_Close(View *view):QGraphicsPixmapItem()
{
//set image
    setPixmap(QPixmap(":/Background/BackGround/Close.png"));
    //set view
    this->view=view;
}

void Button_Close::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        view->close();
    }
}
