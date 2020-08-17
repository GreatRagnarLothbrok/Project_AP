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

    int getRow() const;
    void setRow(int value);

    int getColumn() const;
    void setColumn(int value);
    virtual void customFunctionality() {}
private:
    int price;
    bool isPlaced = false;
    int row;
    int column;
protected slots:
    virtual void checkColliding();
private slots:
    void move();
public slots:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
};

#endif // PLANTS_H
