#ifndef MOVABLE_H
#define MOVABLE_H

#include <QObject>
#include <QTimer>

class Movable :public QObject
{
    Q_OBJECT
public:
    explicit Movable(int);
    virtual ~ Movable();
    void start();
    void stop();
private:
    virtual void customStop() {

    }
protected:
    QTimer * moveTimer;
    bool isStarted = false;
private slots:
    virtual void move() = 0;

};

#endif // MOVABLE_H
