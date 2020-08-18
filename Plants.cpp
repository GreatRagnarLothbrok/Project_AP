#include "Plants.h"
#include"Zombi.h"
#include "Section.h"
#include <QDebug>
Plants::Plants(int price):Animation(),price{price}
{
//Timer
    livingTimer=new QTimer;
    livingTimer->start(50);
    QObject::connect(livingTimer,SIGNAL(timeout()),this,SLOT(checkColliding()));
}

Plants::~Plants()
{
    delete livingTimer;
}

int Plants::getPrice()
{
    return price;
}

void Plants::checkColliding()
{
    QList<QGraphicsItem*> listItems = collidingItems();
    for( auto item:listItems){
        auto zombi=dynamic_cast<Zombi*>(item);
        if(zombi&&isPlaced&&row==zombi->getRow())
            {
                emit plantRemoved();
                delete this;
                return;
        }
    }
}

void Plants::move()
{
//empty
}

void Plants::setPosition(Show_Sun_Score *score)
{
    this->score=score;
    QList<QGraphicsItem*> items = collidingItems();
    for (auto el : items) {
        if (typeid(*el) == typeid(Section)) {
            auto rect = dynamic_cast<Section*>(el);
            if (rect->isEmpty()) {
                setPos(el->pos());
                rect->setPlant(this);
                column=rect->getColumn();
                row=rect->getRow();
                customFunctionality();
                score->decrease(getPrice());
                QMediaPlayer *player=new QMediaPlayer;
                player->setMedia(QUrl("qrc:/music/music/take_Plant.mp3"));
                player->play();
                return;
            }
        }
    }
    delete this;
}

int Plants::getRow() const
{
    return row;
}

void Plants::setRow(int value)
{
    row = value;
}

int Plants::getColumn() const
{
    return column;
}

void Plants::setColumn(int value)
{
    column = value;
}

void Plants::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setPosition(score);
}
