#include "Section.h"

#include <QPen>

Section::Section() : QGraphicsRectItem(0,0,90,110)
{

}

int Section::getColumn() const
{
    return column;
}

void Section::setColumn(int value)
{
    column = value;
}

void Section::setPlant(Plants *value)
{
    plant = value;
}

int Section::getRow() const
{
    return row;
}

void Section::setRow(int value)
{
    row = value;
}
