#include "Controller.h"
#include"Zombi.h"
#include"Plants.h"
#include"Plants_Pea.h"
#include"Plants_Shooter.h"
#include"Plants_Sun.h"
#include"Plants_Sunflower.h"
#include"Plants_Wall.h"
#include "Shovel.h"
#include "Card.h"
#include <QCursor>
#include "Plants_RandomSun.h"

Controller::Controller() : scene(new QGraphicsScene(0,0,1920,1080)),score(new Show_Sun_Score)
{
    auto bar = new QGraphicsPixmapItem(QPixmap(":/Background/BackGround/barezombie.png"));
    addItem(bar);
    score->setPos(0,100);
    scene->addItem(score);
    holder = new QGraphicsRectItem(0,0,scene->width(),scene->height());
    field = new Field(700,300,5,8,holder);
    //add zombi
    for(int i=0;i<10;i++){
    auto zombi1=new Zombi;
    zombi1->setPos(1500,i*100);
    scene->addItem(zombi1);
    zombi1->start();
    }
    field->addToScene(scene);
    //add card
    auto shooterCard = new Card(this);
    auto sunflowerCard = new Card(this,1);
    auto walnutCard = new Card(this,2);
    auto cherryCard = new Card(this,3);
    shooterCard->setPos(150,0);
    sunflowerCard->setPos(300,0);
    walnutCard->setPos(450,0);
    cherryCard->setPos(600,0);
    addItem(shooterCard);
    addItem(sunflowerCard);
    addItem(walnutCard);
    addItem(cherryCard);
    //add shovel
    auto shovel = new Shovel(this,holder);
    shovel->setPos(900,0);
    addItem(shovel);
//random sun
  Plants_RandomSun*  randomSun=new Plants_RandomSun(this);

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

    plant->setPos(QCursor::pos().x() - (plant->boundingRect().width()/2),QCursor::pos().y() - (plant->boundingRect().height()/2) );
    plant->start();
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

void Controller::pickShovel()
{
    shovelPicked = true;
}

