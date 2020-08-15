#include "Field.h"

Field::Field(int x, int y,int row,int column,QGraphicsRectItem * parent): posX(x), posY(y), row(row), column(column)
{
    rects = new Section*[row];
    for (int i = 0;i < row;++i) {
        rects[i] = new Section[column];
        for (int j = 0;j < column;++j) {
            rects[i][j].setPos(x,y);
            rects[i][j].setPen(QPen(QBrush(Qt::black),0));
            rects[i][j].setRow(i); rects[i][j].setColumn(j);
            rects[i][j].setParentItem(parent);
            x += 100;
        }
        x = posX;
        y += 124;
    }
}

void Field::addToScene(QGraphicsScene *scene)
{
    for (int i = 0;i < row;++i)
        for (int j = 0;j < column;++j)
            scene->addItem(rects[i] + j);
}
