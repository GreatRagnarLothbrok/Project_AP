#include "View.h"

View::View() : QGraphicsView(), controller(new Controller)
{
    setFixedSize(1920,1080);
    showFullScreen();
  //  setBackgroundBrush(QBrush(QImage(":/Background/BackGround/BackGround.jpg")));
    setVerticalScrollBarPolicy  (Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(controller->scene);
}

View::~View()
{
    delete controller;
}

