#include "Button_Pause.h"
#include<QDebug>
Button_Pause::Button_Pause(View *view):QGraphicsPixmapItem(),scenePause(new QGraphicsScene(0,0,1920,1080))
{
    this->view=view;
//set pix
    setPixmap(QPixmap(":/Background/BackGround/puase.png"));


}

void Button_Pause::mousePressEvent(QGraphicsSceneMouseEvent *event)
{if(event->button()==Qt::LeftButton){
    if(!view->controller->checkIsStop())
       {

        view->controller->stop();
        setPos(900,500);
        scenePause->addItem(this);
        view->setScene(scenePause);
        view->setBackgroundBrush(QBrush(QImage(":/Background/BackGround/stop.png")));

    }
    else{
        view->controller->start();
        setPos(1600,20);
        view->controller->scene->addItem(this);
        view->setScene(view->controller->scene);
        view->setBackgroundBrush(QBrush(QImage(":/Background/BackGround/BackGround.jpg")));


    }
    }
}
