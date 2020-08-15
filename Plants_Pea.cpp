#include "Plants_Pea.h"
#include"Zombi.h"
Plants_Pea::Plants_Pea():Plants(0)
{
//set pic
    setPixmap(QPixmap(":/Plants/Plants/pea.png"));
}

void Plants_Pea::checkColliding()
{
    QList<QGraphicsItem*> listItems=collidingItems();
    for(const auto &item:listItems){
    if(dynamic_cast<Zombi*>(item))
    {
        dynamic_cast<Zombi*>(item)->damage();
        delete this;
        return;
    }
    }

}

void Plants_Pea::move()
{
    if (x() >= scene()->width()) {
        delete this;
        return;
    }
    setPos(x()+6,y());
}
