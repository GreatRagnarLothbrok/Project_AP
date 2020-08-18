#include "Season.h"
#include<QMessageBox>
#include "Card.h"
void Season::start()
{
    clean();
    switch (level) {
    case 1:
        season1Start();
        break;
    case 2:
        season2Start();
        break;
    case 3:
        season3Start();
        break;
    default:
        break;
    }

}

Season::Season(Controller *controller):controller{controller}
{
    sec=0;
    player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/music/lose.mp3"));
    level=0;
}

void Season::season1Start()
{
    level=1;
    controller->score->restart();
    controller->field = new Field(700,300,1,8,controller->holder);
    controller->field->addToScene(controller->scene);
    controller->secTimer=new QTimer;
    controller->secTimer->start(1000);
    QObject::connect(controller->secTimer,SIGNAL(timeout()),this,SLOT(season1Function()));
}

void Season::season2Start()
{
    auto walnutCard = new Card(controller,2);
    walnutCard->setPos(450,0);
    controller->addItem(walnutCard);
    level=2;
    controller->score->restart();
    controller->field = new Field(700,300,2,8,controller->holder);
    controller->field->addToScene(controller->scene);
    controller->secTimer=new QTimer;
    controller->secTimer->start(1000);
    QObject::connect(controller->secTimer,SIGNAL(timeout()),this,SLOT(season2Function()));
}

void Season::season3Start()
{
    auto cherryCard = new Card(controller,3);
    cherryCard->setPos(600,0);
   controller->scene->addItem(cherryCard);

    level=3;
    controller->score->restart();
    controller->field = new Field(700,300,3,8,controller->holder);
    controller->field->addToScene(controller->scene);
    controller->secTimer=new QTimer;
    controller->secTimer->start(1000);
    QObject::connect(controller->secTimer,SIGNAL(timeout()),this,SLOT(season3Function()));
}

void Season::clean()
{
    QList<QGraphicsItem*> list=controller->scene->items();
    for(auto item:list){
        auto it=dynamic_cast<Animation*>(item);
        if(it)
        delete it;
    }
}

void Season::season1Function()
{
    secIncrease();
    if(sec>=50&&sec<=60){
        if(sec==50)
            controller->addZombi(1,true,4);
        else if(sec==54)
            controller->addZombi(1,true,4);
        else if(sec==57)
            controller->addZombi(1,true,4);
        else if(sec==59)
            controller->addZombi(1,true,4);
        else if(sec==60)
            controller->addZombi(1,true,4);

    }
    else if(sec>60){
        int num=0;
        QList<QGraphicsItem*> items = controller->scene->items();
        for(auto &item:items){
            auto zombi=dynamic_cast<Zombi*>(item);
            if(zombi){
                if(zombi->x()<=0){
                    //lose empty
                    player->play();
                    clean();
                    show_LoseOrWin=new Show_LoseOrWin;
                    show_LoseOrWin->lose();
                    show_LoseOrWin->setPos(900,500);
                    controller->scene->addItem(show_LoseOrWin);
                    QObject::disconnect(controller->secTimer,SIGNAL(timeout()),this,SLOT(season1Function()));
                  break;
                }
                num++;

            }

        }
        if(num==0)
        {
            // win empty
         QObject::disconnect(controller->secTimer,SIGNAL(timeout()),this,SLOT(season1Function()));
         sec=0;
         clean();
         show_LoseOrWin=new Show_LoseOrWin;
         show_LoseOrWin->win();
         show_LoseOrWin->setPos(900,500);
         controller->scene->addItem(show_LoseOrWin);
         season2Start();


        }

    }
}

void Season::season2Function()
{

    secIncrease();
    if(sec>=45&&sec<=52){
        if(sec==45)
            controller->addZombi(1,true,4);
        else if(sec==48){
            controller->addZombi(1,true,4);
            controller->addZombi(2,true,4);
        }
        else if(sec==49)
            controller->addZombi(2,true,4);
        else if(sec==50){
            controller->addZombi(1,true,4);
            controller->addZombi(2,true,4);
        }
        else if(sec==51){
            controller->addZombi(1,true,4);
            controller->addZombi(2,true,4);
        }
        else if(sec==52){
            controller->addZombi(1,true,4);
            controller->addZombi(2,true,4);
        }


    }
    else if(sec>52){
        int num=0;
        QList<QGraphicsItem*> items = controller->scene->items();
        for(auto &item:items){
            auto zombi=dynamic_cast<Zombi*>(item);
            if(zombi){
                if(zombi->x()<=0){
                    //lose empty
                    player->play();
                    show_LoseOrWin=new Show_LoseOrWin;
                    show_LoseOrWin->lose();
                    show_LoseOrWin->setPos(900,500);
                    controller->scene->addItem(show_LoseOrWin);
                    QObject::disconnect(controller->secTimer,SIGNAL(timeout()),this,SLOT(season2Function()));

                    clean();

                  break;
                }
                num++;

            }

        }
        if(num==0)
        {
            // win empty
         QObject::disconnect(controller->secTimer,SIGNAL(timeout()),this,SLOT(season2Function()));
         sec=0;
         show_LoseOrWin=new Show_LoseOrWin;
         show_LoseOrWin->win();
         show_LoseOrWin->setPos(900,500);
         controller->scene->addItem(show_LoseOrWin);
         season3Start();
         clean();

        }

    }
}
void Season::season3Function()
{
    secIncrease();
    if(sec>=40&&sec<=53){
        if(sec==40)
            controller->addZombi(1,true,4);
        else if(sec==44)
            controller->addZombi(2,true,4);
        else if(sec==46){
            controller->addZombi(3,true,4);

        }
        else if(sec==47){
            controller->addZombi(1,true,4);
            controller->addZombi(2,true,4);
        }
        else if(sec==48){
            controller->addZombi(3,true,4);
            controller->addZombi(1,true,4);
        }
        else if(sec==50){
            controller->addZombi(1,true,4);
            controller->addZombi(2,true,4);
            controller->addZombi(3,true,4);

        }
        else if(sec==51){
            controller->addZombi(2,true,12);
            controller->addZombi(3,true,12);
        }
        else if(sec==53){
            controller->addZombi(1,false,4);
            controller->addZombi(2,false,4);
            controller->addZombi(3,false,4);

        }


    }
    else if(sec>53){
        int num=0;
        QList<QGraphicsItem*> items = controller->scene->items();
        for(auto &item:items){
            auto zombi=dynamic_cast<Zombi*>(item);
            if(zombi){
                if(zombi->x()<=0){
                    player->play();
                    show_LoseOrWin=new Show_LoseOrWin;
                    show_LoseOrWin->lose();
                    show_LoseOrWin->setPos(900,500);
                    controller->scene->addItem(show_LoseOrWin);
                    QObject::disconnect(controller->secTimer,SIGNAL(timeout()),this,SLOT(season3Function()));
                    clean();
                  break;
                }
                num++;

            }

        }
        if(num==0)
        {
            // win empty
            show_LoseOrWin=new Show_LoseOrWin;
            show_LoseOrWin->win();
            show_LoseOrWin->setPos(900,500);
            controller->scene->addItem(show_LoseOrWin);
         QObject::disconnect(controller->secTimer,SIGNAL(timeout()),this,SLOT(season3Function()));
         clean();

        }

    }
}
