#ifndef SEASON_H
#define SEASON_H
#include"Controller.h"

class Season:public QObject
{
    Q_OBJECT
public:

    Season(Controller *controller);
    void season1Start();
    void season2Start();
    void season3Start();

private:
    int sec;
    Controller *controller;
    void secIncrease(){sec++;}
    void clean();
    QMediaPlayer *player;
private slots:
    void season1Function();
    void season2Function();
    void season3Function();
};

#endif // SEASON_H
