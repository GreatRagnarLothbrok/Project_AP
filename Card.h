#ifndef CARD_H
#define CARD_H
#include "Controller.h"

#include <QGraphicsPixmapItem>

class Card : public QGraphicsPixmapItem
{
public:
    Card(Controller * controller, char type = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    Controller * controller;
    char type;
    int price;
};

#endif // CARD_H
