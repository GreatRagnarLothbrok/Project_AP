#include "Controller.h"
#include"Zombi.h"
#include"Plants.h"
#include"Plants_Pea.h"
#include"Plants_Shooter.h"
#include"Plants_Sun.h"
#include"Plants_Sunflower.h"
#include"Plants_Wall.h"

Controller::Controller() : scene(new QGraphicsScene(0,0,1920,1080)),score(new Show_Sun_Score)
{
    score->setPos(200,60);
    scene->addItem(score);
    holder = new QGraphicsRectItem(0,0,scene->width(),scene->height());
    field = new Field(700,300,5,8,holder);
    auto zombi1=new Zombi;
    zombi1->setPos(1500,600);
    scene->addItem(zombi1);
    zombi1->start();
    field->addToScene(scene);
//auto sunFlower=new Plants_Wall();
//sunFlower->setPos(200,600);
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

void Controller::takePlant(Plants *plant)
{
    scene->addItem(plant);
    selectedPlant = plant;
}

Plants *Controller::getSelectedPlant()
{
    return selectedPlant;
}

void Controller::addToField()
{
    selectedPlant->setPosition();
    selectedPlant->setPlaced();
    selectedPlant = nullptr;
}

