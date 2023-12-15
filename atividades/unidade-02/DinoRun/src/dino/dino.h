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
    int getPos();

private:
    int HEIGHT_JUMP;
    int SPEED_JUMP = 160;
    int PIXEL_COUNT = 1;
    int CONST_UPDATE_SPEED = 10;

    int speed;
    QTimer *timer;
    QTimer *jumpTimer;

    QGraphicsPixmapItem *dino;
    dinoSprites *sprites;

signals:
    void isJump(bool value);
    void jumpFinished();

public slots:
    void dinoDead();
    void dinoJump();

private slots:
    void dinoIdle();
    void dinoWalk();
    void jumpUp();
    void jumpDown();
};

#endif // DINO_H

