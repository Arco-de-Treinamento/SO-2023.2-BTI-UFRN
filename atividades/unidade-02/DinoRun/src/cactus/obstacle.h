#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QList>
#include <cstdlib>
#include <ctime>
#include "cactus.h"

class Obstacle : public QObject, public QGraphicsItemGroup{
    Q_OBJECT

public:
    explicit Obstacle(const int posCollider, const int currentSpeed, QObject *parent = nullptr);
    ~Obstacle();

    void speedUp();
    void setSpeed(int newSpeed);

private:
    int POS_Y = 150;
    int POS_X = 610;
    int POS_COLLIDER;
    int CONST_UPDATE_SPEED = 10;
    int INTERVAL_UNIT = 48;
    int MAX_UNIT_INTERVAL = 10;
    int MIN_UNIT_INTERVAL = 2;
    int SCREEN_SIZE = 600;

    int speed;

    QList<Cactus*> obstacles;

    int getRand();

signals:
    void isCollided();



private slots:
    void createCactus();
    void checkCollider();
};

#endif // OBSTACLE_H

