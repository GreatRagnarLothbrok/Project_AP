#include "Show_Sun_Score.h"
#include <QFont>
Show_Sun_Score::Show_Sun_Score():QGraphicsTextItem()
{
    score=0;
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",50));
}

void Show_Sun_Score::increase()
{
    score+=25;
    setPlainText(QString::number(score));

}

int Show_Sun_Score::getPoint()
{
    return score;
}

void Show_Sun_Score::decrease(int price)
{
    score-=price;
    setPlainText(QString::number(score));
}

void Show_Sun_Score::restart()
{
    score=0;
    setPlainText(QString::number(score));
}
