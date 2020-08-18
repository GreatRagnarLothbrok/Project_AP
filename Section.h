#ifndef RECT_H
#define RECT_H

#include "Plants.h"
#include <QGraphicsRectItem>
#include <QObject>

class Section : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Section();
    int getRow() const;
    void setRow(int value);
    int getColumn() const;
    void setColumn(int value);
    bool isEmpty() {return plant == nullptr;}
    void setPlant(Plants *value);
    void destroy();
private:
    int row;
    int column;
    Plants * plant = nullptr;
public slots:
    void removePlant();
};

#endif // RECT_H
