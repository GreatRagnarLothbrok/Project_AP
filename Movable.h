#ifndef MOVABLE_H
#define MOVABLE_H

#include <QObject>
#include <QTimer>
#include<QMediaPlayer>
class Movable :public QObject
{
    Q_OBJECT
public:
    explicit Movable(int);
    virtual ~ Movable();
    void start();
    void stop();
    virtual void customStop() {
    }
    virtual void customStart(){

    }


protected:
    QTimer * moveTimer;
    bool isStarted = false;
private slots:
    virtual void move() = 0;

};

#endif // MOVABLE_H
