#ifndef RECT_H
#define RECT_H

#include "Plants.h"
#include <QGraphicsRectItem>


class Section : public QGraphicsRectItem
{
public:
    Section();
    int getRow() const;
    void setRow(int value);
    int getColumn() const;
    void setColumn(int value);
    bool isEmpty() {return plant == nullptr;}
    void setPlant(Plants *value);
private:
    int row;
    int column;
    Plants * plant = nullptr;
};

#endif // RECT_H
