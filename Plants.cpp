#include "Plants.h"
#include"Zombi.h"
Plants::Plants():Animation()
{
//set pic

//Timer
    auto livingTimer=new QTimer;
    livingTimer->start(50);
    QObject::connect(livingTimer,SIGNAL(timeout()),this,SLOT(checkColliding()));
}

void Plants::checkColliding()
{
QList<QGraphicsItem*> listItems=collidingItems();
for(const auto &item:listItems){
if(typeid(dynamic_cast<Zombi*>(item))==typeid(Zombi*))
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
