#ifndef DINO_H
#define DINO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include "dinosprites.h"

class Dino : public QObject, public QGraphicsItemGroup{
    Q_OBJECT
public:
    explicit Dino(int currentSpeed,  QObject *parent = nullptr);
    ~Dino();

    void speedUp();
    void setSpeed(int newSpeed);
    int getPos();

private:
    int POS_X = 48;
    int POS_Y = 160;
    int PIXEL_COUNT = 1;
    int CONST_UPDATE_SPEED = 10;

    int speed;
    QTimer *timer;

    QGraphicsPixmapItem *dino;
    dinoSprites *sprites;

signals:
    void isJumped();

private slots:
    void dinoIdle();
    void dinoWalk();
    void dinoJump();
    void dinoDead();
};

#endif // DINO_H

