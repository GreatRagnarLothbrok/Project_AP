#include "Show_Sun_Score.h"
#include <QFont>
Show_Sun_Score::Show_Sun_Score():QGraphicsTextItem()
{
score=100;
setPlainText(QString::number(score));
setDefaultTextColor(Qt::yellow);
setFont(QFont("times",50));
}

void Show_Sun_Score::getSun()
{
    score+=25;
    setPlainText(QString::number(score));

}
