#include "Zombi.h"
#include <sstream>
#include <iomanip>
#include<QMediaPlayer>
using namespace std;
Zombi::Zombi(int lifPoint,int row):Animation(),lifePoint{lifPoint},row{row}
{
    //set life point
    lifePoint=4;
//set pic
    auto func = [](int x) {
    ostringstream stream;
    stream << fixed << setw(4) << setfill('0') << x;
    return QString::fromStdString(stream.str());
};
    QList<QPixmap> qlist;
        for(int i=1;i<=240;i++){
    qlist.append(QPixmap(":/Zombi/ZombieWalking/Walking_"+ func(240 - i) +"_Layer-"+ QString::number(i) +".png"));
    }
    setPicsList(qlist);
//Qtimer
auto livingTimer=new QTimer;
livingTimer->start(50);
//connect
    QObject::connect(livingTimer,SIGNAL(timeout()),this,SLOT(checkLiving()));
    //det musoc
    QMediaPlayer* zombi=new QMediaPlayer;
    zombi->setMedia(QUrl("qrc:/music/music/zombi.mp3"));
    zombi->play();
}

void Zombi::damage()
{
    lifePoint--;
}

int Zombi::getRow() const
{
    return row;
}

void Zombi::setRow(int value)
{
    row = value;
}

void Zombi::move()
{
    setPos(x()-0.4,y());
    //  setPos(x()-4,y());

}

void Zombi::checkLiving()
{
    if(lifePoint<=0){
        QMediaPlayer *player=new QMediaPlayer;
        player->setMedia(QUrl("qrc:/music/music/zombi_die.mp3"));
        player->play();
        delete this;
        return;
    }
}
