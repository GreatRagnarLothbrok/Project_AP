#ifndef PLANTS_RANDOMSUN_H
#define PLANTS_RANDOMSUN_H
#include"Show_Sun_Score.h"
#include"Plants_Sun.h"
#include"Movable.h"
#include <QObject>
class Plants_RandomSun:public QObject
{
Q_OBJECT
public:
    Plants_RandomSun(Show_Sun_Score *score,QGraphicsScene *scene);
    ~Plants_RandomSun();
    void customStop();
    void customStart();
private:
    QList<Movable*> sunList;
    QTimer *timerSun;
    Show_Sun_Score *score;
    QGraphicsScene *scene;
private slots:
    void buildSun();

};

#endif // PLANTS_RANDOMSUN_H
