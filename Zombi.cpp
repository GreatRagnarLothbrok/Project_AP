#include "Zombi.h"
#include <sstream>
#include <iomanip>
using namespace std;
Zombi::Zombi():Animation()
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
for(int i=0;i<240;i++){
    qlist.append(QPixmap(":/Zombi/ZombieWalking/Walking_"+ func(240 - i) +"_Layer-"+ QString::number(i) +".png"));
}
setPicsList(qlist);
//Qtimer
auto livingTimer=new QTimer;
livingTimer->start(50);
//connect
QObject::connect(livingTimer,SIGNAL(timeout()),this,SLOT(checkLiving()));
}

void Zombi::damage()
{
    lifePoint--;
}

void Zombi::move()
{
    setPos(x()-0.4,y());
  //  setPos(x()-4,y());

}

void Zombi::checkLiving()
{
    if(lifePoint<=0){
        delete this;
        return;
    }
}
