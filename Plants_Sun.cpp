#include "Plants_Sun.h"
Plants_Sun::Plants_Sun(Show_Sun_Score *score,bool check):Animation(),checkMove{check}
{
    this->score=score;
    //set pic
    setPixmap(QPixmap(":/Plants/Plants/sun.png"));
    destroyTimer=new QTimer;
    destroyTimer->start(2000);
    QObject::connect(destroyTimer,SIGNAL(timeout()),this,SLOT(destroy()));
}

void Plants_Sun::customStop()
{
    QObject::disconnect(destroyTimer,SIGNAL(timeout()),this,SLOT(destroy()));
}

void Plants_Sun::customStart()
{
    QObject::connect(destroyTimer,SIGNAL(timeout()),this,SLOT(destroy()));
}

void Plants_Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
    score->increase();
    delete this;
        return;
    }
}

void Plants_Sun::move()
{
    if(checkMove){
    setPos(x(),y()+2);

    }
}

void Plants_Sun::destroy()
{
    delete this;
}
