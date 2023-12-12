#ifndef DINO_H
#define DINO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include "dinosprites.h"

class Dino : public QObject, public QGraphicsItemGroup{
    Q_OBJECT

public:
    explicit Dino(int posX, int posY, int heightJump, int currentSpeed,  QObject *parent = nullptr);
    ~Dino();

    void speedUp();
    void setSpeed(int newSpeed);
    void dinoJump();
    int getPos();

private:
    int HEIGHT_JUMP;
    int PIXEL_COUNT = 1;
    int CONST_UPDATE_SPEED = 10;

    int speed;
    QTimer *timer;

    QGraphicsPixmapItem *dino;
    dinoSprites *sprites;

signals:
    void isJumped();
    void isWalking();

public slots:
    void dinoDead();

private slots:
    void dinoIdle();
    void dinoWalk();
};

#endif // DINO_H

