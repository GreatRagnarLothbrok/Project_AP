#include "Plants.h"
#include"Zombi.h"
#include "Section.h"
#include <QDebug>
Plants::Plants(int price):Animation()
{
//set pic
this->price=price;
//Timer
    auto livingTimer=new QTimer;
    livingTimer->start(50);
    QObject::connect(livingTimer,SIGNAL(timeout()),this,SLOT(checkColliding()));
}

int Plants::getPrice()
{
    return price;
}

void Plants::checkColliding()
{
QList<QGraphicsItem*> listItems = collidingItems();
for( auto item:listItems){
if(dynamic_cast<Zombi*>(item)&&isPlaced)
{
    delete this;
    return;
}
}
}

void Plants::move()
{
//empty
}

void Plants::setPosition()
{
    QList<QGraphicsItem*> items = collidingItems();
    for (auto el : items) {
        if (typeid(*el) == typeid(Section)) {
            auto rect = dynamic_cast<Section*>(el);
            if (rect->isEmpty()) {
                qInfo() << "Placed" ;
                setPos(el->pos());
                rect->setPlant(this);
                return;
            }
        }
    }
    delete this;
}

void Plants::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setPosition();
}
