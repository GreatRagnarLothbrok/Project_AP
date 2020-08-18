#ifndef SHOW_LOSEORWIN_H
#define SHOW_LOSEORWIN_H
#include<QGraphicsTextItem>
#include<QTimer>
#include <QObject>
class Show_LoseOrWin:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Show_LoseOrWin();
    ~Show_LoseOrWin();
    void lose();
    void win();
private :
    QString text;
    QTimer *timer;
private slots:
    void destroy();
};

#endif // SHOW_LOSEORWIN_H
