#include "CloseButton.h"

CloseButton::CloseButton(View *view):QGraphicsPixmapItem()
{
//set image
    setPixmap(QPixmap(":/Background/BackGround/Close.png"));
    //set view
    this->view=view;
}

void CloseButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        view->close();
    }
}
