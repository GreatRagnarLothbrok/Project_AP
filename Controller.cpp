#include "Controller.h"

Controller::Controller() : scene(new QGraphicsScene(0,0,1920,1080))
{
    holder = new QGraphicsRectItem(0,0,scene->width(),scene->height());
}

Controller::~Controller()
{
    delete scene;
    delete holder;
}
