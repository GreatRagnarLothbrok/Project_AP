#include "Show_LoseOrWin.h"
#include<QFont>
Show_LoseOrWin::Show_LoseOrWin():QGraphicsTextItem()
{
    setPlainText(text);
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",50));
    timer=new QTimer;
    timer->start(5000);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(destroy()));
}

Show_LoseOrWin::~Show_LoseOrWin()
{
    delete timer;
}

void Show_LoseOrWin::lose()
{
    text=QString("You lose ,but you can play again");
    setPlainText(text);
    setDefaultTextColor(Qt::red);
}

void Show_LoseOrWin::win()
{
    text=QString("Yow win , now go next season");
    setPlainText(text);
    setDefaultTextColor(Qt::green);

}

void Show_LoseOrWin::destroy()
{
    delete this;
}
