#include "Section.h"

#include <QPen>

Section::Section() : QGraphicsRectItem(0,0,90,110), row(row), column(column)
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

int Section::getRow() const
{
    return row;
}

void Section::setRow(int value)
{
    row = value;
}
