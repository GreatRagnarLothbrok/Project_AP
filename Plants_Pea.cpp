#include "Plants_Pea.h"
#include"Zombi.h"
Plants_Pea::Plants_Pea():Plants()
{
//set pic
    setPixmap(QPixmap(":/Plants/Plants/pea.png"));
}

void Plants_Pea::checkColliding()
{QList<QGraphicsItem*> listItems=collidingItems();
    for(const auto &item:listItems){
    if(typeid(dynamic_cast<Zombi*>(item))==typeid(Zombi*))
    {
        dynamic_cast<Zombi*>(item)->damage();
        delete this;
        return;
    }
    }

}

void Plants_Pea::move()
{
    setPos(x()+5,y());
}
