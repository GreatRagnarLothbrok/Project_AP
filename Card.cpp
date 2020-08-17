#include "Card.h"
#include "Plants_Shooter.h"
#include "Plants_Sunflower.h"
#include "Plants_Wall.h"
#include"Plants_CherryBomb.h"
Card::Card(Controller * controller, char type) : controller(controller), type(type)
{
    if (type == 0) {
        setPixmap(QPixmap(":/cards/Cards/PeashooterCard.png"));
    }
    else if(type == 1) {
        setPixmap(QPixmap(":/cards/Cards/SunflowerCard.png"));
    }
    else if(type == 2) {
        setPixmap(QPixmap(":/cards/Cards/WalnutCard.png"));
    }
    else if(type == 3) {
        setPixmap(QPixmap(":/cards/Cards/CherryBombCard.png"));
    }

}



void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!controller->checkIsStop()){
    if (type == 0) {
        if(controller->score->getPoint()>=100){
        controller->takePlant(new Plants_Shooter(controller));
        price=100;
        }
    }
    else if(type == 1) {
        if(controller->score->getPoint()>=50){
        controller->takePlant(new Plants_Sunflower(controller->score));
        price=50;
        }
    }
    else if(type == 2) {
        if(controller->score->getPoint()>=150){
        controller->takePlant(new Plants_Wall);
        price=150;
        }
    }
    else if(type == 3) {
        if(controller->score->getPoint()>=150){
        controller->takePlant(new Plants_CherryBomb());
        price=150;
        }
    }
}

}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(controller->chechPlants()){
    controller->addToField();
    controller->score->decrease(price);
    }
}



