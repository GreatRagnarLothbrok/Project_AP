#include "Plants_RandomSun.h"
#include<QTimer>
#include<QGraphicsScene>
#include <exception>
#include<QDebug>
#include"Movable.h"
Plants_RandomSun::Plants_RandomSun(Show_Sun_Score *score,QGraphicsScene *scene):QObject(),score{score},scene{scene}
{
    timerSun=new QTimer;
    timerSun->start(10000);
    QObject::connect(timerSun,SIGNAL(timeout()),this,SLOT(buildSun()));

}

Plants_RandomSun::~Plants_RandomSun()
{
 delete timerSun;
}

void Plants_RandomSun::customStop()
{
    QObject::disconnect(timerSun,SIGNAL(timeout()),this,SLOT(buildSun()));

}

void Plants_RandomSun::customStart()
{
    QObject::connect(timerSun,SIGNAL(timeout()),this,SLOT(buildSun()));

}

void Plants_RandomSun::buildSun()
{
    int xP=800+rand()%800;
    auto sun=new Plants_Sun(score,true);
    sun->setPos(xP,0);
    sun->start();
    scene->addItem(sun);
    sunList.append(sun);
}
