#ifndef CACTUS_H
#define CACTUS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include "cactussprites.h"

class Cactus : public QObject, public QGraphicsItemGroup{
    Q_OBJECT
public:
    explicit Cactus(int posX, int posY, int currentSpeed, QObject *parent = nullptr);
    ~Cactus();

    void setSpeed(int newSpeed);
    int getPos();

private:
    int PIXEL_COUNT = 1;
    int LENGTH;
    int TYPE_CACTUS;
    int AUX_POS_X;

    int speed;
    QTimer *timer;

    int getRand();

private slots:
    void moveCactus();
};

#endif // CACTUS_H
