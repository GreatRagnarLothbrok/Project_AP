#include "Platns_Sun.h"

Platns_Sun::Platns_Sun(Controller *controller):Animation()
{
    //set pic
    setPixmap(QPixmap(":/Plants/Plants/sun.png"));
    this->controller=controller;
}

void Platns_Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        controller->addSun();
        delete this;
        return;
    }
}

void Platns_Sun::move()
{

}
