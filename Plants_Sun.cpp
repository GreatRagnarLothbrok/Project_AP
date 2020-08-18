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

Plants_Sun::~Plants_Sun()
{
    delete destroyTimer;
}

void Plants_Sun::customStop()
{
    destroyTimer->stop();
}

void Plants_Sun::customStart()
{
    destroyTimer->start();
}

void Plants_Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
    score->increase();
    QMediaPlayer *player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/music/get_Sun.mp3"));
    player->play();
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
