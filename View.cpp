#include "View.h"
#include"CloseButton.h"
View::View() : QGraphicsView(), controller(new Controller)
{
    //set Background
    setFixedSize(1920,1080);
    showFullScreen();
    setBackgroundBrush(QBrush(QImage(":/Background/BackGround/BackGround.jpg")));
    setVerticalScrollBarPolicy  (Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(controller->scene);
    //set CloseButton
    auto closeButton=new CloseButton(this);
    closeButton->setPos(1830,20);
    controller->scene->addItem(closeButton);
}

View::~View()
{
    delete controller;
}

