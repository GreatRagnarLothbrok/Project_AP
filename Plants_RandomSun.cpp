#include "Plants_RandomSun.h"
#include"Plants_Sun.h"
#include<QTimer>
Plants_RandomSun::Plants_RandomSun(Controller *controller):QObject()
{
    this->controller=controller;

    auto timerSun=new QTimer;
    timerSun->start(10000);
    connect(timerSun,SIGNAL(timeout()),this,SLOT(buildSun()));

}

void Plants_RandomSun::buildSun()
{
int xP=800+rand()%800;
auto sun=new Plants_Sun(controller,true);
sun->setPos(xP,0);
sun->start();
controller->addItem(sun);
}
