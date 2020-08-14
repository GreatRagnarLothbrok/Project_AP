#include "Controller.h"
#include"Zombi.h"
#include"Plants.h"
#include"Plants_Pea.h"
#include"Plants_Shooter.h"
#include"Plants_Sun.h"
#include"Plants_Sunflower.h"
Controller::Controller() : scene(new QGraphicsScene(0,0,1920,1080)),score(new Show_Sun_Score)
{
score->setPos(200,60);
scene->addItem(score);
    holder = new QGraphicsRectItem(0,0,scene->width(),scene->height());
auto zombi1=new Zombi;
zombi1->setPos(1500,600);
scene->addItem(zombi1);
zombi1->start();
//auto sunFlower=new Plants_Sunflower(this);
//sunFlower->setPos(700,300);
//sunFlower->start();
//scene->addItem(sunFlower);
}

Controller::~Controller()
{
    delete scene;
    delete holder;
}

void Controller::addItem(QGraphicsItem *item)
{
    scene->addItem(item);
}

void Controller::addSun()
{
    score->getSun();
}

