#include "Plants_Sun.h"

Plants_Sun::Plants_Sun(Controller *controller):Animation()
{
    //set pic
    setPixmap(QPixmap(":/Plants/Plants/sun.png"));
    this->controller=controller;
}

void Plants_Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        controller->addSun();
        delete this;
        return;
    }
}

void Plants_Sun::move()
{

}
