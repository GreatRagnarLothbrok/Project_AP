#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Movable.h"
#include "Field.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QList>
#include "Plants.h"

#include"Show_Sun_Score.h"

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
private:
    QGraphicsScene * scene;
    QGraphicsRectItem * holder;
    QList<Movable*> movables;
    Show_Sun_Score *score;
    Field *field;
    Plants * selectedPlant = nullptr;
    bool shovelPicked = false;
};

#endif // CONTROLLER_H
