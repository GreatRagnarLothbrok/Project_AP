#ifndef RECT_H
#define RECT_H

#include <QGraphicsRectItem>


class Section : public QGraphicsRectItem
{
public:
    Section();
    int getRow() const;
    void setRow(int value);
    int getColumn() const;
    void setColumn(int value);
private:
    int row;
    int column;
};

#endif // RECT_H
