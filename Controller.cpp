#include "Controller.h"
#include"Plants.h"
#include"Plants_Pea.h"
#include"Plants_Shooter.h"
#include"Plants_Sun.h"
#include"Plants_Sunflower.h"
#include"Plants_Wall.h"
#include "Shovel.h"
#include "Card.h"
#include <QCursor>
#include<QDebug>
#include"cmath"
Controller::Controller() : scene(new QGraphicsScene(0,0,1920,1080)),score(new Show_Sun_Score),isStop{false}
{
    //set scene pic
    setSceneController();
    //field
   // field->addToScene(scene);
    //add card
    addCard();
    //random sun
    randomSun=new Plants_RandomSun(score,scene);
//    auto zombi=new Zombi;
//    zombi->setPos(1500,250);
//    zombi->start();
//    scene->addItem(zombi);
    sec=45;
    season1Start();
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
    score->increase();
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

    selectedPlant->setPosition(score);
    selectedPlant->setPlaced();
    selectedPlant = nullptr;
}

void Controller::pickShovel()
{
    shovelPicked = true;
}

bool Controller::chechPlants()
{
    return selectedPlant!=nullptr;
}

void Controller::stop()
{
    QList<QGraphicsItem*> items = scene->items();
    for (auto & el : items) {
        auto item = dynamic_cast<Movable*>(el);
        if (item){
            item->stop();
            item->customStop();
        }
    }
    randomSun->customStop();
    isStop = true;

}

void Controller::start()
{
    QList<QGraphicsItem*> items = scene->items();
    for (auto & el : items) {
        auto item = dynamic_cast<Movable*>(el);
        if (item){
            item->start();
            item->customStart();
        }
    }
    randomSun->customStart();
    isStop = false;
}

bool Controller::checkIsStop()
{
    return isStop;
}

void Controller::addCard()
{
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
}

void Controller::setSceneController()
{
    //set scene pic
    auto bar = new QGraphicsPixmapItem(QPixmap(":/Background/BackGround/barezombie.png"));
    addItem(bar);
    score->setPos(0,100);
    scene->addItem(score);
    holder = new QGraphicsRectItem(0,0,scene->width(),scene->height());
  //  field = new Field(700,300,5,8,holder);
    //set picStop
    stopPic=new QGraphicsPixmapItem;
    stopPic->setPixmap(QPixmap(":/Background/BackGround/stop.png"));
    stopPic->setPos(0,0);
}

void Controller::addZombi(int height,bool zombi_type)
{
    Zombi* zombi;
    if(zombi_type)
         zombi=new Zombi;
    else
         zombi=new Zombi_Master;

    zombi->setPos(scene->width(),height);
    zombi->start();
    scene->addItem(zombi);
\
}

void Controller::season1Start()
{
    field = new Field(700,300,1,9,holder);
    field->addToScene(scene);
    secTimer=new QTimer;
    secTimer->start(1000);
    QObject::connect(secTimer,SIGNAL(timeout()),this,SLOT(season1Function()));

}

void Controller::season1Function()
{
    secIncrease();
    if(sec>=50&&sec<=60){
        if(sec==50)
            addZombi(250,false);
        else if(sec==54)
            addZombi(250,false);
        else if(sec==57)
            addZombi(250,false);
        else if(sec==59)
            addZombi(250,false);
        else if(sec==60)
            addZombi(250,false);

    }
    else if(sec>60){
        int num=0;
        QList<QGraphicsItem*> items = scene->items();
        for(auto &item:items){
            auto zombi=dynamic_cast<Zombi*>(item);
            if(zombi){
                if(zombi->x()<=0){
                    //lose empty
                  break;
                }
                num++;

            }

        }
        if(num==0)
        {
            // win empty

        }

    }
}

