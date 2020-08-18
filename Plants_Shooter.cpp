#include "Plants_Shooter.h"
#include"Plants_Pea.h"
#include"Zombi.h"
Plants_Shooter::Plants_Shooter():Plants(100)
{
    this->controller=controller;
    //set pic
    setPixmap(QPixmap(":/Plants/Plants/shooter.png"));
    //set timer
     shooter_Timer=new QTimer;
    shooter_Timer->start(1000);

}

void Plants_Shooter::customFunctionality()
{
    QObject::connect(shooter_Timer,SIGNAL(timeout()),this,SLOT(shot()));

}

void Plants_Shooter::customStop()
{
    QObject::disconnect(shooter_Timer,SIGNAL(timeout()),this,SLOT(shot()));
}

void Plants_Shooter::customStart()
{
    QObject::connect(shooter_Timer,SIGNAL(timeout()),this,SLOT(shot()));

}

void Plants_Shooter::shot()
{
    //check zombi
    QList<QGraphicsItem*> listItems = scene()->items(x(),y() ,scene()->width(), y() + 100,Qt::IntersectsItemShape,Qt::DescendingOrder);
    for( auto item:listItems){
    if(dynamic_cast<Zombi*>(item))
      {
    auto pea=new Plants_Pea();
    pea->setPos(x()+60,y()+40);
    pea->start();
    scene()->addItem(pea);
    break;
    }
    }
}
