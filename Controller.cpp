#include "Controller.h"

Controller::Controller() : scene(new QGraphicsScene(0,0,1920,1080))
{

}

Controller::~Controller()
{
    delete scene;
}
