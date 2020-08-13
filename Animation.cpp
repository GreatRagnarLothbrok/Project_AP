#include "Animation.h"
#include <QObject>
#include <QDebug>
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
    if(isAnimated)
        animationTimer->stop();
    motionPictures.clear();
    for (const auto & el : pics) {
        motionPictures.append(el);
    }
    pictureIndex = 0;
    if(isAnimated)
        animationTimer->start();
}

void Animation::startAnimate()
{
    if(!isAnimated) {
        animationTimer->start(50);
        QObject::connect(animationTimer,SIGNAL(timeout()),this,SLOT(animate()));
        isAnimated = true;
    }
}

void Animation::stopAnimate()
{
    if(isAnimated) {
        animationTimer->stop();
        QObject::disconnect(animationTimer,SIGNAL(timeout()),this,SLOT(animate()));
        isAnimated = false;
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
