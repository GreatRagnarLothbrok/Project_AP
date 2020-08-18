#ifndef PLANTS_SUNFLOWER_H
#define PLANTS_SUNFLOWER_H
#include "Plants.h"
#include"Plants_Sun.h"
#include "Show_Sun_Score.h"
class Plants_Sunflower:public Plants
{
    Q_OBJECT
public:
    Plants_Sunflower(Show_Sun_Score *score);
    ~Plants_Sunflower();
    void customFunctionality();
private:
    void customStart();
    void customStop();
    Show_Sun_Score *score;
    QTimer *addSunTimer;
private slots:
    void buildSun();
};

#endif // PLANTS_SUNFLOWER_H
