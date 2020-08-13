#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "Controller.h"


class View : public QGraphicsView
{
    Controller * controller;
public:
    View();
    ~View();
};

#endif // VIEW_H
