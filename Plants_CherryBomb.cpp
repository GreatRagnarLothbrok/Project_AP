#include "Plants_CherryBomb.h"
#include"Zombi.h"
#include<QDebug>
Plants_CherryBomb::Plants_CherryBomb():Plants(150)
{
//set pixmap
    setPixmap(QPixmap(":/Plants/Plants/Cherry_Bomb.png"));
    //set timer
        bobmTimer=new QTimer;
        bobmTimer->start(2000);
    //connect


}

void Plants_CherryBomb::customFunctionality()
{
    QObject::connect(bobmTimer,SIGNAL(timeout()),this,SLOT(explosion()));
}



void Plants_CherryBomb::customStop()
{
    QObject::disconnect(bobmTimer,SIGNAL(timeout()),this,SLOT(explosion()));
}

void Plants_CherryBomb::customStart()
{
    if(isStop)
    QObject::connect(bobmTimer,SIGNAL(timeout()),this,SLOT(explosion()));
}

void Plants_CherryBomb::explosion()
{
    QList<QGraphicsItem*> listItems = scene()->items(x() - 90,y() -120,x() + 100, y() + 140,Qt::IntersectsItemShape,Qt::DescendingOrder);
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
