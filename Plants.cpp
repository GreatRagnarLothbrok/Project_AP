#include "Plants.h"
#include"Zombi.h"
Plants::Plants(int price):Animation()
{
//set pic
this->price=price;
//Timer
    auto livingTimer=new QTimer;
    livingTimer->start(50);
    QObject::connect(livingTimer,SIGNAL(timeout()),this,SLOT(checkColliding()));
}

int Plants::getPrice()
{
    return price;
}

void Plants::checkColliding()
{
QList<QGraphicsItem*> listItems=collidingItems();
for( auto item:listItems){
if(dynamic_cast<Zombi*>(item))
{
    delete this;
    return;
}
}
}

void Plants::move()
{
//empty
}
