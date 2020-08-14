#ifndef FIELD_H
#define FIELD_H

#include "Section.h"
#include <QGraphicsScene>
class Field
{
public:
    Field(int x, int y, int row, int column,QGraphicsRectItem * parent);
    void addToScene(QGraphicsScene * scene);
private:
    Section** rects;
    int posX;
    int posY;
    int row;
    int column;
};

#endif // FIELD_H
