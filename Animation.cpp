#include "Animation.h"
#include <QObject>
Animation::Animation():
    Movable(10), QGraphicsPixmapItem(), animationTimer(new QTimer)
{
    isStop=false;
    pictureIndex = 0;
    if (!motionPictures.empty())
        setPixmap(motionPictures[pictureIndex]);
}

Animation::~Animation()
{
    delete animationTimer;
}

void Animation::customStop()
{
    stopAnimate();
}

void Animation::customStart()
{
    startAnimate();
}



void Animation::setPicsList(const QList<QPixmap> &pics)
{
    stopAnimate();
    motionPictures.clear();
    for (const auto & el : pics) {
        motionPictures.append(el);
    }
    pictureIndex = 0;
    startAnimate();
}

void Animation::startAnimate()
{
    if(!animationStarted) {
        animationTimer->start(33);
        QObject::connect(animationTimer,SIGNAL(timeout()),this,SLOT(animate()));
        animationStarted = true;
    }
}

void Animation::stopAnimate()
{
    if(animationStarted) {
        animationTimer->stop();
        QObject::disconnect(animationTimer,SIGNAL(timeout()),this,SLOT(animate()));
        animationStarted = false;
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
