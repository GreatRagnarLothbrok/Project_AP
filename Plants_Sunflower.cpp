#include "Plants_Sunflower.h"

Plants_Sunflower::Plants_Sunflower(Controller *controller):Plants(50)
{
    this->controller=controller;
//set pic
    setPixmap(QPixmap(":/Plants/Plants/Sunflower.png"));
    //set timer
    QTimer *addSunTimer=new QTimer;
    addSunTimer->start(1000);

QObject::connect(addSunTimer,SIGNAL(timeout()),this,SLOT(buildSun()));
}

void Plants_Sunflower::buildSun()
{
    auto sun=new Plants_Sun(controller);
    sun->setPos(x(),y());

    controller->addItem(sun);
}
