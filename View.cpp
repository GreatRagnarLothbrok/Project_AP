#include "View.h"
#include"Button_Close.h"
#include"Button_Resize.h"
#include "Card.h"
#include "Plants_Shooter.h"
#include "Zombi.h"
#include "Shovel.h"
#include <QCursor>
#include"Button_Pause.h"
#include<QDebug>
#include"Button_Reload.h"
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

    auto closeButton=new Button_Close(this);
    closeButton->setPos(1830,20);
    controller->scene->addItem(closeButton);
    //set ResizeButton
    auto resizeButton=new Button_Resize(this);
    resizeButton->setPos(1710,15);
    controller->scene->addItem(resizeButton);
    //set puaseButton
    auto pauseButton=new Button_Pause(this);
    pauseButton->setPos(1600,20);
    controller->scene->addItem(pauseButton);
    // add reload button
    Button_Reload* button_Reload=new Button_Reload(controller);
    button_Reload->setPos(1400,20);
    controller->scene->addItem(button_Reload);
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

