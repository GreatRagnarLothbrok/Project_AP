#include "Plants_Shooter.h"
#include"Plants_Pea.h"
Plants_Shooter::Plants_Shooter(Controller *controller):Plants(100), controller(controller)
{
//set pic
    setPixmap(QPixmap(":/Plants/Plants/shooter.png"));
    //set timer
    auto shooter_Timer=new QTimer;
    shooter_Timer->start(1000);
    QObject::connect(shooter_Timer,SIGNAL(timeout()),this,SLOT(shot()));
    this->controller=controller;
}

void Plants_Shooter::shot()
{
    auto pea=new Plants_Pea;
    pea->setPos(x()+60,y()+40);
pea->start();
controller->addItem(pea);
}
