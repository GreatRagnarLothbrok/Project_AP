#include "Plants_Sun.h"

Plants_Sun::Plants_Sun(Controller *controller,bool check):Animation(),checkMove{check}
{
    //set pic
    setPixmap(QPixmap(":/Plants/Plants/sun.png"));
    this->controller=controller;
    auto destroyTimer=new QTimer;
    destroyTimer->start(2000);
    QObject::connect(destroyTimer,SIGNAL(timeout()),this,SLOT(destroy()));
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
if(checkMove)
{
    setPos(x(),y()+2);
}
}

void Plants_Sun::destroy()
{
    delete this;
}
