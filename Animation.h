#ifndef ANIMATION_H
#define ANIMATION_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QList>
#include <QTimer>
#include "Movable.h"
class Animation :public Movable, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Animation();
    ~Animation();
    void customStop();
    void customStart();
protected:
    void setPicsList(const QList<QPixmap>& pics);
    void startAnimate();
    void stopAnimate();
    QTimer * animationTimer;
    bool isStop;
private:
    QList<QPixmap> motionPictures;
    int pictureIndex;
    bool animationStarted = false;
public slots:
    void animate();
};

//

#endif // ANIMATION_H
