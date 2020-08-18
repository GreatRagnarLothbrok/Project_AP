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
#include<QMediaPlayer>
#include"cmath"
#include"Season.h"
Controller::Controller() : scene(new QGraphicsScene(0,0,1920,1080)),score(new Show_Sun_Score),isStop{false}
{
    //set scene pic
    setSceneController();
    //add card
    addCard();
    //random sun
    randomSun=new Plants_RandomSun(score,scene);
    Season* sea=new Season(this);
    sea->season1Start();
//set music
    QMediaPlayer *player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/music/backgeound.mp3"));
    player->play();
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

void Controller::addZombi(int row,bool zombi_type,int lifePoint)
{
    Zombi* zombi;
    if(zombi_type){
         zombi=new Zombi(lifePoint,row-1);
         zombi->setPos(scene->width(),150+row*100);
    }
    else{
         zombi=new Zombi_Master(lifePoint,row-1);
         zombi->setPos(scene->width(),110+row*100);
    }

    zombi->start();
    scene->addItem(zombi);
\
}




