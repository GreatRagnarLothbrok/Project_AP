#ifndef PLANTS_H
#define PLANTS_H
#include"Animation.h"
class Plants : public Animation
{
    Q_OBJECT
public:
    Plants(int price);
    int getPrice();
    void setPosition();
    void setPlaced(){isPlaced = true;}
private:
    int price;
    bool isPlaced = false;
protected slots:
    virtual void checkColliding();
private slots:
    void move();
public slots:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
};

#endif // PLANTS_H
