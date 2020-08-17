#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "Controller.h"


class View : public QGraphicsView
{
public:
    Controller * controller;

    View();
    ~View();
    void mouseMoveEvent(QMouseEvent *event);

};

#endif // VIEW_H
