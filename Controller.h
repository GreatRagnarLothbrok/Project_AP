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

class Controller
{
    friend class View;

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
    QList<Movable*> movables;
    QGraphicsScene * scene;
private:

    bool isStop;
    QGraphicsRectItem * holder;
    QGraphicsPixmapItem *stopPic;
    Field *field;
    Plants * selectedPlant = nullptr;
    bool shovelPicked = false;
    Plants_RandomSun*  randomSun;
};

#endif // CONTROLLER_H
