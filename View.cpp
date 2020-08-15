#include "View.h"
#include"CloseButton.h"
#include"ResizeButton.h"
#include "Card.h"
#include "Plants_Shooter.h"
#include "Zombi.h"
#include "Shovel.h"
#include <QCursor>


View::View() : QGraphicsView(), controller(new Controller)
{
    //set Background
    setMouseTracking(true);
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
    //set ResizeButton
    auto resizeButton=new ResizeButton(this);
    resizeButton->setPos(1710,15);
    controller->scene->addItem(resizeButton);
}

View::~View()
{
    delete controller;
}

void View::mouseMoveEvent(QMouseEvent *event)
{
    if (controller->selectedPlant != nullptr) {
        controller->selectedPlant->setPos(QCursor::pos().x() - (controller->selectedPlant->boundingRect().width ()/2),
                                          QCursor::pos().y() - (controller->selectedPlant->boundingRect().height()/2));
    }
    QGraphicsView::mouseMoveEvent(event);
}

