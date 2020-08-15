#ifndef SHOVEL_H
#define SHOVEL_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <Controller.h>
#include <QTimer>

class Shovel : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Shovel(Controller * controller, QGraphicsRectItem * parent);
    ~Shovel();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
private:
    Controller * controller;
    QTimer * timer;
    bool picked = false;
    QPointF defaultPoint;
public slots:
    void setPosition();

};

#endif // SHOVEL_H
