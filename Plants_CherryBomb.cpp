#include "Plants_CherryBomb.h"
#include"Zombi.h"
#include<QDebug>
Plants_CherryBomb::Plants_CherryBomb():Plants(150)
{
//set pixmap
    setPixmap(QPixmap(":/Plants/Plants/Cherry_Bomb.png"));
    //set timer
        auto bobmTimer=new QTimer;
        bobmTimer->start(2000);
    //connect
    QObject::connect(bobmTimer,SIGNAL(timeout()),this,SLOT(explosion()));

}

void Plants_CherryBomb::explosion()
{
    QList<QGraphicsItem*> listItems=collidingItems();
    for( auto item:listItems){
    if(dynamic_cast<Zombi*>(item))
      {
        delete item;
       }
    }
    delete this;
    return;
}

void Plants_CherryBomb::checkColliding()
{

}
