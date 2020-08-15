#include "Shovel.h"
#include <QCursor>
#include "Section.h"
Shovel::Shovel(Controller * controller, QGraphicsRectItem * parent) : QGraphicsPixmapItem(parent), controller(controller)
{
    setPixmap(QPixmap(":/Background/BackGround/Shovel.png"));
    timer = new QTimer;
}

Shovel::~Shovel()
{
    delete timer;
}

void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem*> collidings = collidingItems();
    for ( auto & el : collidings) {
        if(typeid(*el) == typeid(Section)){
           auto rect = dynamic_cast<Section*>(el);
           if(!rect->isEmpty()) {
               rect->destroy();
               return;
           }
        }
    }
}

void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

void Shovel::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(picked) {
        picked = false;
        setPos(defaultPoint);
        timer->stop();
        QObject::disconnect(timer,SIGNAL(timeout()),this,SLOT(setPosition()));
    }
    else {
        picked = true;
        defaultPoint = pos();
        timer->start(16);
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setPosition()));
    }
}

void Shovel::setPosition()
{
    if(picked) {
        setPos(QCursor::pos().x() - (boundingRect().width() / 2),QCursor::pos().y() - (boundingRect().height() / 2));
    }
}


