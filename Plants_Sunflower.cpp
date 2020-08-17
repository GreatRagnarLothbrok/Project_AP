#include "Plants_Sunflower.h"

Plants_Sunflower::Plants_Sunflower(Show_Sun_Score *score):Plants(50)
{
    this->score=score;
//set pic
    setPixmap(QPixmap(":/Plants/Plants/Sunflower.png"));
    //set timer
    addSunTimer=new QTimer;
    addSunTimer->start(15000);

    QObject::connect(addSunTimer,SIGNAL(timeout()),this,SLOT(buildSun()));

}

void Plants_Sunflower::customStart()
{
    if(isStop)
    QObject::connect(addSunTimer,SIGNAL(timeout()),this,SLOT(buildSun()));

}

void Plants_Sunflower::customStop()
{
    QObject::disconnect(addSunTimer,SIGNAL(timeout()),this,SLOT(buildSun()));

}

void Plants_Sunflower::buildSun()
{
    auto sun=new Plants_Sun(score,false);
    sun->setPos(x(),y());
    scene()->addItem(sun);

}
