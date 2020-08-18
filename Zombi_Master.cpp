#include "Zombi_Master.h"
#include <sstream>
#include <iomanip>
using namespace  std;
Zombi_Master::Zombi_Master(int life,int row):Zombi(life,row)
{
    auto func = [](int x) {
        ostringstream stream;
        stream << fixed << setw(4) << setfill('0') << x;
        return QString::fromStdString(stream.str());
    };
    QList<QPixmap> qlist;
    for(int i=1;i<=240;i++){
        qlist.append(QPixmap(":/Zombi/WalkingHat/hatwalking_"+ func(240 - i) +"_Layer-"+ QString::number(i) +".png"));
    }
    setPicsList(qlist);
}
