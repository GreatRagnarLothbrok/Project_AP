#ifndef PLANTS_H
#define PLANTS_H
#include"Animation.h"
#include"Show_Sun_Score.h"
class Plants : public Animation
{
    Q_OBJECT
public:
    Plants(int price);
    ~Plants();
    int getPrice();
    void setPosition(Show_Sun_Score *score);
    void setPlaced(){isPlaced = true;}

    int getRow() const;
    void setRow(int value);

    int getColumn() const;
    void setColumn(int value);
    virtual void customFunctionality() {}
protected:
    bool isPlaced = false;

private:
    QTimer * livingTimer;
    int price;
    //bool isPlaced = false;
    int row;
    int column;
     Show_Sun_Score* score;
protected slots:
    virtual void checkColliding();
private slots:
    void move();
public slots:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
signals:
    void plantRemoved();
};

#endif // PLANTS_H
