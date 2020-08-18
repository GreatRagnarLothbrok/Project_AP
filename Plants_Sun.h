#ifndef PLATNS_SUN_H
#define PLATNS_SUN_H
#include <Animation.h>
#include <QGraphicsSceneMouseEvent>
#include<QGraphicsScene>
#include"Show_Sun_Score.h"
class Plants_Sun:public Animation
{
    Q_OBJECT
public:
    Plants_Sun(Show_Sun_Score* score,bool check);
    ~Plants_Sun();
private:
    Show_Sun_Score *score;
    bool checkMove;
    QTimer *destroyTimer;
    void customStop();
    void customStart();
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void move();
    void destroy();
};

#endif // PLATNS_SUN_H
