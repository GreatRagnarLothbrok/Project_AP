#include "Movable.h"

Movable::Movable(int msec) : QObject()
{
    moveTimer = new QTimer();
    moveTimer->setInterval(msec);
}

Movable::~Movable()
{
    delete moveTimer;
}

void Movable::start()
{
    if (!isStarted) {
        moveTimer->start(moveTimer->interval());
        QObject::connect(moveTimer,SIGNAL(timeout()),this,SLOT(move()));
        isStarted = true;
    }
}

void Movable::stop()
{
    if (isStarted) {
        moveTimer->stop();
        QObject::disconnect(moveTimer,SIGNAL(timeout()),this,SLOT(move()));
        customStop();
        isStarted = false;
    }
}

