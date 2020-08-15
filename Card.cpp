#include "Card.h"
#include "Plants_Shooter.h"
#include "Plants_Sunflower.h"
#include "Plants_Wall.h"

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
    if (type == 0) {
        controller->takePlant(new Plants_Shooter(controller));
    }
    else if(type == 1) {
        controller->takePlant(new Plants_Sunflower(controller));
    }
    else if(type == 2) {
        controller->takePlant(new Plants_Wall);
    }
    else if(type == 3) {
        //controller->takePlant(new Plants_CherryBomb);
    }


}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    controller->addToField();
}



