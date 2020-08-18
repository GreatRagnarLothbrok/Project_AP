#ifndef SHOW_SUN_SCORE_H
#define SHOW_SUN_SCORE_H
#include<QGraphicsTextItem>

class Show_Sun_Score:public QGraphicsTextItem
{
public:
    Show_Sun_Score();
    void increase();
    int getPoint();
    void decrease(int price);
    void restart();
private:
    int score;
};

#endif // SHOW_SUN_SCORE_H
