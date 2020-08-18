#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Movable.h"
#include "Field.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QList>
#include "Plants.h"
#include "Show_Sun_Score.h"
#include "Plants_RandomSun.h"
#include"Zombi.h"
#include"Zombi_Master.h"
class Controller:public QObject
{
    friend class View;
    friend class Season;
Q_OBJECT
public:
    Controller();
    ~Controller();
    void addItem(QGraphicsItem *item);
    void addSun();
    void takePlant(Plants * plant);
    Plants *getSelectedPlant();
    void addToField();
    void pickShovel();
    Show_Sun_Score *score;
    bool chechPlants();
    void stop();
    void start();
    bool checkIsStop();
    QGraphicsScene * scene;
private:
    QTimer *secTimer;
    int sec;
    void addCard();
    void setSceneController();
    bool isStop;
    QGraphicsRectItem * holder;
    QGraphicsPixmapItem *stopPic;
    Field *field;
    Plants * selectedPlant = nullptr;
    bool shovelPicked = false;
    Plants_RandomSun*  randomSun;
    void addZombi(int height,bool zombi_type,int lifePoint);
    void secIncrease(){sec++;}

};

#endif // CONTROLLER_H
