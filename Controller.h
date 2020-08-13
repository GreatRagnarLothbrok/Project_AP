#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QGraphicsScene>



class Controller
{
    friend class View;
public:
    Controller();

private:
    QGraphicsScene * scene;
};

#endif // CONTROLLER_H
