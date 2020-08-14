#include "Plants_Wall.h"
#include"Zombi.h"
Plants_Wall::Plants_Wall():Plants(150)
{
//set piclist
    QList<QPixmap> qlist;
    for(int i=0;i<29;i++){
        qlist.append(QPixmap(":/Plants/Plants/Wall/wall"+QString::number(i)+".png"));
    }
    //setPicsList(qlist);
    setPixmap(QPixmap(":/Plants/Plants/Wall/wall0.png"));
}

void Plants_Wall::checkColliding()
{
    QList<QGraphicsItem*> listItems=collidingItems();
        for(const auto &item:listItems){
        if(dynamic_cast<Zombi*>(item))
           delete dynamic_cast<Zombi*>(item);
        }
}

void Plants_Wall::move()
{
    setPos(x()+5,y());
}
