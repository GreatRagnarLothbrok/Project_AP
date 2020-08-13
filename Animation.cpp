#include "Animation.h"
#include <QObject>
Animation::Animation():
    Movable(10), QGraphicsPixmapItem(), animationTimer(new QTimer)
{

    pictureIndex = 0;
    if (!motionPictures.empty())
        setPixmap(motionPictures[pictureIndex]);
}

Animation::~Animation()
{
    delete animationTimer;
}



void Animation::setPicsList(const QList<QPixmap> &pics)
{
    animationTimer->stop();
    motionPictures.clear();
    for (const auto & el : pics) {
        motionPictures.append(el);
    }
    pictureIndex = 0;
    animationTimer->start();
}

void Animation::startAnimate()
{
    if(!animationTimer->isActive()) {
        animationTimer->start(50);
        QObject::connect(animationTimer,SIGNAL(timeout()),this,SLOT(animate()));
    }
}

void Animation::stopAnimate()
{
    if(animationTimer->isActive()) {
        animationTimer->stop();
        QObject::disconnect(animationTimer,SIGNAL(timeout()),this,SLOT(animate()));
    }
}


void Animation::animate() {
    if (pictureIndex != motionPictures.size()) {
        setPixmap(motionPictures[pictureIndex]);
        ++pictureIndex;
    }
    else {
        pictureIndex = 0;
    }
}
